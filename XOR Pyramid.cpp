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

#define MAXN (int)(2*1e6+5)

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

ll nCr(int n, int r) {
    return fac[n]*pw(fac[r], MOD-2)%MOD*pw(fac[n-r], MOD-2)%MOD;
}


int recur(vi &a, int n) {
    if (n == 1) {
        return a[0];
    }
    int k = log2(n);
    vi pref(n+1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1]^a[i-1];
    }
    vi b(n-(1<<k)+1);
    for (int i = 0; i < n-(1<<k)+1; i++) {
        b[i] = pref[(1<<k)+i]^pref[i];
    }
    return recur(b, n-(1<<k)+1);
}
int main() {
    speedup
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << recur(a, n) << endl;
    return 0;
}
