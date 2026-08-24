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

vi p;

bool isprime(int n) {
    for (int u: p) {
        if (n%u == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    usopen("exercise")
    int n, m; cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        if (isprime(i)) {
            p.push_back(i);
        }
    }
    //int sz = p.size();
    vector<ll> dp(n+1);
    dp[0]=1;
    //dp[1]=1;
    for (int pr: p) {
        for (int j = n; j >= 1; j--) {
            ll cur = pr;
            while (j >= cur) {
                dp[j] = (dp[j]+cur*dp[j-cur])%m;
                cur = (cur*pr)%m;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans+dp[i])%m;
    }
    cout << (ans+1)%m << '\n';
    return 0;
}
