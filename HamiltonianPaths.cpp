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
    vector<vi> g(n);
    vector<vi> dp((1<<(n-1)), vi(n-1));
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[v].push_back(u);
        if (u == 0 && v != 0)
            dp[(1<<(v-1))][v-1]++;
    }
    for (int mask = 1; mask < (1<<(n-1)); mask++) {
        for (int j = 0; j < n-1; j++) {
            if (mask&(1<<j)) {
                for (int k: g[j+1]) {
                    if (mask&(1<<(k-1))) {
                        dp[mask][j] += dp[mask^(1<<j)][k-1];
                        dp[mask][j] %= MOD;
                    }
                }
            }
        }
    }
    cout << (dp[(1<<(n-1))-1][n-2]+MOD)%MOD << '\n';
    return 0;
}
