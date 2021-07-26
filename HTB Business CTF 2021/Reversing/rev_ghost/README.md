**Disclaimer**: I didn't finish this challenge during the CTF, only because of the typo in the code, but I did around 99% of the expected work, and after finding the typo the next day, I was able to solve the challenge.

**Description**: Our organization was affected by a ransomware due to employee negligence. Can you help us recover our files? Note: Make sure you're analyzing this in an isolated environment.
**Stars**: 3/4
**Downloadable**: windows11update.exe - 64-bit Golang binary, capture.pcapng - pcap with encrypted network traffic, your_documents - zip archive
**Goal**: To reverse encryption algorithm and decrypt the pdf file with the flag

# Solution:

Challenge consisted of 3 files:
 * 64-bit PE executable, that after initial analysis was a compiled GoLang binary
 * pcap file with what looked like encrypted traffic
 * "your_documents" file without an extension, that after brief analysis turned out to be a zip archive containing file Confidential.pdf.ghost, a potentially encrypted pdf containing the flag

## Part 1 - decrypting the traffic
The initial strategy was to look at the binary, looking for a key to decrypt traffic from the pcap. As said before, binary turned out to be a compiled GoLang. I wasn't experienced with reversing golang binaries, so initially I spent a lot of time learning about golang (I will link few useful sources on the bottom). There were few issues I was dealing with:
Golang compiler is passing all functions' arguments on the stack, while Ghidra insists since it is x64 binary it must follow an x64 callign convention. Due to this, arguments are all messed up in Ghidra both in disassembly and decompiler. I couldn't find easy and fast way to solve it during CTF so I was just making notes, what functions have what arguments.
Golang has a huge concurrency focus, related to so called goroutines. Not sure if this is directly related, but my x64dbg loved to switch context, even during single-stepping, which was quite annoying. In the end, I learned to not use single-stepping and just put a lot of breakpoint whenever I saw an interesting code.
On the bright side, Ghidra did well on recovering all function names and strings, which I read was an issue for some disassemblers in the past. So this at least made analyzis a little bit more convinent.
Eventually, by running disassembler and debugger concurrently, I started to make some sense out of the binary. Initially the binary used net.Dial() function to connect to nonexistent domain wind0ws11.com on port 443, then it used crypto/cipher library to encrypt communcation with AES encryption in GCM mode. If you set the breakpoint at correct address, you can easily see AES key being passed to the function

![AES key in memory](img\network_decryption_key.PNG)

Having the key, we need to understand a network alorithm to fully decrypt the text. If we look into the pcap in the raw form in Wireshark (follow tcp stream -> show data as: raw) we will see that first packet is usually 4 bytes and then a longer string follows. If you areperienced with raw socket programming, you will know that for raw socket transission, it's always easy to first send information about the amount of data that needs is to be expected next, before sending actual data. This is exactly what happens here. So we have 4 bytes that are not encrypted and decypher to a number n, followed by an encrypteded string of data of lenght of exactly n bytes.
With this information it's just a matter of writing a simple decryptor in our language of choice. Usually I chose the same language that was used in the original file, just to avoid some pottential issues related to cryptography implemantation. So I wrote one decryptor in go, but later I needed a decryption function in python, so I wrote that too. 
You can find the correct script in the decrypt.py file.

![Decrypted data](img\decrypted_data.PNG)

In the decrypted network traffic, we will find an interesting communication with the C2, but most importantly a long binary string, that decrypts to a .NET executable. Additionaly we will find some recon commands, some guid string sent from client to server (this will be important later) and a ransom note.
Entire decrypted traffic can be found in decrypted.txt file.
If we look more closely, we can also see that each command is preceded by a 2 letter message like "rc" or "la". These are C2 server commands that will tell the binary what function to execute next with parameters that follow after the command. If we will look closely at the diassembly, we will find a function that is responsible for parsing a reply from C2 and executing a particular action. It looks like this:

![C2 command parsing routine](img\C2Comms.PNG)

What I did during the CTF to help me understand better the flow of the code and the functions is writing a tiny TCP server in python to serve as C2. With this I could debug specific functions and see what they are doing. You can find the script in c2_emulator.py file.

![C2 emulator](img\c2_emulator.png)

Now we can tell from the decrypted pcap what exactly happended during the attack. There were some reconnasiance commands run at first, then some data was written to a RegistryKey "Service" (take note, this is important) and later a .NET binary was sent and executed and after that client some guid (stored also in registry key) to the server, and in the end a ransom note was written to the desktop.

