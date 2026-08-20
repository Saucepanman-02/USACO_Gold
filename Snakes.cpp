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
    usopen("snakes")
    int n, k; cin >> n >> k; k++;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vi> dp(n+1, vi(k+1, 1e9));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int sum = 0, mx = 0;
            for (int r = i; r > 0; r--) {
                sum += a[r-1];
                mx = max(mx, a[r-1]);
                dp[i][j] = min(dp[i][j], mx*(i-r+1)-sum+dp[r-1][j-1]);
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= k; i++) {
        ans = min(dp[n][i], ans);
    }
    cout << ans << endl;
    return 0;
}
