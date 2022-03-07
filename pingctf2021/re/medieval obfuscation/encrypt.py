def RiWdagGgRfVvwHIJ(zRIDfjFONtzYXcvt):
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

def obg(zRIDfjFONtzYXcvt, NiWivUmsPqwOeZSY, BLvaTjEmZoEKKxgh, AmZdWwBuyEiWjnLp, rOgkVYWWLtckACdK, pbWHBUYSqWGVOEio):
	return (int((str(RiWdagGgRfVvwHIJ(NiWivUmsPqwOeZSY))+str(RiWdagGgRfVvwHIJ(BLvaTjEmZoEKKxgh)))))*RiWdagGgRfVvwHIJ(zRIDfjFONtzYXcvt)/(int(str(RiWdagGgRfVvwHIJ(AmZdWwBuyEiWjnLp)+RiWdagGgRfVvwHIJ(rOgkVYWWLtckACdK))+str(RiWdagGgRfVvwHIJ(pbWHBUYSqWGVOEio))))
DWdFaFXGwROWZKun = 0x45FDAF8A1AE849DD90E841A0F2F93601F894F9791611DA585830619A1F41BBC9C231312DB9E653EC0EDA2A34CA34A0792EA5B8A4D0F47E87D5D46293D629A719
iJCxBYGeIazlujbH = 0xe9efaac27db47c326b50e33d4df92386c0816e7b15858e545d3fc793ca233085b4b6e89a96809aa79150bb864ca7c1478d88add29ca784d9a0ba1bb38b6b8176
VXbYeaXGWDsvCNCz = 0x3010922BE56A79C216E92466A180F71D86175363AD0AB2515F91436088A4AA2FAC9ABAE9108C17F38CD06DBCA0EED254CF4161243E5F502364AAAEB05D83D5C
OUOjdPHXwXtOYfKF = 0x5b02e4ea011b26b60e28b614d0ec77116cbe72f345000ca88db6b43df79a5d3121f321b03e7bc9d6c0233483a2a637bfe3c97dadf5a0e3f63823f1bee239bce9
AwzkEKbzAMUeLmYr = 0xd7be6cb6ad604aee70e9f9243485d08b578cc6b120a960228ab48564ac6384f999b91cfffd826d58f26a4e7cd5978bd7f944531b7b707851ccd7a3bc8df64030
HzyGlHuvFlQdOhZd = 0xfbf3f74e6b39f8417e56d21d83ad3ec54a50c8a40257137311ac1eead0c3273affd8a93126e4af8a679bb000dfdb4bb0124827523155edb0e3c23776da1a580c
with open("flag.txt", "rb") as RgddtGxAWwpUPuSm:
	KxPCfmZlmAtyxJaT = b"".join(RgddtGxAWwpUPuSm.readlines())[::-int(str(obg(DWdFaFXGwROWZKun,iJCxBYGeIazlujbH,VXbYeaXGWDsvCNCz,OUOjdPHXwXtOYfKF,AwzkEKbzAMUeLmYr,HzyGlHuvFlQdOhZd))[:int(obg(DWdFaFXGwROWZKun,iJCxBYGeIazlujbH,VXbYeaXGWDsvCNCz,OUOjdPHXwXtOYfKF,AwzkEKbzAMUeLmYr,HzyGlHuvFlQdOhZd))])]
	with open("encoded.txt", "wb") as zHqmseKqnypeVFVs:
		bwNBsexUfCtWCOlq = b""
		for i in range(len(KxPCfmZlmAtyxJaT)):
			bwNBsexUfCtWCOlq += bytes([int(KxPCfmZlmAtyxJaT[i])^RiWdagGgRfVvwHIJ(i)])
		zHqmseKqnypeVFVs.write(bwNBsexUfCtWCOlq)