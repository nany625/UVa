#include <bits/stdc++.h>
using namespace std;

array<array<int, 50>, 100> leftPan, rightPan;
array<int, 100> P;
array<string, 100> result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int M;
	cin >> M;
	while(M--) {
	    int N, K;
	    cin >> N >> K;
	    for(int i = 0; i < K; ++i) {
	        cin >> P[i];
	        for(int j = 0; j < P[i]; ++j)
	            cin >> leftPan[i][j];
	        for(int j = 0; j < P[i]; ++j)
	            cin >> rightPan[i][j];
	        cin >> result[i];
	    }
	    int ans = 0;
	    for(int i = 1; i <= N; ++i) {
	        bool isLight = true;
	        for(int j = 0; j < K && isLight; ++j) {
	            int leftW = P[j];
	            for(int k = 0; k < P[j]; ++k) {
	                if(leftPan[j][k] == i) {
	                    --leftW;
	                    break;
	                }
	            }
	            int rightW = P[j];
	            for(int k = 0; k < P[j]; ++k) {
	                if(rightPan[j][k] == i) {
	                    --rightW;
	                    break;
	                }
	            }
	            if((leftW == rightW && result[j][0] != '=') || (leftW < rightW && result[j][0] != '<') || (leftW > rightW && result[j][0] != '>'))
	                isLight = false;
	        }
	        bool isHeavy = true;
	        for(int j = 0; j < K && isHeavy; ++j) {
	            int leftW = P[j];
	            for(int k = 0; k < P[j]; ++k) {
	                if(leftPan[j][k] == i) {
	                    ++leftW;
	                    break;
	                }
	            }
	            int rightW = P[j];
	            for(int k = 0; k < P[j]; ++k) {
	                if(rightPan[j][k] == i) {
	                    ++rightW;
	                    break;
	                }
	            }
	            if((leftW == rightW && result[j][0] != '=') || (leftW < rightW && result[j][0] != '<') || (leftW > rightW && result[j][0] != '>'))
	                isHeavy = false;
	        }
	        if(isLight || isHeavy) {
	            if(ans == 0)
	                ans = i;
	            else {
	                ans = 0;
	                break;
	            }
	        }
	    }
	    cout << ans << '\n';
	    if(M)
	        cout << '\n';
	}
	return 0;
}
