There were 6 low-point (25) "introduction" challenges to Spring MVC application. We have been given a source code with removed flags so it was only matter of reading one MVC controller code and then making some curl requests:

![Controller code](https://github.com/lasq88/CTF/blob/main/tenableCTF2021/springmvc/controller.png)

> 1. curl "http://challenges.ctfd.io:30542/main"
> 2. curl -X POST "http://challenges.ctfd.io:30542/main"
> 3. curl -d "magicWord=please" -X POST "http://challenges.ctfd.io:30542/main"
> 4. curl -H "Content-Type: application/json" -X POST "http://challenges.ctfd.io:30542/main"
> 5. curl -X OPTIONS "http://challenges.ctfd.io:30542/main"
> 6. curl -H "Magic-Word: please" -X GET "http://challenges.ctfd.io:30542/main"

Then there was one 50p "Hidden in plain sight challenge" that honestly wasn't any harder than previous ones, you just need to look in a different part of the code. Actually hello.html file revealed what you need to do is just set your name as "please" but to use "/" instead of "/main" (look for last picture in challenge 8 to see why):

> 7 .curl "http://challenges.ctfd.io:30542/?name=please"

8. Last flag was for 75 points and it named "sessionable" so most likely had something to do with session variables. Actually it was also pretty easy and you could do it completly from your browser. So first you needed to navigate to `http://challenges.ctfd.io:30542/other?name=admin` to set your name as admin, and then just go `http://challenges.ctfd.io:30542/` to get a flag.

It was based on the fact that OtherController set realName session variable nased on the name provided, and main paged checked it to give you flag:

![OtherController code](https://github.com/lasq88/CTF/blob/main/tenableCTF2021/springmvc/other_controller.png)

![Hello](https://github.com/lasq88/CTF/blob/main/tenableCTF2021/springmvc/hello.png)
