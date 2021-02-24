package sw;

import java.io.FileInputStream;
import java.util.Scanner;

public class Num8424 {
    static class Solution {
        private static int n;
        private static int cycleLength;
        private static int answer;

        public static void main(String args[]) throws Exception {
            System.setIn(new FileInputStream("src/sw/res/8424_input.txt"));

            Scanner sc = new Scanner(System.in);
            int T;
            T = sc.nextInt();

            for (int test_case = 1; test_case <= T; test_case++) {
                answer = 0;
                n = sc.nextInt();
                City[][] cities = new City[n][n];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cities[i][j] = new City(false);
                    }
                }
                for (int i = 0; i < n; i++) {
                    int row = sc.nextInt() - 1;
                    int column = sc.nextInt() - 1;
                    cities[row][column].connect();
                    cities[column][row].connect();
                }

                for (int startIndex = 0; startIndex < n; startIndex++) {
                    cycleLength = 0;
                    for (int targetIndex = 0; targetIndex < n; targetIndex++) {
                        if (cities[startIndex][targetIndex].isConnect && !cities[startIndex][targetIndex].isVisit) {
                            cycleLength++;
                            cities[startIndex][targetIndex].visit();
                            cities[targetIndex][startIndex].visit();
                            dfs(cities, startIndex, targetIndex);
                            if (answer != 0) {
                                break;
                            }
                            cycleLength--;
                            cities[startIndex][targetIndex].notVisit();
                            cities[targetIndex][startIndex].notVisit();
                        }
                    }
                    if (answer != 0) {
                        break;
                    }
                }

                System.out.println("#" + test_case + " " + answer);
            }
        }

        private static void dfs(City[][] cities, int start, int target) {
            if (start == target) {
                answer = cycleLength;
                return;
            }

            for (int i = 0; i < n; i++) {
                if (cities[target][i].isConnect && !cities[target][i].isVisit) {
                    cycleLength++;
                    cities[target][i].visit();
                    cities[i][target].visit();
                    dfs(cities, start, i);
                    if (answer != 0) {
                        break;
                    }
                    cycleLength--;
                    cities[target][i].notVisit();
                    cities[i][target].notVisit();
                }
            }
        }

        static class City {
            private boolean isConnect;
            private boolean isVisit;

            public City(boolean isConnect) {
                this.isConnect = isConnect;
            }

            public void visit() {
                this.isVisit = true;
            }

            public void notVisit() {
                this.isVisit = false;
            }

            public void connect() {
                this.isConnect = true;
            }
        }
    }
}
