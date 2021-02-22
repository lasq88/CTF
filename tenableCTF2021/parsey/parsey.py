import re
'''
:param blob: blob of data to parse through (string)
:param group_name: A single Group name ("Green", "Red", or "Yellow",etc...)

:return: A list of all user names that are part of a given Group
'''
def ParseNamesByGroup(blob, group_name):
    regex = '\["age"\:([0-9]{1,3}), "user_name":"([a-zA-Z0-9 _]*)", "Group":"([a-zA-Z0-9 _]*)"\]'
    parsed = re.findall(regex,blob)
    out = []
    for e in parsed:
        if e[2] == group_name:
            out.append(e[1])
    return out

   
data = raw_input()
group_name = data.split('|')[0]
blob = data.split('|')[1]
result_names_list = ParseNamesByGroup(blob, group_name)
print result_names_list

#Black|+++,Bellhomes LLC.,["age":39, "user_name":"Reid Jolley", "Group":"Black"],+++,Greek Ideas,["age":63, "user_name":"Lucius Chadwell", "Group":"Green"],["age":63, "user_name":"Cary Rizzuto", "Group":"Black"],["age":28, "user_name":"Shoshana Bickett", "Group":"Yellow"],["age":69, "user_name":"Madeleine Swallow", "Group":"Green"],["age":41, "user_name":"Buddy Etter", "Group":"Black"],+++,God fire,["age":26, "user_name":"Carlene Caulder", "Group":"Green"],["age":43, "user_name":"Napoleon Peay", "Group":"Purple"],["age":44, "user_name":"Noemi Constant", "Group":"Green"]
