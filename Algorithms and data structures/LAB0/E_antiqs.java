import java.io.EOFException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.io.ArrayList;
import static java.lang.Math.abs;
import static java.lang.Math.min;

public class E {
    public static void main(String[] args) throws EOFException {
        try {
            PrintWriter out = new PrintWriter(new File("antiqs.out"));
            ArrayList<String> places;
            places = new ArrayList<String>();
            Scanner in = new Scanner(new File("antiqs.in"));
            int i = 0;
            int n = in.nextInt();
            int mem[] = new int[n];
            for (i = 0; i != n; ++i) {
                mem[i] = i+1;
            }
            antiQsort(mem);
            for (i = 0; i != n; ++i) {
                out.write(String.valueOf(mem[i]+" "));
            }
            in.close();
            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    static void antiQsort(int[] mem) {
        for (int i = 0; i != mem.length; ++i) {
            int x = mem[i / 2];
            mem[i / 2] = mem[i];
            mem[i] = x;
        }
    }
}