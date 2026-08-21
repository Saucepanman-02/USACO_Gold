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

const int MOD = 1e9+9;

int main() {
    usopen("team")
    int n, m, k; cin >> n >> m >> k;
    vll a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }
    vector<vector<ll>> dp(n+1, vll(m+1, 1));
    vector<vll> ndp(n+1, vll(m+1, 0));
    for (int r = 1; r <= k; r++) {
        for (int i = 1; i <= n ; i++) {
            for (int j = 1; j <= m; j++) {
                ndp[i][j] = ((ndp[i-1][j]+ndp[i][j-1])%MOD-ndp[i-1][j-1])%MOD;
                if (a[i-1] > b[j-1]) {
                    ndp[i][j] = (ndp[i][j]+dp[i-1][j-1])%MOD;
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = ndp[i][j];
            }
        }
    }
    cout << (dp[n][m]+MOD)%MOD << endl;
    return 0;
}
