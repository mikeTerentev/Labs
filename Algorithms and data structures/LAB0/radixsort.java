import java.io.EOFException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class d {
    public static void main(String[] args) throws EOFException {
        try {
            PrintWriter out = new PrintWriter(new File("radixsort.out"));
            Scanner in = new Scanner(new File("radixsort.in"), "utf8");
            int i = 0;
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            String[] a = new String[n];
            int j = 0;
            while ( j <=n-1) {
                String[] x = in.nextLine().split("javaWhitespace");
                if (!x[0].isEmpty()) {
                    a[j] = x[0];
                    j++;
                }
            }
            a = radSort(a, k, m, n);
            for (i = 0; i != n; ++i) {
                out.write(a[i] + '\n');
            }
            in.close();
            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }


    private static String[] radSort(String[] a, int k, int m, int n) {
        int[] s = new int[27];
        String[][] cx = new String[27][n];
        int[] ptr = new int[27];
        int i = m - 1;
        int dgt=0;
        while (i >= m - k) {
            for (int j = 0; j != 27; j++) {
                s[j] = 0;
                ptr[j] = 0;
            }
            for (int j = 0; j != n; j++) {
                dgt = a[j].charAt(i) - 'a';
                cx[dgt][ptr[dgt]] = a[j];
                ptr[dgt]++;
            }
            int d = 0;
            for (int p = 0; p != 27; p++) {
                if (d == n) break;
                for (int ps = 0; ps != ptr[p]; ps++) {
                    a[d] = cx[p][ps];
                    d++;
                    if (d == n) break;
                }
            }
            --i;
        }
        return a;
    }
}
