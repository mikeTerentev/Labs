import java.io.EOFException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

import static java.util.Collections.swap;

public class case2 {
    public static void main(String[] args) {
        try {
            PrintWriter out = new PrintWriter(new File("priorityqueue.out"));
            Scanner in = new Scanner(new File("priorityqueue.in"));
            ArrayList<Integer> point = new ArrayList<Integer>();
            ArrayList<Integer> heap = new ArrayList<Integer>();
            int q = 0;
            while (in.hasNextLine()) {
                String x = in.nextLine();

                if (x.equals("extract-min")) {
                    if (heap.isEmpty()) {
                        out.write("*" + '\n');
                    } else {
                        int res = heap.get(0);
                        swap(point, 0, heap.size() - 1);
                        swap(heap, 0, heap.size() - 1);
                        heap.remove(heap.size() - 1);
                        out.write(String.valueOf(res) + '\n');
                    }
                }
                if (x.equals("push")) {
                    heap.add(in.nextInt());
                    point.add(heap.size() - 1);
                    int i = heap.size() - 1;
                    while (heap.get(i) < heap.get(i - 1) / 2) {     // i == 0 — мы в корне
                        swap(heap, i, (i - 1) / 2);
                        i = (i - 1) / 2;
                    }
                }
                if (x.equals("decrease-key")) {
                    int ch = in.nextInt();
                    int dnum = in.nextInt();
                    swap(heap, heap.size() - 1, point.get(ch));
                    heap.remove(heap.size() - 1);
                    if(heap.get(ch)>)

                }
                in.close();
                out.close();
            }
        } catch (FileNotFoundException e) {

        }
//shift down
        int i = heap.size() - 1;
        while (2 * i + 1 < heap.size()) {     // heapSize — количество элементов в куче
            int left = 2 * i + 1;             // left — левый сын
            int right = 2 * i + 2;            // right — правый сын
            int j = left;
            if (right < heap.size() && heap.get(right) < heap.get(left)) {
                j = right;
            }
            if (heap.get(i) <= heap.get(j))
                break;
            swap(heap, i, j);
            swap(point, i, j);
            i = j;
        }

    }
