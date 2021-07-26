from Crypto.Cipher import AES
import binascii

def decrypt(data):
    data = binascii.unhexlify(data)
    key = binascii.unhexlify('3132333435363132333435363132333435363132333435363132333435363132')
    nonce, tag = data[:12], data[-16:]
    cipher = AES.new(key, AES.MODE_GCM, nonce)
    dt = cipher.decrypt_and_verify(data[12:-16], tag)
    return dt

def main():
    f = open("network_hex_encrypted.txt", "r")
    data = f.read()

    while data != "":
        data_len_hex = data[:8]
        if data_len_hex == "":
            break
        data = data[8:]
        data_len_int = int(data_len_hex[-2:] + data_len_hex[-4:-2] + data_len_hex[-6:-4] + data_len_hex[:-6],16) * 2
        ct = data[:data_len_int]
        dt = decrypt(ct)
        try:
            print(dt.decode('ascii'))
        except:
            print(dt)
        data = data[data_len_int:]
    f.close()


if __name__ == '__main__':
    main()