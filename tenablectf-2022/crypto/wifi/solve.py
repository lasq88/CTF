import socket
import sys
import re
import select
import time
import random
import string
import binascii
import base64

def main():
    ip = socket.gethostbyname('0.cloud.chals.io')
    #ip = "192.168.1.50"
    port = 28931
    #port = 1237
    server_address = (ip, port)
    flag = "flag{"


    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('connecting to %s port %s' % server_address, file=sys.stderr)
    sock.connect(server_address)
    data = socket_receive(sock)
    print(data.decode())
    while True:
        trailer = find_trailer(sock,flag)
        if trailer != -1:
            flag = bruteforce(sock,trailer,flag)

def find_trailer(sock,flag):
    trailer = ""
    for c in string.printable:
        username = trailer + flag
        print("Trying: "+username)
        socket_send(sock,username.encode("utf-8")+b"\n")
        data = socket_receive(sock)
        data = base64.b64decode(data)
        block_count_1 = int(len(data) / 16)
        print("Block count: {}".format(block_count_1))
        username = trailer + flag[:-1] + ";"
        print("Trying: "+username)
        socket_send(sock,username.encode("utf-8")+b"\n")
        data = socket_receive(sock)
        data = base64.b64decode(data)
        block_count_2 = int(len(data) / 16)
        print("Block count: {}".format(block_count_2))
        if block_count_1 < block_count_2:
            return trailer
        trailer = trailer + c
    return -1

def bruteforce(sock,trailer,flag):
    while True:
        if flag[-1] == "}":
            print("Flag found!")
            print(flag)
            exit()
        for c in string.digits+string.ascii_letters+"{}_!@#$%^&*?":
            sh_flag = flag[-5:]
            username = trailer + sh_flag + c
            print("Trying: "+sh_flag+c)
            socket_send(sock,username.encode("utf-8")+b"\n")
            data = socket_receive(sock)
            data = base64.b64decode(data)
            block_count = int(len(data) / 16)
            #print("Block count: {}".format(block_count))
            #for i in range(block_count):
            #    print(binascii.hexlify(data[i*16:i*16 + 16]) + b' ')
            if block_count < 5:
                flag = flag + c
                print(flag)
                break
            if c == "?":
                return flag

def socket_receive(sock):
    data = b''
    try:
        amount_expected = 4096
        ready = select.select([sock], [], [], 2)
        data = sock.recv(amount_expected)
    finally:
        return data

def socket_send(sock, data):
    try:
        sock.send(data)
    except:
        print("Couldn't send data")


if __name__ == "__main__":
    main()