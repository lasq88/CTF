I didn't manage to solve this challenge. There was a 3-byte hex pattern, where 3rd byte was part of message and 2 bytes before it applied some transformations. It turned out to be some kind of custom-made compression mechanism.

It looked like this in hexdump:

![Hackers Manifest](https://github.com/lasq88/CTF/blob/main/tenableCTF2021/hackers%20manifesto/hexdump.PNG)

My approach was to parse it in python (you can find parsed list in parsed.txt) and try to look for some patter/relation but ended up with nothing.

Community solution can be found in community_solution.py (I took it form discord, courtesy to tirefire user, he didn't provide link to github to link directly).
