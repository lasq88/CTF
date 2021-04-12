Idea was to make DNS requests agains custom DNS server and each request get 3 CNAME recored as a result, after some time we stumble at random_txt_record that has a flag as a TXT record:

![dig](https://github.com/lasq88/CTF/blob/main/ritsec2021/misc/answer/dig.PNG)

Simple script resolving this challenge in answer.py:

```python
import dns.resolver

def main():
    my_resolver = dns.resolver.Resolver()
    my_resolver.nameservers = ['34.69.61.54']
    domains = ['answers.ritsec.club']
    query = 'CNAME'
    answer = "answers.ritsec.club"
    while (True):
        try:
            answers = []
            for d in domains:
                while (True):
                    old = answer
                    answer = str(my_resolver.resolve(d, query)[0])[:-1]
                    if answer == old:
                        break
                    else:
                        if answer not in answers:
                            answers.append(answer)
                try:
                    print("try_txt {}",d)
                    answer_txt = str(my_resolver.resolve(d, 'TXT')[0])[:-1]
                    print(answer_txt)
                    return
                except:
                    continue
            domains = answers
        except:
            break

if __name__ == "__main__":
    main()
```
