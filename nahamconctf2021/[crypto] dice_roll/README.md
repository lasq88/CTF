Original challenge file is dice_roll.py

Interesting crypto challenge. The goal is to guess next 32-bit result of `random.getrandbits(32)` functions. It uses `random.seed(os.urandom(dice_bits))` to initialize the seed, though this can be ignored by just not pressing option 1.

1. **First (wrong) intuition:** I didn't know much about random functions in python but after some googling I found out that using `os.urandom()` is [not cryptographically safe](https://stackoverflow.com/questions/47514695/whats-the-difference-between-os-urandom-and-random) as it won't block after os entropy pool is depleted resulting in potentially unsafe results. 
    So my first intuition was to exhaust os entropy pool by calling `os.urandom()` manytimes. It was very time-consuming (making 10000 requests to server took around an hour) and didn't really achieve anything.
    
2. **Solution**: I returned to this challenge after some time and started reading-up about python random library. Apparently, it uses a Mersenne Twister pseudorandom number generator that is [vulnerable to information leak vulnerability](https://bugs.python.org/issue16184), when *"after 312 random.random() calls it allows attackers to predict 313 random number with 2^8 accuracy based on 1, 2, 199, 200, 511, 625 random numbers"*
    It seems there is even a python library [RandCrack](https://pypi.org/project/randcrack/) already exploting this particular weakness, so there is no need to implemnt this ourselves.
    Solution code in roll_bot.py

```python
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
```
