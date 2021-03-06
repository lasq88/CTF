If you looked at the past revisions of the provided repo, you could see some revisions done by challenge author knif3.

`git log`

If you start to list the changes made in them with `git show` you will realize that every commit added one sign of the flag to the file "flag.txt" and removed the previous one:

![commits](https://github.com/lasq88/CTF/blob/main/ritsec2021/misc/revision/writeup/flag.PNG)

A simple bash script allowed us to fetch all the commit changes:

```bash
for i in 2a769ddc9f4bfdfcdce753068497ca251996f7db 2092ddb909befa6ceee7449e4ce9433ba8bc8d57 331c43d1166915dd6e10994d531de9f3d986d616 f23c83288b5f594a595aef47a7c5cb37213f31dd 764794b7567ee2b468eedba22d3bc2eed9795f52 577232034921096b3fe59d9826fbb42a31ba3f96 3abc63e80c3cb5fdb8d0d422b2013724ee675417 8aeb0759342ffafc84a812c0699e9ea8caa3fd36 fca179e4bc0b1621365278cb9562dd65c4df191c 48297e0c0b6c3d739944cc5cda73245e767ee4c7 6f621dba0a3c2cafc863f0acfbb291cac8cb26fa 50f69d69ece32e4217baf9d5581bbb53d313ddbb 9fe2c0ed9d9be950e1fe6a74d0b51039053d2b5a f108cdb5227a24fa75d9774fb572fd9f30996950 432c9eeaed907425ea7e0469c50fbe2ca298d243 d8ddbff68296aa033dea7635924c02b296e00e94 58e54d74610cce1c6c777e305bad39ace9d1b6c8 2a712b002849b5ee44c2a139f5f99df049327f87 6fcc88671072e484ae06ecae35d639e00c6a3c86 2e1c2e0cd405c5d3a3302b165705808d86e4966a a4ee01c27519aa2c160c167eb2ff569aa31582cf c410e16cbba03b29495a2f2d6b10081c701e628c 1b07dd891d41e082cfa28ebe48345d7970dfa3f8 82b7ac89d4ac53045fdd21d6ede02d4d6fc4cdab a2e1f5ba01aaa238d137e62270fb7f8ddf06e10a eae1814581c32f536abd349d7d2deed2965caa04 9d6d71417e4ef9241e72ce3f796df0242ebb71a8 184914866cb2536d7d3d22ef1e1a521df8e22086 53e3f77a3e21abe8ee7eca6d5bd69caf281b72d1 ebd4f62b0295d5e17af0cab3ad630028e4d13133 ee3d68b9b6e5330c67ad1b3dd93275258b849c0a 60f4e46c34647c9529da9e9e518b58b719adbe1b 8e8ce11ebb15f92f9de3aaacf87874bc4288447e 0f40e6ec4446279a8334f0f312f5ade439bf7f20 496362794582e85dd7b1db0cad5f20970f39e1fa 4a2893a847f5cf69aafd4f64379013635663156b b1a0dcb3a818e952c58f2758b5cd5896945826b2 68733d819366b78225df3525017876319b96b1a5;
do
    git show $i >> ../changes.txt;
done
```

And then it's a matter of simply putting a flag together with your favorite method (I simply used a regex search in sublime)
