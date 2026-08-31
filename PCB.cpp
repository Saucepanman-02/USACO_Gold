#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(file) do{freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);}while(0);
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<ll>
#define vll vector<ll>
#define pll pair<ll, ll>
#define f first
#define s second
#define pdi pair<db, int>
#define ceil(n, r) (ll)((n+r-1)/r)
#define floor(n, r) (ll)(n/r);
#define pil pair<int, ll>



int main() {
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        a[i] = {u, v};
    }
    sort(a.begin(), a.end());
    vi b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i].s;
    }
    vi lis;
    lis.push_back(b[0]);
    for (int i = 1; i < n; i++) {
        int l = 0, r = lis.size()-1, as = -1;
        while (r >= l) {
            int md = (r+l)/2;
            if (lis[md] <= b[i]) {
                r = md-1;
                as = md;
            }else {
                l = md+1;
            }
        }
        if (as == -1) {
            lis.push_back(b[i]);
        }else {
            lis[as] = b[i];
        }
    }
    cout << lis.size() << '\n';
    return 0;

}
