import string

def mod_inv(x,m):
    return pow(x, -1, m) #https://www.delftstack.com/howto/python/mod-inverse-python/

enc_flag = [104,290,356,313,262,337,354,229,146,297,118,373,221,359,338,321,288,79,214,277,131,190,377]

dec_flag = ""
alphabet = string.ascii_uppercase + string.digits + "_"

for c in enc_flag:
    mi = mod_inv(c%41,41)
    dec_flag = dec_flag + alphabet[mi-1]

print("picoCTF{"+dec_flag+"}")