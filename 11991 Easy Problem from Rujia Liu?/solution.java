import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int n = (int)st.nval;
            st.nextToken();
            int m = (int)st.nval;
            HashMap<Integer, ArrayList<Integer>> pos = new HashMap<>();
            int index = 0;
            while(n-- > 0) {
                st.nextToken();
                int num = (int)st.nval;
                if(pos.containsKey(num))
                    pos.get(num).add(++index);
                else
                    pos.put(num, new ArrayList<>(Arrays.asList(++index)));
            }
            while(m-- > 0) {
                st.nextToken();
                int k = (int)st.nval;
                st.nextToken();
                int v = (int)st.nval;
                output.append(pos.get(v).size() >= k ? (int)pos.get(v).get(k - 1) : 0).append('\n');
            }
        }
        System.out.print(output);
	}
}
