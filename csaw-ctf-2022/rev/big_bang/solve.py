import random
import binascii
import socket
import select
import sys
import time

MAGIC = 73

def gen_iv_b(iv_a):
    return [b"\xff" * MAGIC if iv_a[i]=='1' else b"\x00" * MAGIC for i in range(MAGIC)]

def gen_out(a):
    return binascii.hexlify(b"".join(gen_iv_b(a)))

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
    ip = socket.gethostbyname('rev.chal.csaw.io')
    port = 5004
    server_address = (ip, port)
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('connecting to %s port %s' % server_address, file=sys.stderr)
    sock.connect(server_address)
    data = socket_receive(sock)
    bits = (data.split(b"\n")[1].split(b" : ")[1]).decode("UTF-8")
    print("IV: {}".format(bits))
    inp = gen_out(bits)
    print("Sending: {}".format(inp))
    socket_send(sock, inp+b"\n")
    data = socket_receive(sock).decode("utf-8")
    print(data)
    sock.close()

if __name__ == "__main__":
    main()