import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            int circle = (int)Math.ceil(Math.sqrt(N)), corner = 1 + circle * (circle - 1);
            if((circle & 1) == 1) {
                if(N < corner) 
                    output.append(circle).append(' ').append(circle - (corner - N)).append('\n');
                else
                    output.append(circle - (N - corner)).append(' ').append(circle).append('\n');
            } else {
    			if(N < corner)
                    output.append(circle - (corner - N)).append(' ').append(circle).append('\n');
                else
                    output.append(circle).append(' ').append(circle - (N - corner)).append('\n');
    		}
        }
        System.out.print(output);
	}
}
