**Description**: The aliens have learned of a new concept called "security by obscurity". Fortunately for us they think it is a great idea and not a description of a common mistake. We've intercepted some alien comms and think they are XORing flags with a single-byte key and hiding the result inside 9999 lines of random data, Can you find the flag?

**Stars**: 1/5

**Downloadable**:
output.txt - encrypted file

**Goal**: To decrypt the flag

**Solution**: A simple 1-byte XOR encryption can be easily decrypted with following CyberChef recipe, just paste the contents of output.txt file into the input field.

https://gchq.github.io/CyberChef/#recipe=From_Hex('Auto')XOR_Brute_Force(1,1000000,0,'Standard',false,true,false,'CHTB')Strings('Single%20byte',24,'Alphanumeric%20%2B%20punctuation%20(A)',false)