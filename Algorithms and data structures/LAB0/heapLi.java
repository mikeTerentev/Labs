import java.io.EOFException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class heapLi {
    public static void main(String[] args)throws  EOFException {
        int[] array = new int[100000];
        try {
            Scanner in = new Scanner(new File("isheap.in"),"utf8");
            int i = 0;
            int n;
            boolean flag = true;
                n = in.nextInt();
            while (in.hasNextInt()) {
                array[i] = in.nextInt();
                i++;
            }
            for (i = 0; i != n; ++i) {
                if (2 * i + 1 < n) {
                    if (array[i] > array[2 * i + 1]) {
                        flag = false;
                        break;
                    }
                    if (2 * i + 2 < n) {
                        if (array[i] > array[2 * i + 2]) {
                            flag = false;
                            break;
                        }
                    }
                }
            }
            PrintWriter out = new PrintWriter(new File("isheap.out"));
            if (flag) {
                out.write("YES");
            } else {
                out.write("NO");
                ;
            } in.close();
              out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }
}
