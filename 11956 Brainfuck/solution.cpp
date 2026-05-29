#include <bits/stdc++.h>
using namespace std;

array<unsigned char, 100>  LED;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i) {
	    fill(LED.begin(), LED.end(), 0);
	    string command;
	    cin >> command;
	    int pos = 0;
	    for(int j = 0; j < command.length(); ++j) {
	        if(command[j] == '>')
	            pos = (pos + 1) % 100;
	        else if(command[j] == '<')
	            pos = (pos + 99) % 100;
	        else if(command[j] == '+')
	            ++LED[pos];
	        else if(command[j] == '-')
	            --LED[pos];
	    }
	    cout << "Case " << i << ":";
	    for(int j = 0; j < 100; ++j)
	        cout << ' ' << setfill('0') << setw(2) << hex << uppercase << (int)LED[j];
	    cout << '\n' << dec;
	}
	return 0;
}
