
public class reverse {
	public static void swap(char[] st, int i, int j) {
		char temp;
		temp = st[i];
		st[i] = st[j];
		st[j] = temp;
	}
	
	public static String reverseByStringBuffer(String s) {
		StringBuffer st = new StringBuffer(s);
		st.reverse();
		return st.toString();
	}
	
	public static String reverseBychar(String s) {
		char[] st = s.toCharArray();
		int front = 0, tail = st.length - 1;
		while (front < tail) {
			swap(st, front, tail);
			front++;
			tail--;
		}
		return s.valueOf(st);
	}
	
	public static void main (String[] args) {
		  String s= "reverse words here.";
		  System.out.println(s+"----reverse to---->"+reverseByStringBuffer(s));
		  System.out.println(s+"----reverse to---->"+reverseBychar(s));
	  }
}
