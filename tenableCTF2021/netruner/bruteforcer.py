import requests
import re
import base64

url = 'http://167.71.246.232:8080/crypto.php'

regex = "<b>([A-Za-z0-9\/=+]*)<\/b>"
flag='flag'

try:
    for i in range(28):
        a = "A"*(27-i)
        cleartext = a
        data = {'text_to_encrypt': cleartext, 'do_encrypt': 'Encrypt'}
        #print(data)
        page = requests.post(url, data = data)
        ciphertext = re.findall(regex,page.text)[0]
        ct_decoded = base64.b64decode(ciphertext)
        second_block = ct_decoded[16:32]
        #print(second_block.hex())
        for c in range(32,127):
            cleartext2 = cleartext + flag + chr(c)
            data = {'text_to_encrypt': cleartext2, 'do_encrypt': 'Encrypt'}
            #print(data)
            page = requests.post(url, data = data)
            ciphertext = re.findall(regex,page.text)[0]
            ct_decoded = base64.b64decode(ciphertext)
            second_block_guess = ct_decoded[16:32]
            #print(second_block_guess.hex())
            if second_block == second_block_guess:
                print(chr(c))
                flag = flag + chr(c)
                if chr(c) == '}':
                    print(flag)
                    exit()
                break

#flag{b4d_bl0cks_for_g0nks}