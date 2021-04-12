My favorite challenge (would be if was not broken, which I will explain later), it contained a mail with few malware attachments. Since this kind of malware analysis is something I do every day, I was quite excited for this. Especially since there were some quite high-score flags in this.

In total there were (or should be) 5 flags to find. One in HTML attachment and 2 in each Word Document. Samples were real-world "castrated" samples from both GandCrab and IcedID/BokBot.

![attachments](https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/ritsec/writeup/beginner/attachments.PNG)

1. First flag was fairly simple one a URL encoded html attachment with a base64 encoded flag:

![html](https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/ritsec/writeup/beginner/html_attachment.PNG)

![flag](https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/ritsec/writeup/beginner/flag.PNG)

2. Second flag was in GandCrab document macro and was also fairly easy, visible right after using olevba or simply opening macro in the editor:

![GCflag](https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/ritsec/writeup/gandcab/macro.PNG)

3. Third flag and the first in IceID document was also fairly simple. In fact it was also in macro only ROT-13 encoded. If we guessed the ROT-13 part we could just use olevba + cyberchef for this. I was honestly expecting some a little bit harder ofuscation, and I also wanted to find a second flag as well (there should be 2 flags in this document), I opted to run and debug macro. From my experience always it's easier to let malware run and deobfuscate/decypt itself insted of staticly analysing it. Because macro was heavily castrated it initially didn't want to run

![macro](https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/ritsec/writeup/iced/broken_macro.PNG)

But few tweaks later I managed to run it and correctly decrypt the flag:

![IDflag1](https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/ritsec/writeup/iced/flag.PNG)

At this point I started banging my head against a wall. I analyzed every line of the macro in IcedID, I found hidden Form that contained hidden data but it only had a rot-13 encoded `<!DOCTYPE html>` so nothing interesting. I checked things like VBA stomping, all metadata and attributes, went through almost every line in XML and oledump but only found followint powershell hidden in the image in GandCrab:

![powershell](https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/ritsec/writeup/gandcab/powerhsell.PNG)

At some point I become sure that challenges are "castrated" a little too much and are in fact unsolvable, especially since both had 0 solves. I talked with mods few times but every time they assured me it's solvable. In the end, few hours before the end of the challenge they actually admitted it's unsolvable - removed GandCrab second challenge and updated fixed challenge for IcedID/BokBot 2:

Fixed challenge in fact had a little bit more data hidden in a previously discovered UserForm textfield. Thsi time it was an entore ROT-13 encrypted HTML document that got decrypted by the macro code, dropped to disk and ran by copied mshta.exe (at least in original, malicious version of this document). We could decode this html ourselves or just let malware drop it to the disc for us with a slight modification:

![drop_html](https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/ritsec/writeup/iced/iceid_fixed_file.PNG)

Decoded HTML document contained a hex-encoded javascript code that was later decoded and ran by other javascript.

![decoded_html](https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/ritsec/writeup/iced/iceid_fixed_html.PNG)

It also passed as a parameter to this code a following string: `261636e23757f6963696c616d6f2472756078756e2d7e603124704365357662603b7345435459425f2f2a307878786` in fact if we reversed it and decoded it gave us a flag. But if we didn't want to guess encoding mechanizm (it could be xored on obfuscated in any other way) we can alway relate on malware to do the job for us. Unfortunately the javascript seemed to be also "castrated" a little bit by the challenge authors but with few modifications we could make it run and output the flag for us:

![javscript](https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/ritsec/writeup/iced/iceid_fixed_js.PNG)

And after running this file with cscript.exe the final result was:

![IDflag2](https://github.com/lasq88/CTF/blob/main/ritsec2021/forensics/ritsec/writeup/iced/iceid_fixed_flag.PNG)

