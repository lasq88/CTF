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

DRX = "LemonS"
TRX = xor(TRX,DRX)
DRX = "caviar"
DRX = DRX[::-1]
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
DRX = "vaniLla"
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
DRX = "tortillas"
TRX = xor(TRX,DRX)
DRX = "applEs"
TRX = xor(TRX,DRX)
DRX = "miLK"
DRX = DRX[::-1]
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
TRX = TRX[::-1]
TRX = TRX[::-1]
DRX = xor(DRX,DRX)
TRX = xor(TRX,DRX)
DRX = "OaTmeAL"
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
TRX = TRX[::-1]
TRX = TRX[::-1]
DRX = xor(DRX,DRX)
TRX = xor(TRX,DRX)
DRX = "cereal"
TRX = xor(TRX,DRX)
DRX = "ICE"
DRX = DRX[::-1]
TRX = xor(TRX,DRX)
DRX = "cHerries"
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
DRX = "salmon"
TRX = xor(TRX,DRX)
DRX = "chicken"
TRX = xor(TRX,DRX)
DRX = "Grapes"
DRX = DRX[::-1]
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
DRX = "caviar"
DRX = DRX[::-1]
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
DRX = "vaniLla"
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
TRX = xor(TRX,DRX)
DRX = TRX
TRX = "HonEyWheat"
DRX = xor(DRX,TRX)
TRX = DRX
DRX = "HamBurgerBuns"
DRX = DRX[::-1]
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
TRX = TRX[::-1]
TRX = TRX[::-1]
DRX = xor(DRX,DRX)
TRX = xor(TRX,DRX)
DRX = "IceCUBES"
TRX = xor(TRX,DRX)
DRX = "BuTTeR"
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
TRX = xor(TRX,DRX)
TRX = TRX[::-1]
DRX = "CaRoTs"
TRX = xor(TRX,DRX)
DRX = "strawBerries"
TRX = xor(TRX,DRX)

print(TRX)