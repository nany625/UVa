#include <bits/stdc++.h>
using namespace std;

array<int, 8> dRow = {0, 1, 0, -1, 1, 1, -1, -1}, dCol = {1, 0, -1, 0, 1, -1, -1, 1};
array<string, 100> field;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int x = 0, n, m;
	while(cin >> n >> m && n != 0) {
		if(x)
			cout << '\n';
		cout << "Field #" << ++x << ":\n";
		for(int i = 0; i < n; ++i)
			cin >> field[i];
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(field[i][j] == '.') {
					field[i][j] = '0';
					for(int dir = 0; dir < 8; ++dir) {
						int nRow = i + dRow[dir];
						int nCol = j + dCol[dir];
						if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && field[nRow][nCol] == '*')
							++field[i][j];
					}
				}
			}
		}
		for(int i = 0; i < n; ++i)
			cout << field[i] << '\n';
	}
	return 0;
}
