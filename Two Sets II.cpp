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
    int n; cin >> n;
    int sum = (n*(n+1))/2;
    if (sum%2) {
        cout << 0 << endl;
        return 0;
    }
    vi dp(sum/2+1);
    dp[0]=1;
    for (int i = 1; i <= n; i++) {
        for (int j = (sum/2); j >= i; j--) {
            dp[j] = (dp[j]+dp[j-i])%MOD;
        }
    }
    cout << (dp[sum/2]%2? ((dp[sum/2]+MOD)/2)%MOD : dp[sum/2]/2 )<< endl;
    return 0;
}
