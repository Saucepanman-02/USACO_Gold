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
    usopen("spainting")
    int n, m, k; cin >> n >> m >> k;
    vector<ll> dp(n+1, 0);
    vector<ll> pref(n+1, 0);
    dp[1] = m;
    pref[1] = m;
    for (int i = 2; i < k; i++) {
        dp[i] = (dp[i-1]*m)%MOD;
        pref[i] = (pref[i-1]+dp[i])%MOD;
    }
    for (int i = k; i <= n; i++) {
        dp[i] = ((m-1)*(pref[i-1]-(i-k>= 0? pref[i-k]: 0)))%MOD;
        pref[i] = (pref[i-1]+dp[i])%MOD;
    }
    ll tot = 1;
    for (int i = 0; i < n; i++) {
        tot = (tot*m)%MOD;
    }
    cout << ((tot-dp[n])%MOD+MOD)%MOD << '\n';
    return 0;
}
