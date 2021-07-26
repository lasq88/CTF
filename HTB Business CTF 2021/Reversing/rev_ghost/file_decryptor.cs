using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace HTB_Ghost_Ransomware_Decryptor
{
    class Program
    {

        public static void DecryptFile(string inputFile, string outputFile)
        {
                byte[] salt = new byte[32];
                byte[] pwd = { 37, 96, 79, 19, 14, 18, 66, 106, 92, 11, 85, 14, 109, 96, 94, 72, 120, 1, 95, 94, 19, 85, 77, 125, 87, 57, 85, 0, 100, 9, 50, 70, 118, 14, 93, 18 };

                FileStream fileStream = new FileStream(inputFile, FileMode.Open);
                FileStream output = new FileStream(outputFile, FileMode.Create);
                fileStream.Read(salt, 0, salt.Length);
                Rfc2898DeriveBytes pbkdf = new Rfc2898DeriveBytes(pwd, salt, 50000);
                RijndaelManaged aes = new RijndaelManaged();
                aes.KeySize = 256;
                aes.BlockSize = 128;
                aes.Key = pbkdf.GetBytes(aes.KeySize / 8);
                aes.IV = pbkdf.GetBytes(aes.BlockSize / 8);
                aes.Mode = CipherMode.CFB;
                aes.Padding = PaddingMode.PKCS7;
                aes.Padding = PaddingMode.ISO10126;
                    var decryptor = aes.CreateDecryptor();
                    using (var cryptStream = new CryptoStream(fileStream, decryptor, CryptoStreamMode.Read))
                    {
                        var buffer = new byte[1024];
                        var read = cryptStream.Read(buffer, 0, buffer.Length);
                        while (read > 0)
                        {
                            output.Write(buffer, 0, read);
                            read = cryptStream.Read(buffer, 0, buffer.Length);
                        }
                        cryptStream.CopyTo(output);
                        cryptStream.Flush();
                    }
        }
        static void Main(string[] args)
        {
            string f1 = @"D:\Documents\ctf\hackthebox business 2021\rev\rev_ghost\Confidential.pdf.ghost";
            string f2 = @"D:\Documents\ctf\hackthebox business 2021\rev\rev_ghost\Confidential.pdf";
            DecryptFile(f1, f2);
        }
    }
}