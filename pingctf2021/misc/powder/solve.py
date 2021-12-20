def obfuscate(zRIDfjFONtzYXcvt):
    MjwTIhbiOLDowBAf = zRIDfjFONtzYXcvt*0xe5 + 0xF7
    MjwTIhbiOLDowBAf = MjwTIhbiOLDowBAf&0xFF
    sIBzCZppHmIyFgkc = (((((MjwTIhbiOLDowBAf*0x26)+0x55)&0xFE)+(MjwTIhbiOLDowBAf*0xED)+0xD6)&0xFF )
    oawOYhYEabqLpCmg = ((((((- (sIBzCZppHmIyFgkc*0x2))+0xFF)&0xFE)+sIBzCZppHmIyFgkc)*0x03)+0x4D)
    TtSyJAEwFblgfrfp = (((((oawOYhYEabqLpCmg*0x56)+0x24)&0x46)*0x4B)+(oawOYhYEabqLpCmg*0xE7)+0x76)
    nqDVwfJnTpHpcVyW = ((((TtSyJAEwFblgfrfp*0x3A)+0xAF)&0xF4)+(TtSyJAEwFblgfrfp*0x63)+0x2E)
    jgUrDqXsxnCUCYZf = (nqDVwfJnTpHpcVyW&0x94)
    fHvOshwxPmPNTnYq = ((((jgUrDqXsxnCUCYZf+jgUrDqXsxnCUCYZf+(- (nqDVwfJnTpHpcVyW&0xFF)))*0x67)+0xD))
    nZXguQFVpgdPKQQY = ((fHvOshwxPmPNTnYq*0x2D)+(((fHvOshwxPmPNTnYq*0xAE)|0x22)*0xE5)+0xC2)&0xFF
    return (0xed*(nZXguQFVpgdPKQQY-0xF7))&0xff

with open("encoded", "rb") as flag_txt:
    encoded_flag = b"".join(flag_txt.readlines())
    with open("flag.txt", "wb") as decoded_flag_txt:
        decrypted_flag = b""
        for i in range(len(encoded_flag)):
            decrypted_flag += bytes([int(encoded_flag[i])^obfuscate(i)])
        decoded_flag_txt.write(decrypted_flag[::-1])