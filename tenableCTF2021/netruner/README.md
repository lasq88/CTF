Very nice challenge, I learned a lot about block-cyphers when solving it. In the end article that helped me to solve it was this one:

https://www.linkedin.com/pulse/short-note-prefix-chosen-plaintext-attack-cpa-ecb-mode-hannes-salin/

Based on this I managed to implement a script in bruteforcer.py. It basically feeds a chosen plaintext of 32 - (length of known flag) + 1 into encryption function, checks second block of ECP transformation, then bruteforces single byte at the time (limiting to printable ascii range for optimization) and compares output block to the stored one.
