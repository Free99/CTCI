public class rotateimage{
    public static void main(String[] args)
    {
        int[][] matrix ={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16 ,17 ,18, 19, 20},{21 ,22 ,23 ,24, 25}};
        matrix = rotateimage(matrix);
        for(int i = 0; i < matrix.length; i++)
        {
            System.out.println();
            for(int j = 0; j < matrix[0].length; j++)
            {
                System.out.print(matrix[i][j] + ",");
            }
        }
    }
    
    public static int[][] rotateimage(int[][] matrix)
    {
        if(matrix == null)
            return null;
        int temp = 0;
        
        int n = matrix.length;
        if(n <= 1)
            return matrix;
            
        for(int i = 0; i < n / 2; i++)
            for(int j = 0; j <= n / 2; j++)
            {
                if(n % 2 == 0 && j == n / 2)
                    continue;
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        
        return matrix;
    }
}
