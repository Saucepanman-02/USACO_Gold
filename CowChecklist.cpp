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

vector<pii> cw[2];

ll dist(int i, int j, int c1, int c2) {
    i--, j--;
    return (cw[c1][i].f-cw[c2][j].f)*(cw[c1][i].f-cw[c2][j].f)+(cw[c1][i].s-cw[c2][j].s)*(cw[c1][i].s-cw[c2][j].s);
}

int main() {
    usopen("checklist")
    int n, m; cin >> n >> m;
    vector<vector<vll>> dp(n+1, vector<vll>(m+1, vll(2, 1e10)));
    cw[0].resize(n);
    cw[1].resize(m);
    for (int i = 0; i < n; i++) {
        cin >> cw[0][i].f >> cw[0][i].s;
    }
    for (int i = 0; i < m; i++) {
        cin >> cw[1][i].f >> cw[1][i].s;
    }
    dp[1][0][0]=0;
    for (int i = 2; i <= n; i++) {
        dp[i][0][0] = dp[i-1][0][0]+dist(i, i-1, 0, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i >= 2)
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0]+dist(i, i-1, 0, 0));
            if (j >= 2)
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1]+dist(j, j-1, 1, 1));
            dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][1]+dist(i, j, 0, 1));
            dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0]+dist(i, j, 0, 1));
        }
    }
    cout << dp[n][m][0] << endl;
    return 0;
}
