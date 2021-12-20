import socket
import sys
import re
import select
import time
import random

def main():
    ip = socket.gethostbyname('chall.knping.pl')
    server_address = (ip, 22224)

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('connecting to %s port %s' % server_address, file=sys.stderr)
    sock.connect(server_address)
    while True:
        data = socket_receive(sock)
        print(data.decode())
        if "ping{" in data.decode():
            data = socket_receive(sock)
            print(data.decode())
            break
        numbers = re.findall(r'[0-9]{3,100}',str(data))
        seed = int(numbers[0])
        low = int(numbers[1])
        high = int(numbers[2])
        random.seed(seed)
        result = random.randrange(low,high)
        socket_send(sock,str(result).encode("utf-8")+b"\n")
        print(result)
        #time.sleep(1)

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