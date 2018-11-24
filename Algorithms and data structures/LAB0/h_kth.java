import java.io.EOFException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

import static java.util.Collections.swap;

public class h {
    public static void main(String[] args) throws EOFException {
        try {
            PrintWriter out = new PrintWriter(new File("kth.out"));
            Scanner in = new Scanner(new File("kth.in"));
            int n = in.nextInt();
            int[] a = new int[n];

            int i = 0;
            int k = in.nextInt() - 1;
            int Z = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            a[0] = in.nextInt();
            a[1] = in.nextInt();

            for (i = 2; i != n; ++i) {
                int mie2m = Z * a[i - 2];
                int mie1m = b * a[i - 1];
                a[i] = mie1m + mie2m + c;
            }
            for (int l = 0, r = n - 1; ; ) {

                if (r <= l + 1) {
                    if (a[r] < a[l] && r == l + 1) {
                        int x = a[l];
                        a[l] = a[r];
                        a[r] = x;
                    }
                    out.write(String.valueOf(a[k]));
                    in.close();
                    out.close();
                    break;
                }
                int mid = (l + r) >> 1;
                {
                    int x = a[mid];
                    a[mid] = a[l + 1];
                    a[l + 1] = x;
                }
                if (a[l] > a[r]) {
                    int x = a[l];
                    a[l] = a[r];
                    a[r] = x;
                }
                if (a[l + 1] > a[r]) {
                    int x = a[l + 1];
                    a[l + 1] = a[r];
                    a[r] = x;
                }
                if (a[l] > a[l + 1]) {
                    int x = a[l];
                    a[l] = a[l + 1];
                    a[l + 1] = x;
                }
                int j = r;
                i = l + 1;
                int now = a[l + 1];
                for (; ; ) {
                    while (a[++i] < now) ;
                    while (a[--j] > now) ;
                    if (i > j)
                        break;
                    int x = a[i];
                    a[i] = a[j];
                    a[j] = x;
                }
                a[l + 1] = a[j];
                a[j] = now;
                if (j >= k)
                    r = j - 1;
                if (j <= k)
                    l = i;
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}

/*import java.io.EOFException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

import static java.util.Collections.swap;

public class h {
    public static void main(String[] args) throws EOFException {
        try {
            PrintWriter out = new PrintWriter(new File("kth.out"));
            Scanner in = new Scanner(new File("kth.in"));
            int n = in.nextInt();
            ArrayList<Integer> a = new ArrayList<Integer>(n);
            int i = 0;

            int k = in.nextInt() - 1;
            int Z = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            a.add(in.nextInt());
            a.add(in.nextInt());

            for (i = 2; i != n; ++i) {
                int mie2m = Z * a.get(i - 2);
                int mie1m = b * a.get(i - 1);
                a.add(mie1m + mie2m + c);
            }
            i = 0;
            for (int l = 0, r = n - 1; ; ) {

                if (r <= l + 1) {
                    if (a.get(r) < a.get(l) && r == l + 1)
                        swap(a, l, r);
                    out.write(String.valueOf(a.get(k)));
                    in.close();
                    out.close();
                    break;
                }
                int mid = (l + r) >> 1;
                swap(a, mid, l + 1);
                if (a.get(l) > a.get(r))
                    swap(a, l, r);
                if (a.get(l + 1) > a.get(r))
                    swap(a, l + 1, r);
                if (a.get(l) > a.get(l + 1))
                    swap(a, l + 1, l);
                int j = r;
                i = l + 1;
                int now = a.get(l + 1);
                for (; ; ) {
                    while (a.get(++i) < now) ;
                    while (a.get(--j) > now) ;
                    if (i > j)
                        break;
                    swap(a, i, j);
                }
                a.set(l + 1, a.get(j));
                a.set(j, now);
                if (j >= k)
                    r = j - 1;
                if (j <= k)
                    l = i;
            }


        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

}*/

