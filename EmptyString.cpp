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
    string a; cin >> a;
    int n = a.size();
    for (int i = 0; i < 505; i++) {
        for (int j = 0; j < 505; j++) {
            memo[i][j] = -2;
        }
    }
    vector<vll> dp(n+1, vll(n+1));
    for (int l = 2; l <= n; l += 2) {
        for (int i = 0; i <= n-l; i++){
            int j = i+l-1;
            for (int r = i+1; r <= j; r+=2) {
                if (a[i] == a[r]) {
                    dp[i][j] = (dp[i][j]+(nCr(l/2, (r-i+1)/2)*(((i+1 > r-1? 1LL: dp[i+1][r-1])*(r+1 > j? 1LL: dp[r+1][j])%MOD))%MOD))%MOD;
                }
            }
        }
    }
    cout << dp[0][n-1]%MOD << '\n';
    return 0;
}
