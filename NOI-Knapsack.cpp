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
    int tot, n; cin >> tot >> n;
    map<int, vector<pii>> mp;
    for (int i = 0; i < n; i++) {
        int v, w, k; cin >> v >> w >> k;
        if (mp.find(w) == mp.end()) {
            mp[w] = {};
        }
        mp[w].push_back({-v, k});
    }
    vll dp(tot+1);
    for (auto &[w, items]: mp) {
        sort(items.begin(), items.end());
        for (int j = tot; j >= 1; j--) {
            int tcnt = 0;
            int ccnt = 0;
            ll cur = 0;
            int idx = 0;
            int sz = items.size();
            while (idx < sz && j-(tcnt+1)*w >= 0) {
                if (ccnt+1 <= items[idx].s) {
                    cur += -1*items[idx].f;
                    dp[j] = max(dp[j], cur+dp[j-(tcnt+1)*w]); ccnt++; tcnt++;
                }else {
                    idx++;
                    ccnt = 0;
                }
            }
        }
    }
    cout << dp[tot] << endl;
    return 0;
}
