import itertools

def deaccumulate(s):
    s = s[::-1]
    r = []
    for i in range(0,len(s)):
        if i == len(s)-1:
            r.append(s[i])
        else:
            r.append(s[i] - s[i + 1])
    return r[::-1]

def deobf(s):
    s = [x // 69684751861829721459380039 for x in s]
    s = deaccumulate(s)
    return ''.join([chr(y) for y in s])

#acc = list(itertools.accumulate([1,5,10]))

just_arr = [7386583697353950474694284134, 15539699665188027885441748697, 23553446129298445853270453182, 31636877345270693542558537706, 36305755720013284880337000319, 42159274876406981482924923595, 47037207506735061985081526325]



print(deobf(just_arr))