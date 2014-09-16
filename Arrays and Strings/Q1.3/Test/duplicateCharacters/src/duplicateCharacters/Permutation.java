package duplicateCharacters;

public class Permutation {
	public static boolean isPermutation(String s1, String s2) {
		if (s1 == "" || s2 == "") return false;
		if (s1.length() != s2.length()) return false;
		
		int len = s1.length();
		int[] c = new int[256];
		for (int i = 0; i < len; ++i) {
			c[s1.charAt(i)] += 1;
			c[s2.charAt(i)] -= 1;
		}
		for (int i : c) {
			if (i != 0) return false;
		}
		return true;
	}
	
	public static void main(String[] args) {
		String s1 = "Tianshan";
		String s2 = "Tianssan";
		System.out.println(isPermutation(s1, s2));
	}
}
