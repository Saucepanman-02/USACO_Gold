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


int main() {
    int n, c; cin >> n >> c;
    vi dp(5*1e5+10);
    int cnt = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if (k == c) {
            cnt++;
        }else {
            dp[k] = max(cnt, dp[k])+1;
        }
        mx = max(mx, dp[k]-cnt);
    }
    cout << cnt+mx << '\n';
    return 0;
}
