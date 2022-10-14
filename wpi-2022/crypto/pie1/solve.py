import itertools

flag = "lxmwsuwaxbweqiutekwvtl"

def encryption(string, key): 
  encrypt_text = [] 
  for i in range(len(string)): 
    x = (ord(string[i]) +ord(key[i])) % 26
    x += ord('A') 
    encrypt_text.append(chr(x)) 
  return("" . join(encrypt_text)) 

def decryption(encrypt_text, key): 
  orig_text = [] 
  for i in range(len(encrypt_text)):
    if ord(encrypt_text[i]) in range(97,123):
        x = (ord(encrypt_text[i]) -ord(key[i % len(key)]) + 26) % 26
        x += ord('a') 
        orig_text.append(chr(x))
    else:
        orig_text.append(encrypt_text[i])
  return("" . join(orig_text)) 

pie_perms = list(itertools.permutations("pie"))
pie_combs = list(itertools.combinations_with_replacement(pie_perms,6))
keys = ["pie" + "".join(("".join(y) for y in x)) for x in pie_combs]

cartesian = list(itertools.product(list(itertools.permutations("pie",3)),list(itertools.permutations("pie",3)),list(itertools.permutations("pie",3)),list(itertools.permutations("pie",3)),list(itertools.permutations("pie",3)),list(itertools.permutations("pie",3)),list(itertools.permutations("pie",1))))

keys = ["pie" + "".join(("".join(y) for y in x)) for x in cartesian]

results = {}
for k in keys:
    decrypted = decryption(flag,k)
    print(decrypted[0:3]+"{"+decrypted[3:]+"}")
    results[decrypted[0:3]+"{"+decrypted[3:]+"}"] = k

pie = "piepiepiepiepiepiep"

pies = ["pie" + pie[i::-1] + pie[:i:-1] for i in range(len(pie))]

for p in pies:
    decrypted = decryption(flag,p)
    #print(decrypted[0:3]+"{"+decrypted[3:]+"}")
    #results[decrypted[0:3]+"{"+decrypted[3:]+"}"] = k

#flag = "hkqhstmoabaqewghnpw"

#flag_perms = ["".join(x) for x in list(itertools.permutations(flag))]