So the solution apparently was to:

1. unpack the pyinstaller binary with pyinstxtractor.py
2. take python38.dll from unpacked binary and run it as a custom python interpreter (with remaped opcodes)
3. use opcode.opmap to get modified opcode mapping
4. use code similar to what's in remap.py to remap opcodes in backup_decryptor.pyc
5. save anew binary to disk and decompile it with uncompyle6

Link to intended solution code from challenge author: https://gist.github.com/Billith/cfab9e624d693770732a81baffa5a384

I've never managed to run modified python38.dll - it kept crashing my python interpreter :(

Second, more timeconsuming solution:

1. unpack the pyinstaller binary with pyinstxtractor.py
2. parse opcode.pyc to get modified opcode map
3. run the same code as in intended solution

My take was to take a look at python38.dll in Ghidra, check function _PyEval_EvalFrameDefault and compare it to same function from not-modified python38.dll + python source code ( https://github.com/python/cpython/blob/master/Python/ceval.c ). 
This is very time consuming and I only managed to figure out 13/120 opcodes in few hours. I was hoping to discover some kind of pattern (like all opcodes shifted by 3) but there was none :(

I've learned a lot about python internals though, which is good.

Some reading I've done on the matter:

 * https://towardsdatascience.com/understanding-python-bytecode-e7edaae8734d
 * https://www.usenix.org/conference/woot13/workshop-program/presentation/kholia
 * https://github.com/kholia/dedrop
 * https://medium.com/tenable-techblog/remapping-python-opcodes-67d79586bfd5

Overall it was a pretty interesting and engaging challenge :)
