def reverse(dst,src):
    return src[::-1]
def xor(dst,src):
    out = ""
    for i in range(0,len(dst)):
        if(i < len(src)):
            out = out + chr(ord(dst[i]) ^ ord(src[i]))
        else:
            out = out + dst[i]
    return out
def mov(dst,src):
    return src

TRX = "GED\x03hG\x15&Ka =;\x0c\x1a31o*5M"


#print(xor("dogs","shadow"))