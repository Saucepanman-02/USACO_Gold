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

ll memo[505][505];

const ll MOD = 1e9+7;

ll nCr(int n, int r) {
    if (n < 0 || r < 0) {
        return 0;
    }
    if (r > n) {
        return 0;
    }
    if (n == r || r ==0) {
        return 1;
    }
    if (memo[n][r] != -2) {
        return memo[n][r];
    }
    return (memo[n][r] = (nCr(n-1, r-1)+nCr(n-1, r))%MOD);
}

int main() {
    speedup
    int n, k; cin >> n >> k;
    vi a(k+2);
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    a[k+1] = n+1;
    vector<vi> dp(k+2, vi(k+2, 1e9));
    sort(a.begin(), a.end());
    for (int l = 2; l <= k+2; l++) {
        for (int i = 0; i <= k+2-l; i++) {
            int j = i+l-1;
            if (l == 2) {
                dp[i][j] = 0;
            }
            for (int r = i+1; r < j; r++) {
                dp[i][j] = min(dp[i][j], dp[i][r]+dp[r][j]+a[j]-a[i]-1);
            }
        }
    }
    cout << dp[0][k+1] << '\n';
    return 0;
}
