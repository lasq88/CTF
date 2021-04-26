**Description**: You found one of their space suits forgotten in a room. You wear it, but before you go away, a guard stops you and asks some questions.

**Stars**: 1/5

**Downloadable**:
passphrase - ELF binary

**Goal**: Analyze the backdoor and see how to exploit it

**Solution**: 

Another basic crackme challenge. When we execute the bianry we are asked for the password:

```bash
$ ./passphrase

Halt! ⛔
You do not look familiar..
Tell me the secret passphrase: abcdef

Intruder alert! 🚨
```

Let's take a look at the code. In the `main()` function, there seem to be an awful lot of local variables, that are later compared with user's input:

```c
  flag = 0x33;
  local_57 = 0x78;
  local_56 = 0x74;
  local_55 = 0x72;
  local_54 = 0x34;
  local_53 = 0x74;
  local_52 = 0x33;
  local_51 = 0x72;
  local_50 = 0x52;
  local_4f = 0x33;
  printstr(&DAT_00100bc8);
  printstr("\nYou do not look familiar..");
  printstr("\nTell me the secret passphrase: ");
  local_4e = 0x73;
  local_4d = 0x74;
  local_4c = 0x52;
  local_4b = 0x31;
  local_4a = 0x34;
  local_49 = 0x4c;
  local_48 = 0x35;
  local_47 = 0x5f;
  local_46 = 0x56;
  fgets(user_input + 1,0x28,stdin);
  local_45 = 0x53;
  local_44 = 0x5f;
  local_43 = 0x68;
  local_42 = 0x75;
  sVar2 = strlen(user_input + 1);
  user_input[sVar2] = '\0';
  local_41 = 0x6d;
  local_40 = 0x34;
  local_3f = 0x6e;
  local_3e = 0x35;
  local_3d = 0;
  iVar1 = strcmp(&flag,user_input + 1);
```

2 solutions here: we could just put them in the CyberChef, do a little regex magic and get a flag. Or we can simply debug the binary `gdb ./passphrase`:

First we set a breakpoint on the line where strcmp is:

```bash
(gdb) b main
Breakpoint 1 at 0x9ca
(gdb) run
Starting program: /mnt/d/Documents/ctf/hackthebox 2021/rev_passphrase/htb/passphrase

Breakpoint 1, 0x00000000080009ca in main ()
(gdb) disassemble main
Dump of assembler code for function main:
...
0x0000000008000ac0 <+250>:   callq  0x8000820 <strcmp@plt>
...
End of assembler dump.
(gdb) b *0x0000000008000ac0
Breakpoint 2 at 0x8000ac0
(gdb) conti
Continuing.

Halt! ⛔
You do not look familiar..
Tell me the secret passphrase: abcdefg

Breakpoint 2, 0x0000000008000ac0 in main ()
```

Then we simply display the flag:

```bash
(gdb) x/s $rax
0x7ffffffee140: "3xtr4t3rR3stR14L5_VS_hum4n5"
```

We can verify it now in our program:

```bash
$ ./passphrase

Halt! ⛔
You do not look familiar..
Tell me the secret passphrase: 3xtr4t3rR3stR14L5_VS_hum4n5
✔

Sorry for suspecting you, please transfer this important message to the chief: CHTB{3xtr4t3rR3stR14L5_VS_hum4n5}
```

Voila!