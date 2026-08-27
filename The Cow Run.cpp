#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(file) do{freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);}while(0);
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<int>
#define pll pair<ll, ll>
#define f first
#define s second
#define pdi pair<db, int>
#define ceil(n, r) (ll)((n+r-1)/r)
#define floor(n, r) (ll)(n/r);
#define pil pair<int, ll>

const int MOD = 1e9+7;


int main() {
    usopen("cowrun")
    int n; cin >> n;
    vi l, r;
    vi a(n);
    int ls = 0, rs = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            ls++;
        }else {
            rs++;
        }
    }
    if (n == 1) {
        cout << abs(a[0]) << endl;
        return 0;
    }
    l.resize(ls);
    r.resize(rs);
    ls = 0, rs = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            l[ls++] = -a[i];
        }else {
            r[rs++] = a[i];
        }
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    vector<vector<vll>> dp(ls+1, vector<vll>(rs+1, vll(2, 1e9)));
    dp[0][0][0] = 0;
    if (ls >= 1) {
        dp[1][0][0] = n*l[0];
        for (int i = 2; i <= ls; i++) {
            dp[i][0][0] = (n+1-i)*(l[i-1]-l[i-2])+dp[i-1][0][0];
        }
    }
    if (rs >= 1) {
        dp[0][1][1] = n*r[0];
        for (int i = 2; i <= rs; i++) {
            dp[0][i][1] = dp[0][i-1][1]+(n+1-i)*(r[i-1]-r[i-2]);
        }
    }
    for (int i = 1; i <= ls; i++) {
        for (int j = 1; j <= rs; j++) {
            dp[i][j][0] = min(dp[i][j][0], (n+1-i-j)*(l[i-1]+r[j-1])+dp[i-1][j][1]);
            dp[i][j][1] = min(dp[i][j][1], (n+1-i-j)*(l[i-1]+r[j-1])+dp[i][j-1][0]);
            dp[i][j][0] = min(dp[i][j][0], (n+1-i-j)*(i > 1 ? l[i-1]-l[i-2]: l[1])+dp[i-1][j][0]);
            dp[i][j][1] = min(dp[i][j][1], (n+1-i-j)*(j > 1? r[j-1]-r[j-2]: r[1])+dp[i][j-1][1]);
        }
    }
    cout << min(dp[ls][rs][0], dp[ls][rs][1]) << '\n';
    return 0;
}
