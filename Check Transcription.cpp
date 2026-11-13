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

const ll HashString::B = uniform_int_distribution<ll>(0, M - 1)(rng);

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

int main() {
    string s, t; cin >> s >> t;
    ll c0,c1; c0=c1=0;
    int n = s.size();
    ll d0, d1;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '0') {
            c0++; d0 = i;
        }else {
            c1++; d1 = i;
        }
    }
    int sz = t.size();
    HashString T(t);
    int ans = 0;
    for (int i = 1; i < sz; i++) {
        if (i*c0 >= sz) {
            break;
        }
        if ((sz-i*c0)%c1 == 0) {
            int s0 = i, s1 = (sz-i*c0)/c1;
            ll dx0 = d0*s1, dx1 = d1*s0;
            ll bs0 = T.hash(dx0, dx0+s0-1);
            ll bs1 = T.hash(dx1, dx1+s1-1);
            if (bs0 == bs1) {
                continue;
            }
            int p = 0;
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (s[j] == '0') {
                    flag = flag && (T.hash(p, p+s0-1) == bs0);
                    p = p+s0;
                }else {
                    flag = flag && (T.hash(p, p+s1-1)==bs1);
                    p = p+s1;
                }
            }
            ans += (flag);
        }
    }
    cout << ans << endl;
    return 0;
}
