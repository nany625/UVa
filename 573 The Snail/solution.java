import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
	    float H;
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (H = (float)st.nval) != 0) {
    	    st.nextToken();
    	    float U = (float)st.nval;
    	    st.nextToken();
    	    float D = (float)st.nval;
    	    st.nextToken();
    	    float F = (float)st.nval;
    	    int day = 0;
    	    float curr = 0, lost = U * F / 100;
    	    do {
    	        ++day;
    	        curr += U;
    	        if(curr > H)
    	            break;
    	        curr -= D;
    	        U = U >= lost ? U - lost : 0;
    	    } while(curr >= 0);
    	    output.append(curr > H ? "success on day " : "failure on day ").append(day).append('\n');
		}
        System.out.print(output);
	}
}
