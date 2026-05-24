#include <bits/stdc++.h>
using namespace std;

const int MAXV = 11;
const int INF = 1e9;
array<array<int, MAXV>, 1 << MAXV> dp;
array<array<int, MAXV>, MAXV> dist;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int scenarios;
    cin >> scenarios;
    while(scenarios--) {
        pair<int, int> start;
        cin >> start.first >> start.second;
        cin >> start.first >> start.second;
        int n;
        cin >> n;
        vector<pair<int, int>> beepers(++n);
        beepers[0] = start;
        for(int i = 1; i < n; ++i)
            cin >> beepers[i].first >> beepers[i].second;
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j)
                dist[i][j] = dist[j][i] = abs(beepers[i].first - beepers[j].first) + abs(beepers[i].second - beepers[j].second);
        }
        int FULL = 1 << n;
        for(int i = 0; i < FULL; ++i)
            fill(dp[i].begin(), dp[i].begin() + n, INF);
        dp[1][0] = 0;
        for(int mask = 1; mask < FULL; ++mask) {
            for(int u = 0; u < n; ++u) {
                if(mask & (1 << u)) {
                    for(int v = 0; v < n; ++v) {
                        if(!(mask & (1 << v))) {
                            int next = mask | (1 << v);
                            dp[next][v] = min(dp[next][v], dp[mask][u] + dist[u][v]);
                        }
                    }
                }
            }
        }
        int ans = INF;
        for(int i = 1; i < n; ++i)
            ans = min(ans, dp[FULL - 1][i] + dist[i][0]);
        cout << "The shortest path has length " << ans << '\n';
    }
    return 0;
}
