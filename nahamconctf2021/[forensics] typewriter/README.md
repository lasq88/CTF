Typical memory forensics challenge. Just after loading image with volatility and doing pslist we saw wordwin.exe process that was quite obvious target.

Below volatility commands to extract `CONFIDENTIAL DOCUMENT.docx` that was opened by word process.

```
C:\Users\MalfindLabs\Desktop\ctf\typewriter>
C:\Users\MalfindLabs\Desktop\ctf\typewriter>volatility -f image.bin --profile=Win7SP1x86_23418 handles -p 2760 > handles
Volatility Foundation Volatility Framework 2.6

0x85d665b8   2760      0x174   0x12019f File             \Device\HarddiskVolume1\Users\IEUser\Desktop\CONFIDENTIAL DOCUMENT.docx

C:\Users\MalfindLabs\Desktop\ctf\typewriter>volatility -f image.bin --profile=Win7SP1x86_23418 filescan > filescan.txt
Volatility Foundation Volatility Framework 2.6

0x000000007e841f80      8      0 RW-r-- \Device\HarddiskVolume1\Users\IEUser\Desktop\CONFIDENTIAL DOCUMENT.docx

C:\Users\MalfindLabs\Desktop\ctf\typewriter>volatility -f image.bin --profile=Win7SP1x86_23418 dumpfiles -Q 0x000000007e841f80 -D dump/
Volatility Foundation Volatility Framework 2.6
DataSectionObject 0x7e841f80   None   \Device\HarddiskVolume1\Users\IEUser\Desktop\CONFIDENTIAL DOCUMENT.docx
SharedCacheMap 0x7e841f80   None   \Device\HarddiskVolume1\Users\IEUser\Desktop\CONFIDENTIAL DOCUMENT.docx
```

After opening `CONFIDENTIAL DOCUMENT.docx` it looked like this:

![CONFIDENTIAL DOCUMENT.docx](https://github.com/lasq88/CTF/blob/main/nahamconctf2021/%5Bforensics%5D%20typewriter/recovered_file.PNG)
