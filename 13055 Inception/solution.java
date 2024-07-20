import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int n = (int)st.nval;
		ArrayList<String> dreams = new ArrayList<>();
		StringBuilder output = new StringBuilder();
		while(n-- > 0) {
		    st.nextToken();
		    switch(st.sval.charAt(0)) {
		        case 'S':
                    st.nextToken();
                    dreams.add(st.sval);
                    break;
                case 'K':
                    if(!dreams.isEmpty())
                        dreams.remove(dreams.size() - 1);
                    break;
                case 'T':
                    if(!dreams.isEmpty())
                        output.append(dreams.get(dreams.size() - 1) + "\n");
                    else
                        output.append("Not in a dream\n");
		    }
		}
		System.out.print(output);
	}
}