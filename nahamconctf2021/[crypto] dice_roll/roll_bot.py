import socket
import sys
import re
import select
import time
from randcrack import RandCrack

def main():
    ip = socket.gethostbyname('challenge.nahamcon.com')
    server_address = (ip, 31217)
    rc = RandCrack()

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('connecting to %s port %s' % server_address, file=sys.stderr)
    sock.connect(server_address)
    data = socket_receive(sock)
    msg = "2\n".encode()
    for i in range(624):
        socket_send(sock,msg)
        data = socket_receive(sock)
        n = int(data.decode("utf-8").split("\n")[1])
        rc.submit(n)
    msg = "3\n".encode()
    socket_send(sock,msg)
    data = socket_receive(sock)
    print(data.decode())
    guess = rc.predict_getrandbits(32)
    print(guess)
    msg = "{}\n".format(guess).encode()
    socket_send(sock,msg)
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