import java.io.EOFException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class binary {
    public static void main(String[] args) throws EOFException {
        try {
            PrintWriter out = new PrintWriter(new File("binsearch.out"));
            Scanner in = new Scanner(new File("binsearch.in"), "utf8");
            int i = 0;
            int n = in.nextInt();
            int[] a = new int[n];
            while (i != n) {
                a[i] = in.nextInt();
                ++i;
            }
            int searchNum = in.nextInt();
            for (i = 0; i != searchNum; ++i) {
                int ths = in.nextInt();
                out.write(String.valueOf(binLeft(a, ths)) + " ");
                out.write(String.valueOf(binRight(a, ths)) + '\n');

            }


            in.close();
            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private static int binRight(int[] a, int box) {
        int left = -1;
        boolean flag = false;
        int right = a.length;
        while (left < right-1) {
            int middle = right + (left - right) / 2;
            if (a[middle] <= box) {
                left = middle;
            } else {
                right = middle;
            }
        }
        if(left==-1) return -1;
        if (a[left] != box) return -1;
        return left+1;
    }

    private static int binLeft(int[] a, int box) {
        int left = -1;
        int right = a.length;
        while (left < right-1) {
            int middle = right + (left - right) / 2;
            if (a[middle] < box) {
                left = middle;
            } else {
                right = middle;
            }
        }
        if(right==a.length) return  -1;
        if (a[right] != box) return -1;
        return right+1;
    }

}
