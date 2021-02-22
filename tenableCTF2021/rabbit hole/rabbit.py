import requests
import re

url = 'http://167.71.246.232:8080/rabbit_hole.php?page='
code = 'cE4g5bWZtYCuovEgYSO1'

regex_list = "\[[0-9]*, '[0-9A-Za-z]*'\]"
regex_code = "[A-Za-z0-9\+=]{5,}"

solution = []

c=0

try:
    while(True):
        print(c)
        page = requests.get(url+code)
        print(page.text)
        if page.text != 'end':
            numbers = re.findall(regex_list,page.text)[0]
            code = re.findall(regex_code,page.text)[0]
            pp = eval(numbers)
            solution.append(pp)
            c = c+1
        else:
            break
except:
    print(solution)

flag = [None]*len(solution)

for e in solution:
    flag[e[0]] = int(e[1],16)


f = open('flag.png','wb')

f.write(bytes(flag))