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

int n, m;
vector<HashString> a;
vector<string> l;
vi ans;

void solve() {
    set<ll> st;
    for (int i = 0; i < n; i++) {
        if (st.find(a[i].hash(0, m-1)) != st.end()) {
            ans[i] = 1;
        }
        st.insert(a[i].hash(0, m-1));
        for (int j = 0; j < m; j++) {
            for (int c = 0; c < 26; c++) {
                if (c == l[i][j]-'a')
                    continue;
                ll hs = (a[i].hash(0, m-1)-pw(B, m-1-j)*(l[i][j]))%M;
                hs += pw(B, m-1-j)*(c+'a');
                hs %= M;
                hs += M;
                hs %= M;
                if (st.find(hs) != st.end()) {
                    ans[i] = 1;
                }
                st.insert(hs);
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        l.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i];
            HashString T(l[i]);
            a.push_back(T);
        }
        ans.resize(n);
        solve();
        reverse(l.begin(), l.end());
        reverse(a.begin(), a.end());
        reverse(ans.begin(), ans.end());
        solve();
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
