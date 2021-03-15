**NOT SOLVED**

Edit: After checking some write-ups, apparently https://www.dcode.fr/book-cipher works flawlessly for this challenge. Not sure why and what is their word counting strategy.

Didn't manage to solve this (supposedly) easy crypto challenge :( I'm quite sure used cipher was [Beale cipher](https://en.wikipedia.org/wiki/Beale_ciphers) but it didn't work. 

note.txt was encrypted flag
>4661 5099 13243 11578 { 14382 734 14024 10621 14382 2 3383 8702 6087 10621 7417 14382 12352 615 1208 4246 4657 9975 7203 2658 770 4 10621 8702 6125 980 9522 2659 14784 7203 8701 38}

Therefore 4661 5099 13243 11578 = flag

But checking these words from hackers.txt revealed completely different characters.

I tried to do some kind of proximity analysis to check if there is any common offset to correct characters but there wasn't. For example for "l" there wasn't "l-word" even close to 5099th word

Solution attempt in decypher.py
```python
note = "4661 5099 13243 11578 14382 734 14024 10621 14382 2 3383 8702 6087 10621 7417 14382 12352 615 1208 4246 4657 9975 7203 2658 770 4 10621 8702 6125 980 9522 2659 14784 7203 8701 38".split()
f = open("hackers.txt","r")

words = f.read().split()


f = []
l = []
a = []
g = []

i = 0
for c in "flag":
    pos = int(note[i])
    for w in range(pos-100,pos+150):
        if (words[w][0] == c) or (words[w][0] == c.upper()):
            diff = w - pos
            eval(c).append(diff)
            #print(w, words[w])
    i = i + 1

print(f)
print(l)
print(a)
print(g)

print(list(set(f) & set(l) & set(a) & set(g)))
```

Results
```
[-73, 6, 33, 82, 96, 108]
[-26, -22, 59, 61, 119, 136]
[-59, -53, -45, -29, -27, -17, -14, -11, 5, 20, 26, 66, 85, 88, 89, 101, 111, 113, 123, 134]
[4, 5, 66, 112, 122, 148]
[]
```
