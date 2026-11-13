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
    int t; cin >> t;
    while (t--) {
        string st; cin >> st;
        HashString T(st);
        int l = 0, r = st.size()-1;
        int ans = 0;
        while (r >= l) {
            int d = -1;
            for (int i = 1; l+i-1 < r-i+1; i++) {
                if (T.hash(l, l+i-1) == T.hash(r-(i-1), r)) {
                    d = i;
                    break;
                }
            }
            if (d == -1) {
                ans++;
                break;
            }
            l = l+d;
            r = r-d;
            ans += 2;
        }
        cout << ans << endl;
    }
    return 0;
}
