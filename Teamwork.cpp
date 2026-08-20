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
    usopen("teamwork")
    int n, k; cin >> n >> k;
    vll a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> dp(n+1, 0);
    for (int i = 1; i <= n; i++) {
        ll mx = 0;
        for (int j = i; j > max(i-k, 0); j--) {
            mx = max(mx, a[j-1]);
            dp[i] = max(dp[i], dp[j-1]+(i-j+1)*mx);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
