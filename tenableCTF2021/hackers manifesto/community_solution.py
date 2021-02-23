#!/usr/bin/env python3

with open('hacker_manifesto.txt', 'rb') as f:
    words = []
    data_t = f.read(2)
    count = 0
    while data_t:
        count += 1
        if data_t[0] == 0 and data_t[1] == 0: # no insertion needed
            words.append(f.read(1).decode())
        else: # need to insert a letter before this one
            rev = len(words) - data_t[0]
            inserts = data_t[1] // 4
            offset = data_t[1] % 4 # use this extra bit to go back even further
            if offset != 0:
                rev -= (256 * offset)
            print('reading {} letters'.format(inserts))
            print('current length {} looking back {} letters'.format(len(words), rev))
            for i in range(inserts):
                print(rev, i, words[rev + i])
                words.append(words[rev + i])
            words.append(f.read(1).decode())

        #if count > 110: break


        data_t = f.read(2)

print(''.join(words))
