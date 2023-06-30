package lab2;

public class Program {
    public static void main(String[] args){
        //Create Array2D
        final int SIZE = 5;
        int[][] grid = new int[5][5];
        for (int i=0; i < SIZE; i++){
            for (int j=0; j < SIZE; j++){
                grid[i][j] = i * SIZE + j + 1;
            }
        }

        //Output Example 1
        System.out.println("Output 1:");
        for (int i=0; i < SIZE; i++){
            for (int j=0; j < SIZE; j++){
                System.out.print(grid[j][i]+" ");
            }
            System.out.println();
        }

        //Output Example 2
        System.out.println("Output 2:");
        for (int i=0; i < SIZE; i++){
            for (int j=0; j < SIZE; j++){
                if (i%2 == 0)
                    System.out.print(grid[i][j] + " ");
                else
                    System.out.print(grid[i][SIZE-j-1] + " ");
            }
            System.out.println();
        }
    }
}
