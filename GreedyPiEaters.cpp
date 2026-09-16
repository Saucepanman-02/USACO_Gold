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
    speedup
    usopen("pieaters")
    int n, m; cin >> n >> m;
    vector<vector<vll>> pcal(n, vector<vll>(n, vll(n)));
    for (int i = 0; i < m; i++) {
        int w, l, r; cin >> w >> l >> r;
        l--, r--;
        for (int j = l; j <= r; j++)
            pcal[l][r][j] = w;
    }
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l <= n-len; l++) {
            int r = l+len-1;
            for (int k = l; k <= r; k++) {
                if (l != k) {
                    pcal[l][r][k] = max(pcal[l+1][r][k], pcal[l][r][k]);
                }
                if (r!=k) {
                    pcal[l][r][k] = max(pcal[l][r-1][k], pcal[l][r][k]);
                }
            }
        }
    }
    vector<vll> dp(n+1, vll(n+1));
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= n-l; i++) {
            int j = i+l-1;
            for (int r = i; r <= j; r++) {
                dp[i][j] = max(dp[i][r]+dp[r+1][j], dp[i][j]);
                dp[i][j] = max((r > 0? dp[i][r-1]: 0) + dp[r+1][j]+pcal[i][j][r], dp[i][j]);
            }
            //cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }
    cout << dp[0][n-1] << '\n';
    return 0;
}
