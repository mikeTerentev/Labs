import java.io.EOFException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;

public class g {
    public static void main(String[] args) {
        try {
            PrintWriter out = new PrintWriter("style.out");

            Scanner in = new Scanner(new File("style.in"));

            int i = 0;
            int n = in.nextInt();
            int[] a = new int[n];
            for (int j = 0; j != n; ++j) {
                a[j] = in.nextInt();
            }
            a = mergeSort(a);
            n = in.nextInt();
            int[] b = new int[n];
            for (int j = 0; j != n; ++j) {
                b[j] = in.nextInt();
            }
            b = mergeSort(b);
            n = in.nextInt();
            int[] c = new int[n];
            for (int j = 0; j != n; ++j) {
                c[j] = in.nextInt();
            }
            c = mergeSort(c);
            n = in.nextInt();
            int[] d = new int[n];
            for (int j = 0; j != n; ++j) {
                d[j] = in.nextInt();
            }
            d = mergeSort(d);

            int mina = a[0], minb = b[0];
            int minc = c[0], mind = d[0];
            int min = Integer.MAX_VALUE;
            int y = 0, z = 0, j = 0;
            i = 0;


            while (i < a.length && j < b.length && y < c.length && z < d.length) {
                int x = abs(max(max(a[i], b[j]), max(c[y], d[z])) - min(min(a[i], b[j]), min(c[y], d[z])));
                if (x < min) {
                    mina = a[i];
                    minb = b[j];
                    minc = c[y];
                    mind = d[z];
                    min = x;
                }
                x = min(min(a[i], c[y]), min(b[j], d[z]));
                if (x == a[i]) {
                    i += 1;
                }
                if (x == b[j]) {
                    j += 1;
                }
                if (x == c[y]) {
                    y += 1;
                }
                if (x == d[z]) {
                    z += 1;
                }

            }

            out.write(String.valueOf(mina) + " " + String.valueOf(minb) + " " + String.valueOf(minc) + " " + String.valueOf(mind));
            in.close();
            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private static int[] merge(int[] x, int[] y) {
        int xl = x.length;
        int yl = y.length;
        int l = xl + yl;
        int[] res = new int[l];
        int i = 0, j = 0;
        while (i < xl || j < yl) {
            if (j == yl || i < xl && x[i] < y[j]) {
                res[i + j] = x[i];
                i++;
            } else {
                res[i + j] = y[j];
                j++;
            }
        }
        return res;
    }

    private static int[] mergeSort(int[] a) {
        int l = a.length;
        if (l < 2) return a;
        int mid = l / 2;
        return merge(mergeSort(Arrays.copyOfRange(a, 0, mid)), mergeSort(Arrays.copyOfRange(a, mid, l)));
    }

}

