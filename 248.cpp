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
    usopen("248")
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vi> dp(n+1, vi(n+1, -1));
    int ans = -1;
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= n-l; i++) {
            int j = i+l-1;
            if (l == 1) {
                dp[i][j] = a[i];
            }
            for (int r = i+1; r <= j; r++) {
                if (dp[i][r-1]==dp[r][j]) {
                    dp[i][j] = max(dp[i][j], dp[i][r-1]+1);
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}
