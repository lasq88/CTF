import re

f = open("gone_batty", "r")
lines = f.readlines()
set_regex = r"set ([a-z]*) ?=(.*)"
chars_regex = r"set \/a ([a-z]*) ?=([0-9]*) ?%% ?([0-9]*)"
cmd_regex = r"cmd \/c exit (.)"
replacements = {}

#first pass - parse obfuscation into dict
for i in range(len(lines)):
    m = re.match(set_regex, lines[i])
    m2 = re.match(chars_regex, lines[i])
    if m or m2:
        if m:
            variable = "%"+m.group(1)+"%"
            if m.group(2) == "%=exitcodeAscii%":
                m3 = re.match(cmd_regex, lines[i-1])
                value = m3.group(1)
            else:
                value = m.group(2)
        else:
            variable = "%"+m2.group(1)+"%"
            value = chr(int(m2.group(2)) % int(m2.group(3)))
        replacements[variable] = value
        for j in range(i,len(lines[i::])):
            lines[j] = lines[j].replace(variable,value)

#second pass replace code
variable_regex = r"(%[a-z]*%)"
i = 0
for line in lines:
    variables = re.findall(variable_regex,line)
    tmp = line
    for v in variables:
        if v in replacements:
            #print(v, replacements[v])
            tmp = tmp.replace(v, replacements[v])
    lines[i] = tmp
    i = i + 1


#third pass - find flag
flag_regex = r":: set flag_character([0-9]{1,2})=(.)"
flag_dict = {}
for line in lines:
    m = re.match(flag_regex, line)
    if m:
        flag_dict[int(m.group(1))] = m.group(2)

#print flag

flag = ""
for i in range(len(flag_dict)):
    flag = flag + flag_dict[i+1]

print(flag)

f.close()
