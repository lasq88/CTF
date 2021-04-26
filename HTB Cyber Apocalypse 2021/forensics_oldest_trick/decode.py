import codecs
f = open("data.txt", "r")
lines = f.readlines()
result = b""

for line in lines:
    result = result + codecs.decode(line[16:48], "hex")

f2 = open("output.bin", "wb")

f2.write(result)
f2.close()
f.close()