#!/usr/bin/env python3

import random
import os
from randcrack import RandCrack

rc = RandCrack()

dice_bits = 32
#flag = open('flag.txt').read()


for i in range(624):
	rc.submit(random.getrandbits(32))

print("Random result: {}\nCracker result: {}".format(random.getrandbits(32), rc.predict_getrandbits(32)))