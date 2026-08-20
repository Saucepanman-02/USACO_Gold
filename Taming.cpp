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

int n;
vi a;

int main() {
    usopen("taming")
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vi> dp(n, vi(n+1, 1e9));
    vector<vi> cost(n, vi(n, 0));
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; i+j < n; j++) {
            cnt += (a[i+j] == j);
            cost[i][i+j] = cnt;
        }
    }
    for (int i = 0; i < n; i++) {
        dp[i][1] = (i+1-cost[0][i]);
    }
    for (int br = 2; br <= n; br++) {
        for (int pos = 0; pos < n; pos++) {
            for (int r = pos; r > 0; r--) {
                dp[pos][br] = min(dp[pos][br], (pos-r+1-cost[r][pos])+dp[r-1][br-1]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[n-1][i] << '\n';
    }
    return 0;
}
