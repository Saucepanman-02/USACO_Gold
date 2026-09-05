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
    int n, x; cin >> n >> x;
    vi w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vll dp((1<<n), 1e9);
    dp[0] = 0;
    vi last((1<<n), x);
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask&(1<<i)) {
                if (last[mask^(1<<i)]+w[i] <= x && dp[mask^(1<<i)] != 1e9){
                    if (dp[mask] > dp[mask^(1<<i)]) {
                        dp[mask] = dp[mask^(1<<i)];
                        last[mask] = last[mask^(1<<i)]+w[i];
                    }else if (dp[mask] == dp[mask^(1<<i)]) {
                        last[mask] = min(last[mask], last[mask^(1<<i)]+w[i]);
                    }
                }else if (dp[mask^(1<<i)] != 1e9){
                    if (dp[mask] > dp[mask^(1<<i)]+1) {
                        last[mask] = w[i];
                        dp[mask] = dp[mask^(1<<i)]+1;
                    }else if (dp[mask] == dp[mask^(1<<i)]+1) {
                        last[mask] = min(last[mask], w[i]);
                    }
                }
            }
        }
    }
    cout << dp[(1<<n)-1] << '\n';
    return 0;
}
