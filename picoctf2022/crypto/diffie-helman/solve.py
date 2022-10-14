import string
message = "H98A9W_H6UM8W_6A_9_D6C_5ZCI9C8I_8F7GK99J"

alphabet = string.ascii_uppercase + string.digits
mod = len(alphabet)

for i in range(0,mod):
    decrypted = ""
    for c in message:
        if c != "_":
            decrypted = decrypted + alphabet[(alphabet.index(c) + i) % mod]
        else:
            decrypted = decrypted + "_"
    print(decrypted)