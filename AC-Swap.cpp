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

#define VC(c) (c == 'K'? 0: (c == 'E': 1? 2));

int main() {
    string st; cin >> st;
    int k; cin >> k;
    int n = st.size();
    k = min(k, (n*(n-1))/2);
    vector<vi> pc(3, vi());
    vector<vi> pref(3, vi(n+1));
    for (int i = 1; i <= n; i++) {
        pref[0][i] = pref[0][i-1];
        pref[1][i] = pref[1][i-1];
        pref[2][i] = pref[2][i-1];
        if (st[i-1] == 'K') {
            pref[0][i]++;
            pc[0].push_back(i);
        }else if (st[i-1] == 'E') {
            pref[1][i]++;
            pc[1].push_back(i);
        }else {
            pref[2][i]++;
            pc[2].push_back(i);
        }
    }
    int nk = pc[0].size(), ne= pc[1].size(), ny = pc[2].size();
    vector<vector<vector<vi>>> dp(k+1, vector<vector<vi>>(nk+1, vector<vi>(ne+1, vi(ny+1))));
    dp[0][0][0][0] = 1;
    for (int swp = 0; swp <= k; swp++) {
        for (int k0 = 0; k0 <= nk; k0++) {
            for (int e0 = 0; e0 <= ne; e0++) {
                for (int y0 = 0; y0 <= ny; y0++) {
                    if (k0 < nk) {
                        int cost = max(0LL, pref[1][pc[0][k0]]-e0)+max(0LL, pref[2][pc[0][k0]]-y0);
                        if (cost+swp <= k) {
                            dp[cost+swp][k0+1][e0][y0] += dp[swp][k0][e0][y0];
                        }
                    }
                    if (e0 < ne) {
                        int cost = max(0LL, pref[0][pc[1][e0]]-k0)+max(0LL, pref[2][pc[1][e0]]-y0);
                        if (cost+swp <= k) {
                            dp[cost+swp][k0][e0+1][y0] += dp[swp][k0][e0][y0];
                        }
                    }
                    if (y0 < ny) {
                        int cost = max(0LL, pref[0][pc[2][y0]]-k0)+max(0LL, pref[1][pc[2][y0]]-e0);
                        if (cost+swp <= k) {
                            dp[cost+swp][k0][e0][y0+1] += dp[swp][k0][e0][y0];
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        ans += dp[i][nk][ne][ny];
    }
    cout << ans << endl;
    return 0;
}
