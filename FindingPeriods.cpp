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

mt19937 rng((ll)chrono::steady_clock::now().time_since_epoch().count());
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
            ph[i] = (mod_mul(ph[i-1],B)+s[i-1]-'a')%M;
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

ll inv(__int128 a) {
    ll b = M-2;
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
    string st; cin >> st;
    HashString T(st);
    int n = st.size();
    for (int i = 0; i < n; i++) {
        if (i == 2) {
            string debug;
        }
        ll hsh = T.hash(0, i);
        int p = i+1;
        bool flag = true;
        while (p+i < n && flag) {
            flag = flag && (T.hash(p, p+i) == hsh);
            p += i+1;
        }
        if (!flag) {
            continue;
        }
        int len = n-p;
        flag = flag && (T.hash(0, len-1) == T.hash(n-len, n-1));
        if (flag) {
            cout << i+1 << '\n';
        }
    }
    return 0;
}
