import sys

def translate(code):
    instruction = code.split()
    output = ""
    if (instruction[0] == "MOV"):
        output = instruction[1]+" = "+instruction[2]
    elif (instruction[0] == "XOR"):
        output = instruction[1]+" = xor("+instruction[1]+","+instruction[2]+")"
    elif (instruction[0] == "REVERSE"):
        output = instruction[1]+" = " + instruction[1] +"[::-1]"
    return output


def main():
    fin = open("Crypto.asm","r")
    fout = open("emu_code.py","a")
    text = fin.readlines()
    for line in text:
        out = translate(line)
        fout.write(out+"\n")
    fin.close()
    fout.close()

if __name__ == "__main__":
  main()
