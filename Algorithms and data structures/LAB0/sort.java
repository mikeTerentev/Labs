import java.io.EOFException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class sort {
    public static void main(String[] args) throws EOFException {
        try {
            Scanner in = new Scanner(new File("sort.in"), "utf8");
            int i = 0;
            int n = in.nextInt();
            int[] a = new int[n];
            while (in.hasNextInt()) {
                a[i] = in.nextInt();
                ++i;
            }
            PrintWriter out = new PrintWriter(new File("sort.out"));
            int[] res=new int[n];
            res=mergeSort(a);
            for(int s:res){out.write(String.valueOf(s)+" ");}
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
