Interesting C# deobfuscation challenge. Original code implemented quite common obfuscation for C# malware where first stage binary decrypted and loaded into memory assembly code and then executed it.

Since we were in posession of source-code we could even slightly modify this code to drob second stage to disk. Most likely it wasn't even needed as probably flag could be simply taken from memory of this first stage code, but in all honesty I don't know how to do it with Visual Studio so I prefered to drop this file do disk and take a look at it in dnspy.

Modified first stage in Program.cs
```C#
using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Reflection;
using System.Linq;
namespace RAKSVwqLMTDsnB
{
    class pcuMyzvAxeBhINN
    {
        private static string zcfZIEShfvKnnsZ(string t, string k)
        {
            string bnugMUJGJayaT = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            string WgUWdaUGBFwgN = ""; Dictionary<char, char> OrnBLfjI = new Dictionary<char, char>();
            for (int i = 0; i < bnugMUJGJayaT.Length; ++i) { OrnBLfjI.Add(k[i], bnugMUJGJayaT[i]); }
            for (int i = 0; i < t.Length; ++i)
            {
                if ((t[i] >= 'A' && t[i] <= 'Z') || (t[i] >= 'a' && t[i] <= 'z')) { WgUWdaUGBFwgN += OrnBLfjI[t[i]]; }
                else { WgUWdaUGBFwgN += t[i]; }
            }
            return WgUWdaUGBFwgN;
        }

        public static bool ByteArrayToFile(string fileName, byte[] byteArray)
        {
            try
            {
                using (var fs = new FileStream(fileName, FileMode.Create, FileAccess.Write))
                {
                    fs.Write(byteArray, 0, byteArray.Length);
                    return true;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception caught in process: {0}", ex);
                return false;
            }
        }
        static void Main()
        {
            string pTIxJTjYJE = "CvsjeemeeeeXeeee//[...]"; // very long base64 - truncated
            string YKyumnAOcgLjvK = "lQwSYRxgfBHqNucMsVonkpaTiteDhbXzLPyEWImKAdjZFCOvJGrU";
            byte[] assembly = Convert.FromBase64String(zcfZIEShfvKnnsZ(pTIxJTjYJE, YKyumnAOcgLjvK));
            ByteArrayToFile("D:\\Documents\\ctf\\nahamcon\\alphabet\\assembly.dll", assembly);
            //Assembly smlpjtpFegEH = Assembly.Load(assembly);
            //MethodInfo nxLTRAWINyst = smlpjtpFegEH.EntryPoint;
            //nxLTRAWINyst.Invoke(smlpjtpFegEH.CreateInstance(nxLTRAWINyst.Name), null);
        }
    }
}
```

After looking at assembly.dll in dnspy, it initialized very big variable and then simply printed *"Not so fast!"*. It looked like flag is somewhere in initialized memory. Simple look at memory window confirmed this

![memory](https://github.com/lasq88/CTF/blob/main/nahamconctf2021/%5Bmisc%5D%20alphabet_soup/flag.PNG)
