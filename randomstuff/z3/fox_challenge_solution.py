from z3 import *
from hashlib import md5, sha1, sha256, sha384

# Create the Z3 solver instance
solver = Solver()

# Define the name and secret variables
name = String('name')
secret = String('secret')

# Define the constraints for check1
solver.add(Length(name) >= 16)

# Define the constraints for check2
solver.add(Length(secret) == 29)
solver.add(SubSeq(secret, 5, 1) == StringVal('-'))
solver.add(SubSeq(secret, 11, 1) == StringVal('-'))
solver.add(SubSeq(secret, 17, 1) == StringVal('-'))
solver.add(SubSeq(secret, 23, 1) == StringVal('-'))
for i in range(29):
    if i not in [5, 11, 17, 23]:
        solver.add(secret[i].is_digit())

# Define the constraints for check3
hash_algorithms = [md5, sha1, sha256, sha384, sha256]
expected_hashes = secret.split("-")
name_bytes = bytes.fromhex((m := name.encode().hex())[1::2] + m[::2])

for i, algorithm in enumerate(hash_algorithms):
    solver.add(algorithm(name_bytes).hexdigest().startswith(expected_hashes[i]))

if solver.check() == sat:
    model = solver.model()
    print(model)
else:
    raise Exception("Constraints not satisfiable.")