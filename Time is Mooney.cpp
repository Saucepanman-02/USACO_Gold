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

int main() {
    usopen("time")
    int n, m; ll c; cin >> n >> m >> c;
    vi coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    vector<vi> g(n, vi());
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[v].push_back(u);
    }
    int MAXT = 1e3+10;
    vector<vll> dp(MAXT+1, vll(n, -1));
    dp[0][0] = 0;
    ll ans = 0;
    for (int t = 1; t <= MAXT; t++) {
        for (int u = 0; u < n; u++) {

            for (const int v: g[u]) {
                if (dp[t-1][v] != -1) {
                    dp[t][u] = max(dp[t][u], dp[t-1][v]+coin[u]-c*(2*t-1));
                }
            }
        }
        ans = max(ans, dp[t][0]);
    }
    cout << ans << endl;
    return 0;
}
