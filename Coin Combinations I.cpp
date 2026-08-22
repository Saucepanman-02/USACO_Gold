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
    int n, x; cin >> n >> x;
    vi c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vi dp(x+1);
    dp[0] = 1;
    for (int j = 1; j <= x; j++) {
        for (int i = 0; i < n; i++) {
            if (j >= c[i]) {
                dp[j] = (dp[j]+dp[j-c[i]])%MOD;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}
