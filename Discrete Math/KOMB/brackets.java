import java.io.EOFException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.ArrayList;

public class parirition {

    public void generation(int opeS, int cloS, ArrayList<Character> res, int n) {
        int max = 2 * n;
        if (cloS + opeS == max) {
            for (int i = 0; i < cloS + opeS; i++) {
                PrintWriter out = new PrintWriter(new File("brackets.out");
                out.write(res.get(i));
            }
            if(opeS<n) {
                generation(n, opeS + 1, cloS, res);
            }
            if (opeS > cloS) {
                res.get(cloS + opeS-1)=')';
                generation(n, opeS, cloS + 1, res)
            }
        }

    public static void main(String[] args) throws EOFException {
        try {
            Scanner in = new Scanner(new File("brackets.in"), "utf8");
            PrintWriter out = new PrintWriter(new File("brackets.out");

            int n = in.nextInt();


        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}