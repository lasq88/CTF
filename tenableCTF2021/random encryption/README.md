So this was a fixed challenge after ogranizers leaked a flag in the first one and also didn't give seeds (apparently it was still solvable due to low number (10000) of initial seeds but took some bruteforcing).

For this one it was fairly easy. It has to do with how pseudorandomness works on deterministic machines such as our computers. It's only matter of chosing a secret seed (preferably based on some more random hardware events like mouse movements etc.) and then doing deterministic operations on this intial seed. So in short if you have initial seed and correct alghorithm you can reverse any "randomness". Therefore we have been given everything on a silver plate in this challenge. It was only matter of finding removed random numbers and then reversing encryption algorithm.

Correct solution is in sol.py file
