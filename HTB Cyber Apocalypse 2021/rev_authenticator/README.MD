**Description**: We managed to steal one of the extraterrestrials' authenticator device. If we manage to understand how it works and get their credentials, we may be able to bypass all of their security locked doors and gain access everywhere!

**Stars**: 1/5

**Downloadable**:
authenticator - ELF binary

**Goal**: Defeat the authenticator check

**Solution**: 

A very basic crackme challenge. After launching a binary, we are asked to provide the ID:

```bash
$ ./authenticator

Authentication System 👽

Please enter your credentials to continue.

Alien ID: Test
Access Denied!
```

To get it, let's open this binary in Ghidra. Right after looking at the `main()` function we see a following line

```c
iVar1 = strcmp(local_58,"11337\n");
```

Let's try again:

```bash
$ ./authenticator

Authentication System 👽

Please enter your credentials to continue.

Alien ID: 11337
Pin: test
Access Denied!
```

Now we need a PIN. In the code we can see that whatever we pass to the program, is passed to `checkpin()` function. So it is worth checking:

```c
    fgets(local_38,0x20,stdin);
    iVar1 = checkpin(local_38);
```

This function is not really that complicated and it has the correct PIN actually hardcoded, only XORed with `0x9` key:

```c
if ((byte)("}a:Vh|}a:g}8j=}89gV<p<}:dV8<Vg9}V<9V<:j|{:"[local_24] ^ 9U) != param_1[local_24])
```

So our final PIN seems to be `th3_auth3nt1c4t10n_5y5t3m_15_n0t_50_53cur3`

Let's check:

```bash
$ ./authenticator

Authentication System 👽

Please enter your credentials to continue.

Alien ID: 11337
Pin: th3_auth3nt1c4t10n_5y5t3m_15_n0t_50_53cur3
Access Granted! Submit pin in the flag format: CHTB{fl4g_h3r3}
```

Voila!