import string

lines = open('out.txt').readlines()

flag="ping{"
alphanumeric = (string.ascii_letters + string.digits + "{}_")

for i in range(5,len(lines[0])//2):
	for j in alphanumeric:
		ok = True
		for line in lines:
			c = int(line[i*2]+line[i*2+1],16)
			r = c ^ ord(j)
			if r not in range(13,38):
				ok = False
				break
		if ok:
			flag = flag + j

print(flag)