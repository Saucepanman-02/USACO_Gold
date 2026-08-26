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
    usopen("nocross")
    int n; cin >> n;
    vi a(n);
    vi b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++) {
        cin >> b[j];
    }
    vector<vi> dp(n+1, vi(n+1));
    for (int i = 1; i <= n; i++) {
        for (int j =1 ; j <= n; j++) {
            if (abs(a[i-1]-b[j-1]) <= 4) {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
