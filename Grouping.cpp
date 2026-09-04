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
    vector<vi> a(n, vi(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vll dp((1<<n));
    for (int mask = 1; mask < (1<<n); mask++) {
        int pos = __builtin_ctz(mask-(mask&(mask-1)));
        int smask = mask&(mask-1);
        ll sum = 0;
        while (smask) {
            int p = __builtin_ctz(smask-(smask&(smask-1)));
            sum += a[pos][p];
            smask &= (smask-1);
        }
        dp[mask] = sum+dp[mask^(1<<pos)];
    }
    vll cost(1<<n);
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int smask = mask; smask; smask = (smask-1)&mask) {
           cost[mask] = max(cost[mask], dp[smask]+cost[mask^smask]);
        }
    }
    cout << cost[(1<<n)-1] << '\n';
    return 0;
}
