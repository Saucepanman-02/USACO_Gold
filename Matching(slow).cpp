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
    speedup
    int n; cin >> n;
    vector<int> g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c; cin >> c;
            if (c == 1) {
                g[i] |= (1<<j);
            }
        }
    }
    vector<vi> dp((1<<n), vi(n+1));
    dp[0][0] = 1; int sub;
    for (int mask = 1; mask < (1<<n); mask++) {
        sub = mask;
        while (sub) {
            int pos = __builtin_ctz(sub-(sub&(sub-1)));
            for (int i = 0; i < n; i++) {
                if (g[pos]&(1<<i)) {
                    dp[mask][i+1] += dp[mask^(1<<pos)][i];
                }
                dp[mask][i+1] += dp[mask][i];
                dp[mask][i+1] %= MOD;
            }
            sub = sub&(sub-1);
        }
    }
    cout << (dp[(1<<n)-1][n]+MOD)%MOD << '\n';
    return 0;
}
