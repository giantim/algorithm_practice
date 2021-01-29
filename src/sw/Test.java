package sw;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Test {
    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>();
        arr.add(1);
        arr.add(2);
        arr.add(3);
        arr.add(4);
        arr.add(5);

        for (Iterator<Integer> iterator = arr.listIterator(); iterator.hasNext();) {
            Integer it = iterator.next();

            List<Integer> deleteIndexes = new ArrayList<>();
            for (int i = 0; i < arr.size(); i++) {
                Integer integer = arr.get(i);
                if (!integer.equals(it) && integer / it == 1) {
                    deleteIndexes.add(i);
                }
            }

            if (!deleteIndexes.isEmpty()) {
                deleteIndexes.forEach(arr::remove);
                iterator.remove();
            }
        }

        System.out.println("finish!");
    }
}
