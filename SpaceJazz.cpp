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
    string st; cin >> st;
    int n = st.size();
    vector<vi> dp(n+1, vi(n+1));
    for (int l = 1; l <= n; l++){
    for (int i = 0; i <= n-l; i++) {
            int j = i+l-1;
            dp[i][j] = dp[i+1][j]+1;
            for (int r = i+1; r <= j; r++) {
                if (st[r] == st[i]) {
                    dp[i][j] = min(dp[i][j], dp[i+1][r-1]+dp[r+1][j]);
                }
            }
        }
    }
    cout << dp[0][n-1] << '\n';
    return 0;
}
