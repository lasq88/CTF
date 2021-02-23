In the challenge description there was a link to page that only displayed something like this:
>[235,"1F"],cE4g5bWZtYCuovEgYSO1

And when you put the second part (long base64-like string) into page attribute in url it took you to another very similar page only with different values, and you could go to another page, and another and so on. It was obvious it requires some automation.

After playing a while with it, trying to guess what values between brackets mean, it struck me that second value is most likely a byte, and first value looks just like a position. This was a good clue, so it was only a matter of writing correct script in python to automate http requests, parse response and put it in some data structure and in the end write it to file. In the end after making 1500+ http requests we ended up with valid PNG file.

Solution is available in rabbit.py
