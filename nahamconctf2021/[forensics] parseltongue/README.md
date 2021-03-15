vulcan@DESKTOP-93D27OT:/mnt/d/Documents/ctf/nahamcon/parseltongue$ cp parseltongue parseltongue.pyc
vulcan@DESKTOP-93D27OT:/mnt/d/Documents/ctf/nahamcon/parseltongue$ uncompyle6 parseltongue.pyc
# uncompyle6 version 3.7.4
# Python bytecode 3.8 (3413)
# Decompiled from: Python 3.8.5 (default, Jul 28 2020, 12:59:40)
# [GCC 9.3.0]
# Embedded file name: ./parseltongue.py
# Compiled at: 2021-02-28 21:42:29
# Size of source mod 2**32: 1889 bytes
import Crypto.Util.number as l2b
import random
sszz = [
 'aposlogahs', 'apsle', 'Sine', 'aʃe', 'bei∫ed', 'tuif', 'Kura', 'Vera', 'pard', 'pardshesl', 'bo∫', 'Gara', 'vinth', 'Pelʃis', 'keilsing', 'khair', 'tikni', 'Bana', 'Slehara', 'koukh', 'kups', 'dai', 'Andi', 'dorʃe', 'doʃe', 'sloʃe', 'kaʃe', 'Sarna', 'Suu', 'giʃe', 'Gorna', 'ass-girou', 'dros', 'feslure', 'hasli', 'riʃan', 'fraeslis', 'vris', 'gatsi', 'runʃe', 'Tira', 'hishe', 'einʃe', 'hesleuf', 'Firna', 'Baʃ', 'ʃem', 'ai', 'ine', 'dinʃe', 'Negei', 'slanp', 'ʃena', 'sliʃe', 'dati', 'slifai', 'Kuine', 'Ha', 'nisl', 'ʃe', 'Sobne', 'bna', 'Sora', 'ovith', 'houk', 'parknent', 'fasar', 'nesha', 'praughs', 'Pura', 'ʃine', 'ʃane', 'gisan', 'rai∫e', 'kata', 'Ara', 'Nigi', 'akaʃe', 'rashe', 'slan', 'Derne', 'Tina', 'snart', 'gariʃe', 'kerashe', 'stabsle', 'Fasi', 'Peina', 'Tasi', 'Sekusi', 'Harne', 'kapi', 'Athne', 'vaʃe', 'asl', 'ʃik', 'agiro', 'vei', 'Asuna', 'Teʃ', 'Fiʃ', 'Doʃ', 'ʃira', 'Haʃ', 'Vuʃ', 'vindovth', 'Bira', 'Sa', 'Slu', 'ou', 'iangsteur']
zzss = b'\x07\x1c\x0e\x14\x17\n\x06\x03\x0cJ\x00@G\x0e\x017X\x0b\x04W\xf8\xb5\x03P\x06\x0f\x80\xea\x9b\x00\x05A\x16\\\x00.\x17\x0f'
s = False
z = True
ss = s & z
z = abs(ss) - abs(z)
zz = ss | z
z = zz - z - z
zz = z | z
z = zz << zz
s = ss >> ss
sz = s << z
zs = z << s
z = zs - sz
ss = str(z).replace(str(zs), str(ss).replace(str(ss), str(z).replace(str(z), '')))
sss = bytes(ss.join(sszz), 'utf-8')
zzz = bytes([_a ^ _b for _a, _b in zip(sss, zzss)])
print(zzz.decode())
ssszzz = bytes([_a ^ _b for _a, _b in zip(zzz, zzss)])
sss += b'S'
ssss = []
ss = sss[:len(sss) // 2]
zz = sss[len(sss) // 2:]
for s in range(len(ss)):
    ssss.append(ss[s] ^ zz[s])
else:
    if 5 == 1:
        print(' '.join([random.choice(sszz).upper() for _ in range(random.randrange(5, 10))]))
    else:
        print(' '.join([random.choice(sszz).upper() for _ in range(random.randrange(5, 10))]))
# okay decompiling parseltongue.pyc