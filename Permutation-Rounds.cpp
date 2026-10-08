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

vi vis;
int cnt;
vi p;

void dfs(int u) {
    if (vis[u])
        return;
    vis[u]  = true;
    cnt++;
    dfs(p[u]);
}

ll PW(ll a, ll b) {
    ll pw = 1;
    while (b) {
        if (b&1) {
            pw = pw*a%MOD;
        }
        a = a*a%MOD;
        b >>= 1;
    }
    return pw;
}
__int128 gcd128(__int128 a, __int128 b) {
    while (b) {
        __int128 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

vi primes;
const int MAXN = 1e6+5;
int max_div[MAXN];

void pfactor() {
    for (int i = 1; i < MAXN; i++) {
        max_div[i] = i;
    }
    for (ll i = 2; i < MAXN; i++) {
        if (max_div[i] == i) {
            primes.push_back(i);
            for (ll j = i*i; j < MAXN; j += i) {
                max_div[j] = i;
            }
        }
    }
}
int main() {
    pfactor();
    int n; cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i]; p[i]--;
    }
    vis.resize(n);
    vll l;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt = 0;
            dfs(i);
            if (cnt == 1) {
                continue;
            }
            l.push_back(cnt);
        }
    }
    ll ans = 1;
    for (int pr: primes) {
        ll mc = 1;
        for (ll r: l) {
            if (r%pr) continue;
            cnt = 1;
            while (r%pr == 0) {
                cnt *= pr;
                r /= pr;
            }
            mc = max(mc, cnt);
        }
        ans *= mc;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
