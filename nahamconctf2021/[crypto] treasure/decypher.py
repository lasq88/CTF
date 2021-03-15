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
            print(w, words[w])
    i = i + 1

print(f)
print(l)
print(a)
print(g)

print(list(set(f) & set(l) & set(a) & set(g)))