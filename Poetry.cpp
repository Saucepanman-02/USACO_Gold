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


ll exp(ll a, int e) {
    if (a == 0) {
        return 0;
    }
    ll ans = 1;
    while (e) {
        if (e & 1) ans = ans * a % MOD;
        a = (a * a)% MOD;
        e >>= 1;
    }
    return ans;
}

int main() {
    usopen("poetry")
    int n, m, k; cin >> n >> m >> k;
    vi st(n);
    vector<vi> r_class(n+1);
    for (int i = 0; i < n; i++) {
        int r, u; cin >> r >> u;
        st[i] = r;
        r_class[u].push_back(r);
    }
    vll comp(k+1);
    comp[0] = 1;
    for (int j = 0; j <= k; j++) {
        for (int i = 0; i < n; i++) {
            if (j >= st[i]) {
                comp[j] = (comp[j-st[i]]+comp[j])%MOD;
            }
        }
    }
    vll precomp(n+1);
    for (int i = 0; i <= n; i++) {
        for (int word: r_class[i]) {
            if (word <= k)
                precomp[i] = (precomp[i]+comp[k-word])%MOD;
        }
    }
    vll a(26);
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        a[c-'A']++;
    }
    vll dp(27);
    dp[0] = 1;
    for (int i = 0; i < 26; i++) {
        dp[i+1] = dp[i];
        if (a[i] == 0) {
            continue;
        }
        ll cur = 0;
        for (int j = 0; j <= n; j++) {
            cur = (cur+exp(precomp[j], a[i]))%MOD;
        }
        dp[i+1] = (dp[i+1]*cur)%MOD;
    }
    cout << dp[26] << '\n';
    return 0;
}
