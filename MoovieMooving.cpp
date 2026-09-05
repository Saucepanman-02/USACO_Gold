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
    usopen("movie")
    int n, l; cin >> n >> l;
    vector<vll> shows(n);
    vll d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        int c; cin >> c;
        shows[i].resize(c);
        for (int j = 0; j < c; j++) {
            cin >> shows[i][j];
        }
        sort(shows[i].begin(), shows[i].end());
    }
    vll dp((1<<n), -1e10);
    int ans = 1e9;
    dp[0] = 0;
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask&(1<<i)) {
                int l = 0, r = shows[i].size()-1, as = -1;
                while (r >= l) {
                    int md = (r+l)/2;
                    if (shows[i][md] <= dp[mask^(1<<i)]) {
                        as = md;
                        l = md+1;
                    }else {
                        r = md-1;
                    }
                }
                if (as != -1 && dp[mask^(1<<i)] != -1e10)
                    dp[mask] = max(dp[mask], shows[i][as]+d[i]);
            }
        }
        if (dp[mask] >= l) {
            ans = min(ans, __builtin_popcount(mask));
        }
    }
    cout << (ans == 1e9? -1: ans) << '\n';
    return 0;
}
