Implement hash mechanism according to specs, run it against rockyou.txt dictionary:

```python
import sys

def hash(hi,x):
    out_arr = hi.copy()
    for xi in x:
        in_arr = out_arr.copy()
        for r in range(13):
            in_arr = out_arr.copy()
            out_arr[0xA - 10] = ((((((((in_arr[0xC - 10] ^ in_arr[0xE - 10]) & in_arr[0xF - 10]) + in_arr[0xB - 10]) % 256) + (in_arr[0xD - 10] << 2) % 256) + xi) % 256) + r) % 256
            out_arr[0xB - 10] = in_arr[0]
            out_arr[0xC - 10] = in_arr[0xD - 10] << 2
            out_arr[0xD - 10] = in_arr[0xB - 10] >> 5
            out_arr[0xE - 10] = (in_arr[0xA - 10] + in_arr[0xF - 10]) % 256
            out_arr[0xF - 10] = in_arr[0xD - 10]
    return ''.join(["{0:0{1}x}".format(i,2) for i in out_arr])

def main(argv):
    f = open(argv[0],"r")
    lines = f.readlines()
    for word in lines:
        seed = list(map(ord,"RITSEC"))
        cleartext = list(map(ord,word))[:-1]
        out = hash(seed,cleartext)
        if out == "435818055906":
            print(''.join([chr(i) for i in cleartext]))
            return


if __name__ == "__main__":
    main(sys.argv[1:])
```
