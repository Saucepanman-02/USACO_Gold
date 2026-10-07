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

const int MOD = 1e9+9;
const int MAXN = 1e6+10;

int max_div[MAXN];

ll mxn(ll c) {
   ll l = 0, r = c, ans = -1;
    while (r >= l) {
        ll m = (r+l)/2;
        if (c >= (m*(m+1))/2) {
            l = m+1;
            ans = m;
        }else {
            r = m-1;
        }
    }
    return ans;
}

int main() {
    ll n; cin >> n;
    ll ans = 0;
    ll c = n;
    for (ll i = 2; i*i <= n; i++) {
        if (c%i == 0) {
            ll cnt = 0;
            while (c%i == 0) {
                cnt++;
                c /= i;
            }
            ans += mxn(cnt);
        }
    }
    if (c != 1) {
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
