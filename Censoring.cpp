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
    usopen("censor")
    string st; cin >> st;
    string p; cin >> p;
    __int128 bs = 0;
    string ans = ""; int n = st.size(); int k = p.size();
    for (int i = 0; i < k; i++) {
        bs = (bs*B%M+p[i])%M;
    }
    __int128 cur = 0;
    for (int i = 0; i < n; i++) {
        ans.push_back(st[i]);
        cur = (cur*B%M+st[i])%M;
        int len = ans.size();
        if (len > k) {
            cur -= (pw(B, k)*(ans[len-1-k]))%M;
            cur = (cur+M)%M;
        }
        if (cur == bs) {
            for (int j = 0; j < k; j++) {
                ans.pop_back();
            }
            cur = 0;
            int sz = ans.size();
            for (int j = max(sz-1-(k-1), 0); j < sz; j++) {
                cur = (cur*B%M+ans[j])%M;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
