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

const int MOD = 998244353;

int main() {
    int n; cin >> n;
    vi a(n); ll sum = 0;
    for (int i=0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vi dp(sum+1);
    dp[0] = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= a[i]; j--) {
            if (dp[j] == 0 &&  dp[j-a[i]]) {
                cnt++;
                dp[j] = 1;
            }
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) {
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}
