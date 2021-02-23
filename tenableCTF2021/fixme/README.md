Actually the intended solution was to remove few junk files before each IDAT chunk, so it was best to have python script for this (or do it manually in hexeditor).
I've ended up repairing just first chunk, then I opened file in Windows Photo Browser and though file was still corrupted, flag was already visible (see fixme_mod.png)

Few links/tools I used:

http://libpng.org/pub/png/apps/pngcheck.html
https://gist.github.com/sbp/3084622
https://github.com/kibotrel/PNG-Parser
https://github.com/Hedroed/png-parser
