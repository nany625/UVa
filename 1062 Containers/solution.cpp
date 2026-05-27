#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int cases = 0;
	string container;
	while(cin >> container && container[0] != 'e') {
	    vector<int> tail;
	    for(int i = 0; i < container.length(); ++i) {
	        int pos = lower_bound(tail.begin(), tail.end(), container[i]) - tail.begin();
	        if(pos == tail.size())
	            tail.push_back(container[i]);
	        else
	            tail[pos] = container[i];
	    }
	    cout << "Case " << ++cases << ": " << tail.size() << '\n';
	}
	return 0;
}
