#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(file) do{freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);}while(0);
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<ll>
#define vll vector<ll>
#define pll pair<ll, ll>
#define f first
#define s second
#define pdi pair<db, int>
#define ceil(n, r) (ll)((n+r-1)/r)
#define floor(n, r) (ll)(n/r);
#define pil pair<int, ll>

const int MOD = 1e9+7;

#define VC(c) (c == 'K'? 0: (c == 'E': 1? 2));

int main() {
    usopen("palpath")
    int n; cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<vector<ll>> dp(n, vll(n));
    vector<vll> ndp(n, vll(n));
    for (int i = 0; i < n; i++) {
        dp[i][i]=1;
    }
    for (int k = n-2; k >= 0; k--) {
        for (int r1 = 0; r1 < n; r1++) {
            for (int r2 = r1; r2 < n; r2++) {
                int c1 = k - r1;
                int c2 = 2*(n-1)-k-r2;
                if (c1 > c2) {
                    continue;
                }
                if (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n) {
                    continue;
                }
                if (grid[r1][c1] != grid[r2][c2]) {
                    continue;
                }
                ll cur = 0;
                if (c1 < n-1 && c2 > 0 && grid[r1][c1+1] == grid[r2][c2-1]) {
                    cur += dp[r1][r2];
                }
                if (c1 < n-1 && r2 > 0 && grid[r1][c1+1] == grid[r2-1][c2]) {
                    cur += dp[r1][r2-1];
                }
                if (r1 < n-1 && c2 > 0 && grid[r1+1][c1] == grid[r2][c2-1]) {
                    cur += dp[r1+1][r2];
                }
                if (r1 < n-1 && r2 > 0 && grid[r1+1][c1] == grid[r2-1][c2]) {
                    cur += dp[r1+1][r2-1];
                }
                ndp[r1][r2] = cur%MOD;
            }
        }
        dp = ndp;
    }
    cout << dp[0][n-1] << '\n';
    return 0;
}
