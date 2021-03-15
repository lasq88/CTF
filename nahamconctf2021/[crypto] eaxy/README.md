Quite easy crypto challenge. File was encrypted with single-byt xor but every line was encrypted with different xor key, after decryption revealing tip like this:

>The XOR key you used to find string this is the 0 character index of the flag 

So basically XOR key used to decrypt specific line was n-th character number of the flag.

So to solve it, simple python script was sufficient to go through all possible xor keys and then build a flag from them.

Solution in parser.py (not sure why I called it parser, don't @ me)

```python
import re

f = open("eaxy","rb")

content = f.read()
flag_dict = {}

for x in range(256):
    xored = ""
    for c in content:
        xored = xored + chr(c ^ x)
    xor_strings = re.findall("the ([0-9]{1,2}) character",xored,flags=re.IGNORECASE)
    for n in xor_strings:
        flag_dict[int(n)] = x

flag = ""
for i in range(len(flag_dict)):
    flag = flag + chr(flag_dict[i])

print(flag)
```
