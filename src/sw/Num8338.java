package sw;

import java.io.FileInputStream;
import java.util.*;

public class Num8338 {
    static class Solution {
        private static int answer;
        private static int max;
        private static int n;

        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/8338_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                answer = -1;

                n = sc.nextInt();
                int[] numbers = new int[n];
                for (int i = 0; i < n; i++) {
                    numbers[i] = sc.nextInt();
                }

                max = numbers[0];
                dfs(numbers, 1);
                System.out.println("#" + test_case + " " + answer);
            }
        }

        private static void dfs(int[] numbers, int index) {
            if (index == n) {
                answer = Math.max(answer, max);
                return;
            }

            for (int i = index; i < n; i++) {
                int right = numbers[i];
                max += right;
                dfs(numbers, i + 1);
                max -= right;

                max *= right;
                dfs(numbers, i + 1);
                if (right != 0) {
                    max /= right;
                }
            }
        }
    }
}