## Part 2 - analyzing .NET binary and getting decryption key

So now it is a good time to look at the .NET binary. It is not very obfuscated but function names are random and most of the strings are encrypted. After some deobfuscation and analysis, this is how the main function looks like:
![.NET Binary main](img\dotnetmain.png)
Unfortunately we soon realize, to decrypt any strings, we need to know what argument is passed to the program from the main Go binary (line 22), as it is later used in string decryption function:
![String Decryption Function](img\decryptstring.png)
To do that we need to go back to the Golang binary. If you remember the strange string passed from C2 to the client to be saved in the registry key named "service" it is used as part of this decryption key, but it is later xored with some hardcoded hexstring in the binary. But I learned this only after CTF, during CTF I jsut ran my emulator, asked Go malwared to run a binary, and grabbed an argument from the memory. With this I could already run our .NET ransomware encryptor. To debug it, we also need to nop out a call to Process.EnterDebugMode() - otherwise it will crash our debugger.
So far, so good, now we can run our binary, grab a decryption key and get a flag, right? Not so fast, remember this strange guid sent by client to C2? It is being used as a seed to derive a correct encryption key. It is being generated at line 25 of .NET binary, and then saved to registry in line 26.

```cp
umj3VnYEF8fY3bkw.RegistryKeyValue = Guid.NewGuid().ToString();
         umj3VnYEF8fY3bkw.RegistrySetValueW(umj3VnYEF8fY3bkw.RegistryKeyValue);
```

So to get a correct encryption key we need to set a breakpoint at the beginning of DecryptString function, and change in memory a randomly generated GUID for the one we got from the network traffic.
![Change GUID in memory](img\guid_memory.png)
With this done we can finally get a correct decryption key.
![Ransomware Decryption Key](img\file_decryption_key.png)

## Part 3 - Decrypting the file
So now, there is nothing easier than to just write a simple decryptor in .NET and then decrypt the file and get our flag, right? Well in theory, yes. In practice I wasted 3 hours with different code samples from the internet, trying to make this decryptor work. I always ran into the `Padding is invalid and cannot be removed.` exception, which meant something is wrong either with the encrypted file or with my key, or with a decryption code. After many tries to unsuccessfully debug my code, I've ruan out of time, and the CTF finished. Only the next day, after looking at someone else working code, I realzied my mistake. When calling rfc2898DeriveBytes I set number of rounds to 5000 instead of 50000 as it was originally in the encryptor. This small mistake costed me few hours, a lot of frustration and unsolved challenge. Fortuantely id didn't cost our team a podium position, as even with it we would finished on 4th place.

```cp
Rfc2898DeriveBytes rfc2898DeriveBytes = new Rfc2898DeriveBytes(bytes, array, 50000);
```
One more remark regarding decryption code: Encryptor writes a salt into the first 32 bytes of the encrypted file. You need to read this value first and then decrypt reminder of the file. Other than that it is pretty straightforward, and many examples can be found in the internet. Just watch out for typos.
The working decryption code can be found in file_decryptor.cs file.

After launching it, we can finally enjoy our flag!

## Conclusion
This was a really well thought-through challenge, and kudos to the author. I appriciate a depth to this challenge, from analyzing GO biary, via decrypting traffic to analyzin a .NET binary and writing a decryptor. It all required a really broad set of reversing skills. I also liked an attention to little details like decryption key being derived from earlier saved registry keys etc. This put more challenge into this task, because once I thought I got this, there was always another issue to tackle.
Overall this was one of the best CTF challenges I've done, and even though I didn't finish it, I still loved it. Initially I was frustrated that small typo stopped me from finishing it in time, but while writting this write-up, I realized how much I've accomplishjed and how much I've learned during this challange. It gave me a kind of closure to this.

## Usefull links
https://cujo.com/reverse-engineering-go-binaries-with-ghidra/
https://pulsesecurity.co.nz/articles/portable-pivoting
https://medium.com/@nishanmaharjan17/reversing-golang-binaries-part-3-how-to-run-a-golang-ransomware-613f5369cbaa
https://developpaper.com/understanding-golang-multiple-assignments/
https://blog.malwarebytes.com/threat-analysis/2019/01/analyzing-new-stealer-written-golang/
https://golang.org/doc/asm
https://www.pnfsoftware.com/blog/analyzing-golang-executables/
https://golang.org/doc/gdb