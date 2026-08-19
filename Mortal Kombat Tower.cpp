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


int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << a[0] << '\n';
            continue;
        }
        vector<vi> dp(n+1, vi(2, 1e9));
        dp[1][1] = (a[0]);
        dp[2][1] = (a[0]+a[1]);
        dp[2][0] = dp[1][1];
        for (int i = 3; i <= n; i++) {
            dp[i][1] = min(dp[i-1][0]+a[i-1], dp[i-2][0]+a[i-1]+a[i-2]);
            dp[i][0] = min(dp[i-1][1], dp[i-2][1]);
        }
        cout << min(dp[n][1], dp[n][0]) << '\n';
    }
    return 0;
}
