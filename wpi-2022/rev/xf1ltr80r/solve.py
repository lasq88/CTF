import random
import binascii
import socket
import select
import sys
import time
import base64

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


def main():
    ip = socket.gethostbyname('xf1ltr80r.wpi-ctf-2022-codelab.kctf.cloud')
    #ip = socket.gethostbyname('xf1ltr80r.wpi-ctf.kctf.cloud')
    port = 1337
    server_address = (ip, port)
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('connecting to %s port %s' % server_address, file=sys.stderr)
    sock.connect(server_address)
    hexi = "4231567a654a64344e7a49484e54625665734975396b4a333856657a4d784e334d7a415874474e6743393d3d0d0a0d0a"
    data = binascii.unhexlify(hexi)
    #data = hexi
    print("Sending: {}".format(data))
    socket_send(sock, data)
    data = socket_receive(sock).decode("utf-8")
    print(data)
    sock.close()

if __name__ == "__main__":
    main()