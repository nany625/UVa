import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int N = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(N-- > 0) {
		    st.nextToken();
		    long P = (long)st.nval, reverseP = reverse(P);
		    int count = 0;
		    do {
    	        ++count;
    	        P += reverseP;
    	        reverseP = reverse(P);
    	    } while(P != reverseP);
		    output.append(count).append(' ').append(P).append('\n');
		}
		System.out.print(output);
	}
	
	static long reverse(long n) {
        long result = 0;
        while(n > 0) {
            result = 10 * result + n % 10;
            n /= 10;
        }
        return result;
    }
}
