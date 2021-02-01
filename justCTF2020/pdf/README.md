```
binwalk -e challenge.pdf
cat _challenge.pdf.extracted/feelies/false_flag.md
./_challenge.pdf.extracted/feelies/mutool draw -r 300 -o rendered.png challenge.pdf
use hexeditor to extract obj 4919 1 (0x1337 = 4919 dec ;)
printf "\x1f\x8b\x08\x00\x00\x00\x00\x00" | cat - [4919.out] | gzip -dc > out (or use cyberchef deflate)
cat out | xxd -r -p > flag.jfif (or cyberchef fromhex)
CONGRATS!
```
