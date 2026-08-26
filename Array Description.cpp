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
    int n, m; cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vi> dp(n+1, vi(m+1));
    if (a[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[1][i] = 1;
        }
    }else {
        dp[1][a[0]] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (a[i-1] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j];
                if (j != 1) {
                    dp[i][j] = (dp[i][j]+dp[i-1][j-1])%MOD;
                }
                if (j != m) {
                    dp[i][j] = (dp[i][j]+dp[i-1][j+1])%MOD;
                }
            }
        }else {
            int j = a[i-1];
            dp[i][j] = dp[i-1][j];
            if (j != 1) {
                dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MOD;
            }
            if (j != m) {
                dp[i][j] = (dp[i][j]+dp[i-1][j+1])%MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans+dp[n][i])%MOD;
    }
    cout << ans << endl;
    return 0;
}
