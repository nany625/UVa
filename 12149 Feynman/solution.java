import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        int N;
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0)
    	    output.append(N * (N + 1) * ((N << 1) + 1) / 6).append('\n');
        System.out.print(output);
	}
}
