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

const int MOD = 1e9+7;

ll pw(ll a, ll b) {
    a %= MOD;
    b %= (MOD-1);
    ll cr = 1;
    while (b) {
        if (b&1) cr = cr*a%MOD;
        b >>= 1;
        a = a*a%MOD;
    }
    return cr;
}

int main() {
    int n; cin >> n;
    vll a(n);
    vll b(n);
    ll s1 = 1;
    ll s2 = 1;
    ll s01 = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        s1 = (s1*(b[i]+1))%MOD;
        s01 = (s01*(b[i]+1))%(2*(MOD-1));
        s2 = (s2*(pw(a[i], b[i]+1)-1)%MOD*(pw(a[i]-1, MOD-2)))%MOD;
    }
    //No of divisors
    cout << s1%MOD << ' ';
    //Sum of divisors
    cout << s2 << ' ';
    //Prod of divisors
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= pw(a[i], (b[i]*s01)/2); ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}
