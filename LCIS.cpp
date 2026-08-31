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
#define s second
#define pdi pair<db, int>
#define ceil(n, r) (ll)((n+r-1)/r)
#define floor(n, r) (ll)(n/r);
#define pil pair<int, ll>

const int MOD = 1e9+7;


int main() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m; cin >> m;
    vi d = a;
    vi b(m);
    d.resize(n+m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        d[n+i] = b[i];
    }
    sort(d.begin(), d.end());
    auto it = unique(d.begin(), d.end());
    d.erase(it, d.end());
    map<int, int> mp;
    map<int, int> pm;
    int sz = d.size();
    for (int i = 0; i < sz; i++) {
        mp[d[i]] = i;
        pm[i] = d[i];
    }
    for (int i = 0; i < n; i++) {
        a[i] = mp[a[i]];
    }
    for (int i = 0; i < m; i++) {
        b[i] = mp[b[i]];
    }
    vector<vi> dp(n+1, vi(m+1));
    vector<vi> chuck(n+1, vi(m+1));
    vector<vector<pii>> btrack(n+1, vector<pii>(m+1, {-1, -1}));
    vector<vector<pii>> pchuck(n+1, vector<pii>(m+1, {-1, -1}));
    for (int k = 0; k < sz; k++) {
        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                if (a[i-1] == b[j-1] && a[i-1] == k) {
                    if (dp[i][j] < dp[i-1][j-1]+1) {
                        chuck[i][j] = 1;
                        dp[i][j] = dp[i-1][j-1]+1;
                        btrack[i][j] = {i, j};
                        pchuck[i][j]  = btrack[i-1][j-1];
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (dp[i][j] < dp[i-1][j]) {
                    dp[i][j] = dp[i-1][j];
                    chuck[i][j] = 0;
                    btrack[i][j] = btrack[i-1][j];
                }
                if (dp[i][j] < dp[i][j-1]) {
                    dp[i][j] = dp[i][j-1];
                    chuck[i][j] = 0;
                    btrack[i][j] = btrack[i][j-1];
                }
            }
        }
    }
    cout << dp[n][m] << '\n';
    int cn = btrack[n][m].f, cm = btrack[n][m].s;
    vi lst;
    int cnt = dp[n][m];
    while (cnt) {
        int dn, dm;
        tie(dn, dm) = tie(pchuck[cn][cm].f, pchuck[cn][cm].s);
            //cout << cn << ' ' << cm << endl;
            //cout << dp[cn][cm] << '\n';
        lst.push_back(a[cn-1]); cnt--;
        cn = dn, cm = dm;
    }
    reverse(lst.begin(), lst.end());
    for (int u: lst) {
        cout << pm[u] << ' ';
    }
    cout << '\n';
    return 0;
}
