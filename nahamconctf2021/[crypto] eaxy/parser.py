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