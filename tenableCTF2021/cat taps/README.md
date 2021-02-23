PCAP file with USB HID (Keyboard + Mouse) protocol. In the end you had to parse keyboard interruption data to find a flag.

I managed to solve this manually as none of python scripts I found worked well for me. Though "cat.py" managed to find most of the flag so it gave me start for manual analysis.

Few usefull links:

https://abawazeeer.medium.com/kaizen-ctf-2018-reverse-engineer-usb-keystrok-from-pcap-file-2412351679f4
https://book.hacktricks.xyz/forensics/pcaps-analysis/usb-keyboard-pcap-analysis
https://usb.org/sites/default/files/documents/hut1_12v2.pdf
