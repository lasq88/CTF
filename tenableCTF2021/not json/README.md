Base64 encoded value with kind of custom made hex encoding later. It looked like this in hex editor:

![Encoding explained](https://github.com/lasq88/CTF/blob/main/tenableCTF2021/not%20json/encoding.PNG)

Basically there was a list of ascii printable characters first and then 19 pairs of 2(3)-byte values + 00 delimiter + 1 byte value. First number (marked yellow in the picture) was position of char in flag, second number (marked red) was position in alphabet (so 01 was "a", 02 was "b" etc.).

This was actually a pretty simple decoding challenge and could have been done completely manually. I opted to write a little bit more advanced python script that took into consideration also version of encoding where position numbers or alphabet didn't have to be in order.

