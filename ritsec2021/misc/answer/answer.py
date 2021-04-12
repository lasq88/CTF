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