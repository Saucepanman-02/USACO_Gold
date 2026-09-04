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
    usopen("guard")
    speedup
    int n, h; cin >> n >> h;
    vi hg(n), w(n), st(n);
    for (int i = 0; i < n; i++) {
        cin >> hg[i] >> w[i] >> st[i];
    }
    vll hg_cal((1<<n));
    vll w_cal((1<<n));
    for (int mask = 1; mask < (1<<n); mask++) {
        int pos = __builtin_ctz(mask-(mask&(mask-1)));
        hg_cal[mask] = hg[pos]+hg_cal[mask&(mask-1)];
        w_cal[mask] = w[pos]+w_cal[mask&(mask-1)];
    }
    vll dp(1<<n, -1e10);
    dp[0]=1e10;
    ll ans = -1e10;
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask&(1<<i)) {
                if (st[i] >= w_cal[mask^(1<<i)]) {
                    dp[mask] = max(dp[mask], min(dp[mask^(1<<i)], st[i]-w_cal[mask^(1<<i)]));
                }
            }
        }
        if (hg_cal[mask] >= h) {
            ans = max(ans, dp[mask]);
        }
    }
    if (ans != -1e10)
        cout << ans << '\n';
    else
        cout << "Mark is too tall" << '\n';
    return 0;
}
