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
#define floor(n, r) (ll)(n/r)
#define pil pair<int, ll>
#define max(a, b) (a >= b? a: b)
#define min(a, b) (a <= b? a: b)

#define MAXN (int)(1e4+5)

const int MOD = 1e9+7;
ll fac[MAXN];

ll pw(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b&1) {
            ans =ans*a%MOD;
        }
        a = a*a%MOD;
        b >>= 1;
    }
    return ans;
}

int d[MAXN];

int main() {
    ll n, k; cin >> n >> k;
    ll ans = 1;
    if (k >= 2) {
        ans += (n*(n-1))/2*1;
    }
    if (k >= 3) {
        ans += (n*(n-1)*(n-2))/3;
    }
    if (k >= 4) {
        ans += (n*(n-1)*(n-2)*(n-3))/(24)*9;
    }
    cout << ans << endl;
    return 0;
}
