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
    int n, x; cin >> n >> x;
    vi h(n), st(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> st[i];
    }
    vi dp(x+1);
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], dp[j-h[i]]+st[i]);
        }
    }
    cout << dp[x] << '\n';
    return 0;
}
