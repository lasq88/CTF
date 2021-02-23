Ok so I struggled with this a lot. It was the first time for me doing game hacking in practice. I had some exposure to the theory and tools fortunately due to my involvment in reverse-enginnering community, but didn't have any practical experience.

It took me long time to correctly install and setup Cheat Engine, then to realize Unity game code reversing is not as simple as looking at it in dnspy because it is packed by IL2CPP tool. Fortunately there are existing tools to deal with this, as well as Cheat Engine have built-in mono dissecting capabilities (which I realized quite late into CTF).

In the end I managed to solve only 2 out of 4 challenges here. Though I probably should have solved 4 easily with my knowledge of in-game structures if I only payed more attention to game UI :(

1. First challenge was to run corridor race in less than 5 seconds. I think it was bugged because it gave me flag just by running from start to finish without using any hacking gear. And it definitely took more than 5 seconds. Anyway the intended solution was to modify timer variable in game memory.

2. Second challenge wasn't solved by anyone and organizers didn't release a solution yet (apparently they are using same challenge for a different ongoing event). A lot of people managed to mess with their coordinates but this didn't sync with server-side point of view so was client-only and was not enough to solve it. According to hints by organizer, intended solution had to do with modifing respawn point after death.

3. Third challenge was to see hidden QR code in the ocean. You could do this by modifying CameraMMO2D zoom property in game memory. You could find it using cheat engine built-in mono dissector:

![CameraMMO2D structure](https://github.com/lasq88/CTF/blob/main/tenableCTF2021/pwntown/writeup%20qr/change_zoom.PNG)

This is how it looked after the change:

![QR code in the ocean](https://github.com/lasq88/CTF/blob/main/tenableCTF2021/pwntown/writeup%20qr/zoomed_out.png)

4. This was a frustrating one. In the end it turned out easier than I expected. The goal was to finish quest from Questy McQuest Giver but he asked you to kill 31337 saplings (tell me about grinder MMOs huh?) I had few approaches to this. Before organizers released a hint I tried (probably same as everyone) to somehow modify game memory to make game believe I finished the quest but it was client-only and didn't work:

![Quest completed](https://github.com/lasq88/CTF/blob/main/tenableCTF2021/pwntown/writeup%20quest%20(not%20done)/quest_complete_try.png)

After no one managed to solve this challenge in the first 2 days, organizers released a hint to try to obtain "scroll of killing" in a different way. My first take was to modify game memory to put in the NPC shop and buy it. I found KillQuest structure and found there pointer to ScriptableItem structure of Scroll of Killing. Then it was matter of putting it in the ScriptableItems list in NpcTrading structure. It worked quite well from client-side but unfortunatelly only thing client passed to server was slot id of shop and server checked for correct item on it's side. So this was a dead end.

![Scroll of killing in shop](https://github.com/lasq88/CTF/blob/main/tenableCTF2021/pwntown/writeup%20quest%20(not%20done)/buy_try.png)

Later I tried to spawn it from mobs, because I saw in dnSpy that when drop is being picked up from mob it actually passes a ScriptableObject pointer to Item creator so I hoped I can cheat server to create scroll of killing instead of let's say mana potion. Unfortunately Cheat Engine had some issues parsing Item structure and I had to try to correct it manually crashing the game client multiple times in the process. It was annoying cause after every crash I had to search again for my structures (I don't know of any automated way of doing this in Cheat Engine) and it took some time so after n-th crash I gave up.

In the end solution was easier than I expected (given there was only around dozen solutions in the end). Apparently there was a second shop in game menu on the bottom when you could buy scroll of killing. It was only a matter of editing number of coins in game memory and there was no servers-de check on this one so you could simply buy it. It should be relatively easy with structers I already had located, but unfortunately I have never found second item shop. Should have pay more attention to game menu next tiem I guess.
