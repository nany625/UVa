import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    long B = (long)st.nval;
    	    st.nextToken();
    	    int P = (int)st.nval;
    	    st.nextToken();
    	    int M = (int)st.nval;
    	    output.append(bigMod(B, P, M)).append('\n');
    	}
        System.out.print(output);
	}
	
	static int bigMod(long B, int P, int M) {
        if(P == 0)
            return 1 % M;
        if(P == 1)
            return (int)(B % M);
        int temp = bigMod(B, P >> 1, M);
        if((P & 1) == 1)
            return (int)(temp * temp * B % M);
        return temp * temp % M;
    }
}
