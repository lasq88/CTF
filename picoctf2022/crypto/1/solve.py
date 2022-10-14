import string

enc_flag = [91,322,57,124,40,406,272,147,239,285,353,272,77,110,296,262,299,323,255,337,150,102]

dec_flag = ""
alphabet = string.ascii_uppercase + string.digits + "_"

for c in enc_flag:
    dec_flag = dec_flag + alphabet[c%37]

print("picoCTF{"+dec_flag+"}")