# Python code for Pollard p-1
# factorization Method

# importing "math" for
# calculating GCD
import math

# importing "sympy" for
# checking prime
import sympy

    
# function to generate
# prime factors
def pollard(n):

    # defining base
    a = 2

    # defining exponent
    i = 2

    # iterate till a prime factor is obtained
    while(True):

        # recomputing a as required
        a = (a**i) % n

        # finding gcd of a-1 and n
        # using math function
        d = math.gcd((a-1), n)

        # check if factor obtained
        if (d > 1):

            #return the factor
            return d

            break

        # else increase exponent by one
        # for next round
        i += 1

# Driver code
n = 0x6c5f4a08d820579e606aeb3800d1602c53825167d01bd7c87f43041afdc82877c50bbcc7830a0bf8c718fc9016e4a9e73ff0dfe1edd38688acb6add89b2bd6264d61e2ce0c9b3b0813b46b0eb1fcfc56b9f7f072ba2e1e986e6420f8ad9063e10fa9bca464b23fcf0135f95dc11a89bfddf2e81572c196f4362ea551aee18b343638d9d703b234e788bff4ddc3e885da77c7940a0fa670ddc1604646871f0739199fa7fa01f9ed7d84fb9f0cc82965450e7c97153fec84ef8e10a7fceb37a90e847a012528c733070e9ab751215b13a7e2d485089c0c4d00b81dbab382ef7681c717c76c2b14ce6495ef121540653561c3dd519c5f6e2ead18e9d90f3769a029

# temporarily storing n
num = n

# list for storing prime factors
ans = []

# iterated till all prime factors
# are obtained
while(True):

    # function call
    d = pollard(num)

    # add obtained factor to list
    ans.append(d)

    # reduce n
    r = int(num/d)

    # check for prime using sympy
    if(sympy.isprime(r)):

        # both prime factors obtained
        ans.append(r)

        break

    # reduced n is not prime, so repeat
    else:

        num = r

# print the result
print("Prime factors of", n, "are", *ans)
