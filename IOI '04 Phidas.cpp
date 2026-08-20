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
    int w, h; cin >> w >> h;
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
    }
    vector<vi> dp(w+1, vi(h+1, 0));
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            dp[i][j] = i*j;
        }
    }
    for (int i = 0; i < n; i++) {
        dp[a[i].f][a[i].s] = 0;
    }
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            for (int d1 = 1; d1 <= i-d1; d1++) {
                dp[i][j] = min(dp[i][j], dp[d1][j]+dp[i-d1][j]);
            }
            for (int d2 = 1; d2 <= j-d2; d2++) {
                dp[i][j] = min(dp[i][j], dp[i][d2]+dp[i][j-d2]);
            }
        }
    }
    cout << dp[w][h] << '\n';
    return 0;
}
