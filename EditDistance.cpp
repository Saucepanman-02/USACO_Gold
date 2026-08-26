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
    string s1; cin >> s1;
    string s2; cin >> s2;
    int n = s1.size(); int m = s2.size();
    vector<vi> dp(n+1, vi(m+1, 1e9));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
            dp[i][j] = min(dp[i][j], 1+dp[i][j-1]); //Add char
            dp[i][j] = min(dp[i][j], 1+dp[i-1][j]); //Remove char
            dp[i][j] = min(dp[i][j], 1+dp[i-1][j-1]); //Replace
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}
