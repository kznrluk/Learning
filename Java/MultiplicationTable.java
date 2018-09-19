class MultiplicationTable {
    public static void main(String args[]){
        int i,j;
        int[][] resultArray;
        resultArray = new int[9][9];
        
        i = 0; j = 0;
        while(i < 9){
            j = 0;
            while(j < 9){
                resultArray[i][j] = (i + 1) * (j + 1);
                // System.out.println(resultArray[i][j]);
                j = j + 1;
            }
            i = i + 1;
        }

        printTwoDimentionArray(resultArray);
    }

    public static void printTwoDimentionArray(int array[][]){
        int i, j;

        i = 0; j = 0;
        for(i = 0; i < array.length; i++){
            if(i == 0){
                outputColumnLavel(array);
            }
            for(j = 0; j < array[i].length; j++){
                if(j == 0) outputRowLavel(array[i][j]);
                System.out.print(String.format("%3d",array[i][j]) + " ");
            }
            System.out.print('\n');
        }
    }

    public static void outputColumnLavel(int array[][]){
        int i = 0;
        System.out.print("      ");
        for(i = 0; i < array.length; i++){
            System.out.print(String.format("%3d",array[0][i]) + " ");
        }
        System.out.print("\n----+-------------------------------------\n");
    }

    public static void outputRowLavel(int lavel){
        System.out.print(String.format("%3d | ", lavel));
    }
}