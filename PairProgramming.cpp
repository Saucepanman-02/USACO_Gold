#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(file) do{freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);}while(0);
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<ll>
#define vll vector<ll>
#define pll pair<ll, ll>
#define f first
//#define s second
#define pdi pair<db, int>
#define ceil(n, r) (ll)((n+r-1)/r)
#define floor(n, r) (ll)(n/r);
#define pil pair<int, ll>

const int MOD = 1e9+7;

#define VC(c) (c == 'K'? 0: (c == 'E': 1? 2));


void solve() {
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    vector<vi> dp(n+1, vi(n+1));
    vector<vi> zero(n+1, vi(n+1));
    zero[0][0] = 1;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[0][i] = 1;
        if (s[i-1] == '0') {
            zero[i][0] = 1;
        }else if (s[i-1] == '+') {
            zero[i][0] = 0;
        }else {
            zero[i][0] = zero[i-1][0];
        }
        if (t[i-1] == '0') {
            zero[0][i] = 1;
        }else if (t[i-1] == '+') {
            zero[0][i] = 0;
        }else {
            zero[0][i] = zero[0][i-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (t[j-1] == '+') {
                if (s[i-1] == '+') {
                    dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                    zero[i][j] = 0;
                }else if (s[i-1] == '0') {
                    dp[i][j] = dp[i][j-1]+1;
                    zero[i][j] = 1;
                }else if (s[i-1] == '1') {
                    dp[i][j] = dp[i-1][j];
                    zero[i][j] = zero[i-1][j];
                }else {
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                    zero[i][j] = zero[i-1][j];
                }
            }else if (t[j-1] == '0') {
                if (s[i-1] == '+') {
                    dp[i][j] = dp[i-1][j]+1;
                    zero[i][j] = 1;
                }else if (s[i-1] == '0') {
                    dp[i][j] = 1;
                    zero[i][j] = 1;
                }else if (s[i-1] == '1') {
                    dp[i][j] = dp[i-1][j]+(1-zero[i-1][j]);
                    zero[i][j] = 1;
                }else {
                    dp[i][j] = dp[i-1][j]+(1-zero[i-1][j]);
                    zero[i][j] = 1;
                }
            }else if (t[j-1] == '1') {
                if (s[i-1] == '+') {
                    dp[i][j] = dp[i][j-1];
                    zero[i][j] = zero[i][j-1];
                }else if (s[i-1] == '0') {
                    dp[i][j] = dp[i][j-1]+(1-zero[i][j-1]);
                    zero[i][j] = 1;
                }else if (s[i-1] == '1') {
                    dp[i][j] = dp[i-1][j-1];
                    zero[i][j] = zero[i-1][j-1];
                }else {
                    dp[i][j] = dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
                    zero[i][j] = zero[i-1][j-1];
                }
            }else {
                if (s[i-1] == '+') {
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                    zero[i][j] = zero[i][j-1];
                }else if (s[i-1] == '0') {
                    dp[i][j] = dp[i][j-1]+(1-zero[i][j-1]);
                    zero[i][j] = 1;
                }else if (s[i-1] == '1') {
                    dp[i][j] = dp[i-1][j];
                    zero[i][j] = zero[i-1][j];
                }else {
                    dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                    zero[i][j] = zero[i-1][j-1];
                }
            }
            dp[i][j] %= MOD;
        }
    }
    cout << (dp[n][n]+MOD)%MOD << '\n';
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
