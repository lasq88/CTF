f1 = open("encoded.bmp","rb").read()
f2 = open("key.bmp","rb").read()
xored = b""
out = open("out.bmp","wb")


for i in range(len(f1)):
	xored = xored + (f1[i] ^ f2[i]).to_bytes(1,"big")

out.write(xored)

out.close()