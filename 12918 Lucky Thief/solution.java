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
            int n = (int)st.nval;
            st.nextToken();
		    output.append((long)(((int)st.nval << 1) - n - 1) * n >> 1).append('\n');
    	}
        System.out.print(output);
	}
}
