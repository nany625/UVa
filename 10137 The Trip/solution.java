import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
	    try {
	        StreamTokenizer st = new StreamTokenizer(System.in);
            int n;
            while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
                double[] expense = new double[n];
    		    int total = 0;
    		    for(int i = 0; i < n; ++i) {
    		        st.nextToken();
    		        expense[i] = Math.round(st.nval * 100);
    		        total += expense[i];
    		    }
    		    Arrays.sort(expense);
        	    int overpayCount = total % n, average = total / n;
        	    int[] exchange = new int[2];
    		    for(int i = 0; i < n - overpayCount; ++i) {
        	        if(expense[i] < average)
        	            exchange[0] += average - expense[i];
        	        else
        	            exchange[1] += expense[i] - average;
        	    }
        	    for(int i = n - overpayCount; i < n; ++i) {
        	        if(expense[i] < average + 1)
        	            exchange[0] += (average + 1) - expense[i];
        	        else
        	            exchange[1] += expense[i] - (average + 1);
        	    }
        	    System.out.printf("$%.2f%n", Math.min(exchange[0] / 100.0, exchange[1] / 100.0));
            }
	    } catch(IOException e) {}
	}
}
