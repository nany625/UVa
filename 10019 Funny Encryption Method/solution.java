import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
	    st.nextToken();
	    int T = (int)st.nval;
	    StringBuilder output = new StringBuilder();
	    while(T-- > 0) {
	        st.nextToken();
	        int N = (int)st.nval;
	        int temp = N, count = 0;
	        while(temp > 0) {
    	        count += temp & 1;
    	        temp >>= 1;
    	    }
    	    output.append(count).append(' ');
    	    count = 0;
    	    while(N > 0) {
    	        temp = N % 10;
    	        while(temp > 0) {
        	        count += temp & 1;
        	        temp >>= 1;
        	    }
        	    N /= 10;
    	    }
    	    output.append(count).append('\n');
	    }
        System.out.print(output);
	}
}
