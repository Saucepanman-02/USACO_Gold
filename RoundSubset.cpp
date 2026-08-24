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

int v2(ll n) {
    int cnt = 0;
    while ((n%2) == 0) {
        cnt++;
        n /= 2;
    }
    return cnt;
}

int v5(ll n) {
    int cnt = 0;
    while (n%5 == 0) {
        cnt++;
        n /= 5;
    }
    return cnt;
}
int main() {
    int n, k; cin >> n >> k;
    vi a2(n), a5(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        ll c; cin >> c;
        a2[i] = v2(c);
        a5[i] = v5(c); sum += a5[i];
    }
    vector<vi> dp (k+1, vi(sum+1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 1; j--) {
            for (int l = a5[i]; l <= sum; l++) {
                if (dp[j-1][l-a5[i]] != -1) {
                    dp[j][l] = max(dp[j][l], a2[i]+dp[j-1][l-a5[i]]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= sum; i++) {
        ans = max(ans, min(dp[k][i], i));
    }
    cout << ans << endl;
    return 0;
}
