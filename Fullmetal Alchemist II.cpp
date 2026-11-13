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

mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
class HashString {
public:
    static const ll M = (1LL<<61)-1;
    static const ll B;

    vector<ll> pw = {1};
    vector<ll> ph;

    __int128 mul(ll a, ll b) {
        return (__int128)a*b;
    }
    ll mod_mul(ll a, ll b) {
        return mul(a, b)%M;
    }
    HashString(string &s): ph(s.size()+1) {
        while (pw.size() <= s.size()) {
            pw.push_back(mod_mul(pw.back(), B));
        }
        ph[0] = 0;
        for (int i = 1; i <= s.size(); i++){
            ph[i] = (mod_mul(ph[i-1],B)+s[i-1])%M;
        }
    }

    ll hash(int st, int ed) {
        ll hash = (ph[ed+1]-mod_mul(ph[st],pw[ed-st+1]))%M;
        return (hash+M)%M;
    }
};

const ll HashString::B = uniform_int_distribution<ll>(256, M - 1)(rng);

const auto B = HashString::B;
const auto M = HashString::M;

__int128 pw(__int128 a, ll b) {
    __int128 pw = 1;
    while (b) {
        if (b&1) {
            pw = pw*a%M;
        }
        b >>= 1;
        a = a*a%M;
    }
    return pw;
}

struct edge {
    int u, v, w;
};

bool cmp(edge &a, edge &b) {
    return a.w > b.w;
}

int main() {
    int n; cin >> n;
    vector<HashString> a;
    vector<string> lg;
    for (int i = 0; i < n; i++) {
        string st; cin >> st;
        lg.push_back(st);
        HashString T(st);
        a.push_back(T);
    }
    vector<edge> e;
    vector<vi> dist(n, vi(n));
    vi l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][i] = 0;
                continue;
            }
            int mx = 0;
            int lf = lg[i].size(), rf = lg[j].size();
            for (int r = 1; r <= min(lg[i].size(), lg[j].size()); r++) {
                if (a[i].hash(lf-1-(r-1), lf-1) == a[j].hash(0, r-1)) {
                    mx = r;
                }
            }
            if (lf >= rf) {
                for (int r = 0; r <= lf-rf; r++) {
                    if (a[i].hash(r, r+rf-1) == a[j].hash(0, rf-1)) {
                        mx = 0;
                        l.push_back(j);
                    }
                }
            }else {
                for (int r = 0; r <= rf-lf; r++) {
                    if (a[j].hash(r, r+lf-1) == a[i].hash(0, lf-1)) {
                        mx = 0;
                        l.push_back(i);
                    }
                }
            }
            dist[i][j] = mx;
        }
    }
    vi rem(n);
    for (int u: l) {
        rem[u] = 1;
    }
    vector<vi> dp((1<<n), vi(n, 0));
    for (int i = 0; i < n; i++) {
        dp[(1<<i)][i] = 0;
    }

    for (int mask = 1; mask < (1<<n); mask++) {
        if (__builtin_popcount(mask) == 1)
            continue;
        for (int i = 0; i < n; i++) {
            if (rem[i])
                continue;
            if (mask&(1<<i)) {
                for (int j = 0; j < n; j++) {
                    if (rem[j]) {
                        continue;
                    }
                    if (j == i)
                        continue;
                    if (mask&(1<<j)) {
                        dp[mask][i] = max(dp[mask][i], dp[mask^(1<<i)][j]+dist[i][j]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[(1<<n)-1][i]);
    }
    ans *= -1;
    for (int i = 0; i < n; i++) {
        if (rem[i])
            continue;
        ans += lg[i].size();
    }
    cout << ans << '\n';
    return 0;
}
