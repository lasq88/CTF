To be honest I had completely no idea what I was doing in this challenge. It was mostly google the error message + try solutions from stack overflow (so basically your day-to-day programming job ;D ). And it was also 30 minutes before the end of the CTF so I didn't have time to extend my git knowledge.

In the end, this is the stream of commands that looked to work for me:
  1. Init a new repository
  2. Try to fetch external repo (error)
  3. git repack
  4. set pack window to 0
  5. fetch external repo again (success)
  6. try to cat external object (error)
  7. try to fetch error object (error)
  8. git repack
  9. try to fetch the error branch object again (success)
  10. profit!

![commands](https://github.com/lasq88/CTF/blob/main/ritsec2021/misc/corruption/writeup/commands.PNG)

If you are wondering how I knew the hash of the external object it's because I had the verbose commands turned on when I did this exercise (another good stack overflow tip):

![verbose](https://github.com/lasq88/CTF/blob/main/ritsec2021/misc/corruption/writeup/fetch_verbose.PNG)
