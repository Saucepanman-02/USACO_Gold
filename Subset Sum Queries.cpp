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

const int MOD = 998244353;

int main() {
    int q, k; cin >> q >> k;
    vi dp(k+1);
    dp[0]=1;
    for (int i = 0; i < q; i++) {
        char c; cin >> c; int x; cin >> x;
        if (c == '+') {
            for (int j = k; j >= x; j--) {
                dp[j] = (dp[j]+dp[j-x])%MOD;
            }
        }else {
            for (int j = x; j <= k; j++) {
                dp[j] = (dp[j]-dp[j-x]+MOD)%MOD;
            }
        }
        cout << dp[k] << '\n';
    }
    return 0;
}
