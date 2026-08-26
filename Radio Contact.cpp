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


vector<pii> fj;
vector<pii> bs;

pii convert(pii pr, char c) {
    if (c == 'N') {
        return {pr.f, pr.s+1};
    }
    if (c == 'S') {
        return {pr.f, pr.s-1};
    }
    if (c == 'E') {
        return {pr.f+1, pr.s};
    }
    if (c == 'W') {
        return {pr.f-1, pr.s};
    }
}

ll dist(pii a, pii b) {
    return (a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s);
}

int main() {
    usopen("radio")
    int n, m; cin >> n >> m;
    fj.resize(n+1);
    bs.resize(m+1);
    cin >> fj[0].f >> fj[0].s;
    cin >> bs[0].f >> bs[0].s;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        fj[i] = convert(fj[i-1], c);
    }
    for (int i = 1; i <= m; i++) {
        char c; cin >> c;
        bs[i] = convert(bs[i-1], c);
    }
    vector<vll> dp(n+1, vll(m+1, 1e10));
    dp[0][0]=0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0]+dist(fj[i], bs[0]);
    }
    for (int i = 1; i <= m; i++) {
        dp[0][i] = dp[0][i-1]+dist(fj[0], bs[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll c1 = dist(fj[i], bs[j])+dp[i-1][j-1];
            ll c2 = dist(fj[i], bs[j])+dp[i-1][j];
            ll c3 = dist(fj[i], bs[j])+dp[i][j-1];
            dp[i][j] = min(c1, min(c2, c3));
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}
