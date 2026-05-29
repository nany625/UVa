#include <bits/stdc++.h>
using namespace std;

struct Guard {
    int x1, y1, x2, y2;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i) {
	    Guard g1, g2;
	    cin >> g1.x1 >> g1.y1 >> g1.x2 >> g1.y2;
	    cin >> g2.x1 >> g2.y1 >> g2.x2 >> g2.y2;
	    if(g1.x1 > g2.x1)
	        swap(g1, g2);
	    int weak = (g1.x2 - g1.x1) * (g1.y2 - g1.y1) + (g2.x2 - g2.x1) * (g2.y2 - g2.y1);
	    if(g2.x1 >= g1.x2 || g2.y2 <= g1.y1 || g2.y1 >= g1.y2)
	        cout << "Night " << i << ": 0 " << weak << ' ' << 10000 - weak << '\n';
	    else {
	        int strong = (min(g1.x2, g2.x2) - g2.x1) * (min(g1.y2, g2.y2) - max(g1.y1, g2.y1));
	        weak -= strong << 1;
	        cout << "Night " << i << ": " << strong << ' ' << weak << ' ' << 10000 - strong - weak << '\n';
	    }
	}
	return 0;
}
