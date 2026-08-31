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

const int MOD = 1e9+7;


int main() {
    usopen("cowjog")
    int n; ll t; cin >> n >> t;
    vector<pll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
        a[i].s = a[i].f+a[i].s*t;
    }
    sort(a.begin(), a.end());
    vll lis;
    lis.push_back(a[0].s);
    for (int i = 1; i < n; i++) {
        int l = 0, r = lis.size()-1, as = -1;
        while (r >= l) {
            int md = (r+l)/2;
            if (lis[md] < a[i].s) {
                as = md;
                r = md-1;
            }else {
                l = md+1;
            }
        }
        if (as == -1) {
            lis.push_back(a[i].s);
        }else {
            lis[as] = a[i].s;
        }
    }
    cout << lis.size() << '\n';
    return 0;
}
