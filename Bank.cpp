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
    speedup
    int n, m; cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vi dp((1<<m), -1e9);
    dp[0] = 0;
    vi last(1<<m);
    int ans = 0;
    for (int mask = 1; mask < (1<<m); mask++) {
        for (int i = 0; i < m; i++) {
            if (mask&(1<<i) && dp[mask^(1<<i)] < n && dp[mask^(1<<i)] != -1e9) {
                int idx = dp[mask^(1<<i)];
                if (last[mask^(1<<i)]+b[i] < a[idx]) {
                    if (dp[mask] < dp[mask^(1<<i)]) {
                        dp[mask] = dp[mask^(1<<i)];
                        last[mask] = last[mask^(1<<i)]+b[i];
                    }
                }else if (last[mask^(1<<i)]+b[i] == a[idx]) {
                    if (dp[mask] < dp[mask^(1<<i)]+1) {
                        dp[mask] = dp[mask^(1<<i)]+1;
                        last[mask] = 0;
                    }
                }
            }
        }
        ans = ans | (dp[mask] == n);
    }
    cout << (ans? "YES": "NO") << '\n';
    return 0;
}
