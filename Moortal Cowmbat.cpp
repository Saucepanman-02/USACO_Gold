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
    usopen("cowmbat")
    int n, m, k; cin >> n >> m >> k;
    string st; cin >> st;
    vector<vll> dist(m, vll(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> dist[i][j];
        }
    }
    for (int t = 0; t < m; t++ ) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[i][j] > dist[i][t]+dist[t][j]) {
                    dist[i][j] = dist[i][t]+dist[t][j];
                }

            }
        }
    }
    vector<vll> pref(n+1, vll(m));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            pref[i][j] = dist[st[i-1]-'a'][j]+pref[i-1][j];
        }
    }
    vector<ll> dp(n+1, 1e10);
    dp[0] = 0;
    vector<vll> pcomp(n+1, vll(m, (1e10)));
    for (int i = 0; i < m; i++) {
        pcomp[0][i] = 0;
    }
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < m; j++) {
            pcomp[i][j] = 0;
        }
    }
    for (int i = k; i <= n; i++){
        for (int ch = 0; ch < m; ch++) {
            dp[i] = min(dp[i], pref[i][ch]+pcomp[i-k][ch]);
        }
        for (int ch = 0; ch < m; ch++)
        pcomp[i][ch] = min(pcomp[i-1][ch], dp[i]-pref[i][ch]);
    }
    cout << dp[n] << endl;
    return 0;
}
