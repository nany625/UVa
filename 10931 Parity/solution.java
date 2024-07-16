import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		int I;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (I = (int)st.nval) != 0) {
		    String binaryRep = Integer.toBinaryString(I);
    	    int len = binaryRep.length(), bitsSum = 0;
    	    for(int i = 0; i < len; ++i)
    	        bitsSum += binaryRep.charAt(i) - '0';
    	    output.append("The parity of " + binaryRep + " is " + bitsSum + " (mod 2).\n");
		}
		System.out.print(output);
	}
}