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
            int e = (int)st.nval;
            st.nextToken();
            int f = (int)st.nval;
            st.nextToken();
            int c = (int)st.nval;
            double ans = (e + f - c) / (c - 1.0);
            output.append(ans >= 0 ? (int)ans + 1 : 0).append('\n');
        }
        System.out.print(output);
	}
}
