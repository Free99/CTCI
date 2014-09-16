
public class Image {

	public static int[][] rotate(int[][] image) {
		if (image == null || image.length == 0) return null;
		
		int len = image.length;
		
		int tmp;
		for (int i = 0; i < len; ++i) 
			for (int j = i; j < len; ++j) {
				tmp = image[i][j];
				image[i][j] = image[j][i];
				image[j][i] = tmp;
			}
		
		for (int i = 0; i < len / 2; ++i) 
			for (int j = 0; j < len; ++j) {
				tmp = image[i][j];
				image[i][j] = image[len-i-1][j];
				image[len-i-1][j] = tmp;		
			}
		
		return image;
	}
	
	private static void toString(int[][] image) {
		// TODO Auto-generated method stub
		int N= image.length;
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++){
				System.out.format("%3d", image[i][j]);
			//System.out.print(" ");	
			}
			System.out.println();
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		int[][] image = new int[][] {
		        {1, 2, 3, 4},
		        {5, 6, 7, 8},
		        {9, 10, 11, 12},
		        {13, 14, 15, 16}
		    };
		toString(image);
		image = rotate(image);
		toString(image);
	}
		
	
}
