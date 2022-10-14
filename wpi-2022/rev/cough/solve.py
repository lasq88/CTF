import binascii

file = open("flag.cough","r")

content = file.read()
standard ='0123456789ABCDEF'
substituted = '7C061F258E493DAB'

decrypted = ""
for c in content:
    decrypted = decrypted + standard[substituted.index(c)]

out = binascii.unhexlify(decrypted)

file = open("flag.jpg","wb")
file.write(out)
file.close()