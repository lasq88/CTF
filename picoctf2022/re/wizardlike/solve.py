f = open("game","rb")
fw = open("maps","w")
binary = f.read()

pMaps = 0x6740

for m in range(0,10):
    fw.write("-------------------------------MAP {}-------------------------------\n".format(m+1))
    i=0
    while i<10000:
        begin = 0x6740+i+10000*m+16*m
        fw.write(binary[begin:begin+100].decode()+"\n")
        i = i + 100
