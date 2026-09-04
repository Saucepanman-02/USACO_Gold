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

struct player {
    int a;
    vi p;
};

bool cmp(player &a, player &b) {
    return a.a > b.a;
}

int main() {
    speedup
    int n, p, k; cin >> n >> p >> k;
    vector<player> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].a;
        a[i].p.resize(p);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> a[i].p[j];
        }
    }
    sort(a.begin(), a.end(), cmp);
    vll dp((1<<p));
    for (int i = 0; i < n; i++) {
        for (int mask = (1<<p)-1; mask >= 0; mask--) {
            int mem = __builtin_popcount(mask);
            if (i-mem < k && i >= mem) {
                dp[mask] = max(dp[mask], dp[mask]+a[i].a);
            }
            for (int j = 0; j < p; j++) {
                if (mask&(1<<j)) {
                    dp[mask] = max(dp[mask], dp[mask^(1<<j)]+a[i].p[j]);
                }
            }
        }
    }
    cout << dp[(1<<p)-1] << '\n';
    return 0;
}
