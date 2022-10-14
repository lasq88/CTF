/* Decompiler 20ms, total 1315ms, lines 95 */
import java.util.Scanner;

public class Sekai {
   private static int length = (int)Math.pow(2.0D, 3.0D) - 2;

   public static void main(String[] var0) {
      Scanner var1 = new Scanner(System.in);
      System.out.print("Enter the flag: ");
      String var2 = var1.next();
      if (var2.length() != 43) {
         System.out.println("Oops, wrong flag!");
      } else {
         String var3 = var2.substring(0, length);
         String var4 = var2.substring(length, var2.length() - 1);
         String var5 = var2.substring(var2.length() - 1);
         if (var3.equals("SEKAI{") && var5.equals("}")) {
            assert var4.length() == length * length;

            if (solve(var4)) {
               System.out.println("Congratulations, you got the flag!");
            } else {
               System.out.println("Oops, wrong flag!");
            }
         } else {
            System.out.println("Oops, wrong flag!");
         }

      }
   }

   public static String encrypt(char[] var0, int var1) {
      char[] var2 = new char[length * 2];
      int var3 = length - 1;
      int var4 = length;

      int var5;
      for(var5 = 0; var5 < length * 2; ++var5) {
         var2[var5] = var0[var3--];
         var2[var5 + 1] = var0[var4++];
         ++var5;
      }

      for(var5 = 0; var5 < length * 2; ++var5) {
         var2[var5] ^= (char)var1;
      }

      return String.valueOf(var2);
   }

   public static char[] getArray(char[][] var0, int var1, int var2) {
      char[] var3 = new char[length * 2];
      int var4 = 0;

      int var5;
      for(var5 = 0; var5 < length; ++var5) {
         var3[var4] = var0[var1][var5];
         ++var4;
      }

      for(var5 = 0; var5 < length; ++var5) {
         var3[var4] = var0[var2][length - 1 - var5];
         ++var4;
      }

      return var3;
   }

   public static char[][] transform(char[] var0, int var1) {
      char[][] var2 = new char[var1][var1];

      for(int var3 = 0; var3 < var1 * var1; ++var3) {
         var2[var3 / var1][var3 % var1] = var0[var3];
      }

      return var2;
   }

   public static boolean solve(String var0) {
      char[][] var1 = transform(var0.toCharArray(), length);

      for(int var2 = 0; var2 <= length / 2; ++var2) {
         for(int var3 = 0; var3 < length - 2 * var2 - 1; ++var3) {
            char var4 = var1[var2][var2 + var3];
            var1[var2][var2 + var3] = var1[length - 1 - var2 - var3][var2];
            var1[length - 1 - var2 - var3][var2] = var1[length - 1 - var2][length - 1 - var2 - var3];
            var1[length - 1 - var2][length - 1 - var2 - var3] = var1[var2 + var3][length - 1 - var2];
            var1[var2 + var3][length - 1 - var2] = var4;
         }
      }

      String var10001 = encrypt(getArray(var1, 0, 5), 2);
      return "oz]{R]3l]]B#50es6O4tL23Etr3c10_F4TD2".equals(var10001 + encrypt(getArray(var1, 1, 4), 1) + encrypt(getArray(var1, 2, 3), 0));
   }
}