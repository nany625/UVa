import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		int min = 1, max = 10;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int guess;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (guess = (int)st.nval) != 0) {
		    String resp = br.readLine();
		    switch(resp.charAt(4)) {
    		    case 'h':
                    max = Math.min(max, guess - 1);
                    break;
                case 'l':
                    min = Math.max(min, guess + 1);
                    break;
                case 't':
                    if(guess >= min && guess <= max)
                        output.append("Stan may be honest\n");
                    else
                        output.append("Stan is dishonest\n");
                    min = 1;
                    max = 10;
		    }
		}
		System.out.print(output);
	}
}
