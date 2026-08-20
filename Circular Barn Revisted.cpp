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

int n, k;


ll solve(vi &a) {
    vector<vll> dp(n, vll(k));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][0] += a[j]*(j);
        }
    }
    for (int k0 = 1; k0 < k; k0++) {
        for (int pos = k0; pos < n; pos++){
            ll sum = 0, ws = 0;
            dp[pos][k0] = 1e10;
            for (int r = pos; r > 0; r--) {
                dp[pos][k0] = min(dp[pos][k0], dp[r-1][k0-1]+ws);
                sum += a[r];;
                ws = ws+sum;
            }
        }
    }
    return dp[n-1][k-1];
}

int main() {
    usopen("cbarn2")
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 1e10;
    for (int i = 0; i < n; i++) {
        vector<int> b(n);
        for (int j = 0; j < n; j++) {
            b[j] = a[(i+j)%n];
        }
        ll cur = solve(b);
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
