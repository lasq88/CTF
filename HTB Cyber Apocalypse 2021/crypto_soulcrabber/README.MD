**Description**: Aliens heard of this cool newer language called Rust, and hoped the safety it offers could be used to improve their stream cipher.

**Stars**: 1/5

**Downloadable**:
out.txt - encrypted file
main.rs - encryption algorithm

**Goal**: To find a vulnerability of the algorithm and decrypt the flag

**Solution**: 

It is an encryption algorithm based on a randomly generated key with a static hardcoded seed. Solution was as simple as generating a decryption key, and use it to decrypt the payload.

My main challenge was rust itself, because I don't know this language at all and it seems quite different (especially in regards to typing) then all the others I use. In the end I went for a hybrid approach. I used a simple rust code to generate a key, and then python to decrypt it (could be also done in CyberChef or anywhere really):

```rust
use rand::{Rng,SeedableRng};
use rand::rngs::StdRng;

fn get_rng() -> StdRng {
    let seed = 13371337;
    return StdRng::seed_from_u64(seed);
}

fn main() -> std::io::Result<()> {
    let mut rng = get_rng();
    for _ in 0..41 {
        print!("{:02x}", rng.gen::<u8>());
    }
    Ok(())
}
```

```python
f1 = open("keys.txt","r")
keys = f1.readlines()
f2 = open("out.txt","r")
ciphertext=f2.read()

flag = ""

for i in range(0,len(keys)):
    flag = flag + chr(int(ciphertext[i*2]+ciphertext[i*2+1],16) ^ int(keys[i],16))

print(flag)
```