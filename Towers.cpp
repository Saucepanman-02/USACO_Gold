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
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi lds;
    lds.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        int l = 0, r = lds.size()-1, ans = -1;
        while (r >= l) {
            int md = (r+l)/2;
            if (lds[md] > a[i]) {
                ans = md;
                r = md-1;
            }else {
                l = md+1;
            }
        }
        if (ans == -1) {
            lds.push_back(a[i]);
        }else {
            lds[ans] = a[i];
        }
    }
    cout << lds.size() << '\n';
    return 0;

}
