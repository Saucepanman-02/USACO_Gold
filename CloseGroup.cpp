#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(file) do{freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);}while(0);
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define f first
#define s second
#define pdi pair<db, int>
#define ceil(n, r) (ll)((n+r-1)/r)
#define floor(n, r) (ll)(n/r);
#define pil pair<int, ll>

const int MOD = 1e9+7;

int main() {
    speedup
    int n, m; cin >> n >> m;
    vector<vi> g(n, vi(n));
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u][v] = g[v][u] = 1;
    }
    vector<int> dp((1<<n));
    dp[0] = 1;
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask&(1<<i)) {
                int submask = mask^(1<<i);
                for (int j = 0; j < n; j++) {
                    if (g[i][j]) {
                        if (mask&(1<<j)) {
                            submask ^= (1<<j);
                        }
                    }
                }
                if (submask == 0) {
                    dp[mask] = dp[mask] || dp[mask^(1<<i)];
                }
            }
        }
    }
    vector<int> calc((1<<n), 1e9);
    calc[0] = 0;
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int smask = mask; smask != 0; smask = (smask-1)&(mask)) {
            if (dp[smask]) {
                calc[mask] = min(calc[mask], 1+calc[mask^smask]);
            }
        }
    }
    cout << calc[(1<<n)-1] << '\n';
    return 0;
}
