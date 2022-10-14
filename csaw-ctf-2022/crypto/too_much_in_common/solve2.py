import binascii
import socket
import select
import sys
import time
from math import gcd

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

def extended_euclidean(a, b):
  if b == 0:
    gcd, s, t = a, 1, 0
    return (gcd, s, t)
  else:
    s2, t2, s1, t1 = 1, 0, 0, 1
    while b > 0:
      q= a // b
      r, s, t = (a - b * q),(s2 - q * s1),( t2 - q * t1)
      a,b,s2,t2,s1,t1=b,r,s1,t1,s,t
    gcd,s,t=a,s2,t2
    return (gcd,s,t)

def find_m(n,n2,e,e2,c,c2):
    _,a,b = extended_euclidean(e, e2)
    if a < 0:
        i = pow(c,-1,n)
        m = (pow(i,-a, n) * pow(c2,b,n)) % n
    else:
        i = pow(c2,-1,n)
        m = (pow(c,a,n) * pow(i,-b,n)) % n
    return binascii.unhexlify(hex(m)[2:])

def find_pq(n,e,d):
    gs = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
    k = d * e -1
    t = k
    for g in gs:
        while True:
            if t % 2 == 0:
                t = t // 2
                x = pow(g,t,n)
                y = gcd(x-1,n)
                if x > 1 and y > 1:
                    print("Success!")
                    p = y
                    q = n//y
                    return p,q
            else:
                break


def main():
    ip = socket.gethostbyname('crypto.chal.csaw.io')
    port = 5000
    server_address = (ip, port)
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('connecting to %s port %s' % server_address, file=sys.stderr)
    sock.connect(server_address)
    data = socket_receive(sock)
    socket_send(sock, b"2 d0nt_reUs3_c0mm0n_m0duLus_iN_RSA\n")
    data = socket_receive(sock)
    data = data + socket_receive(sock)
    n,e,d = int(data.split(b"\r\n")[6].split(b" = ")[1]), int(data.split(b"\r\n")[8].split(b" = ")[1]), int(data.split(b"\r\n")[10].split(b" = ")[1])
    print("n = {}\ne = {}\nd = {}".format(n,e,d))
    p,q = find_pq(n,e,d)
    phi = (p-1) * (q-1)
    socket_send(sock, ("2 "+str(phi)+"\n").encode())
    data = socket_receive(sock)
    data = data + socket_receive(sock)
    print(data)
    #while True:
     #   socket_send(sock, b"1\n")
      #  data = socket_receive(sock)
       # data = data + socket_receive(sock)
        #print(data)
        #print(data)
        #n2,e2,d2 = int(data.split(b"\r\n")[6].split(b" = ")[1]), int(data.split(b"\r\n")[8].split(b" = ")[1]), int(data.split(b"\r\n")[10].split(b" = ")[1])
        #gcd_result = gcd(n,n2)
        #if(gcd_result != 1):
         #   print("Success!")
          #  print("n = {}\ne = {}\nd = {}".format(n,e,d))
           # print("n2 = {}\ne2 = {}\nd2 = {}".format(n2,e2,d2))
            #break  
    sock.close()

if __name__ == "__main__":
    main()