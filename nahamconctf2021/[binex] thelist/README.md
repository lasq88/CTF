**NOT SOLVED**

Great write-up here: https://github.com/cavetownie/pwn_journey/blob/main/NahamCon2021/writeups/thelist/thelist.md

Branded as "easy" binary exploitation challenge but still too difficult for me ;)

There was a list of users to edit consisting of 5 options and an input to provide your name. There was no obvious overflow in the input, but some buffer of lenght 0x240 was initialized to keep usernames.

Main function:
```c
undefined8 main(void)

{
  size_t sVar1;
  undefined local_248 [524];
  undefined4 local_3c;
  char local_38 [47];
  char local_9;
  
  local_9 = '\x01';
  memset(local_248,0,0x200);
  printf("Enter your name: ");
  fgets(local_38,0x20,stdin);
  sVar1 = strcspn(local_38,"\r\n");
  local_38[sVar1] = '\0';
  printf("Welcome %s!\n",local_38);
  putchar(10);
  while (local_9 != '\0') {
    menu();
    __isoc99_scanf(&DAT_00402095,&local_3c);
    getchar();
    switch(local_3c) {
    default:
      puts("Invalid choice!");
      break;
    case 1:
      print_users(local_248);
      break;
    case 2:
      add_user(local_248);
      break;
    case 3:
      delete_user(local_248);
      break;
    case 4:
      change_uname(local_248);
      break;
    case 5:
      local_9 = '\0';
    }
    local_3c = 0;
  }
  puts("Goodbye!");
  return 0;
}
```

add_user function
```c
void add_user(long param_1)

{
  size_t sVar1;
  int local_1c;
  
  local_1c = 0;
  while (*(char *)(param_1 + (long)local_1c * 0x20) != '\0') {
    local_1c = local_1c + 1;
  }
  printf("Enter the user\'s name: ");
  fgets((char *)((long)local_1c * 0x20 + param_1),0x20,stdin);
  sVar1 = strcspn((char *)(param_1 + (long)local_1c * 0x20),"\r\n");
  *(undefined *)((long)local_1c * 0x20 + param_1 + sVar1) = 0;
  puts("User added!");
  putchar(10);
  return;
}
```
