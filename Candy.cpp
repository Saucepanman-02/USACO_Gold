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

/*
int lis(vll &a) {
    vll lis;
    int n = a.size();
    lis.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        int l = 0, r = lis.size()-1; int as = -1;
        while (r >= l) {
            int md = (r+l)/2;
            if (lis[md] > a[md]) {
                as = md;
                r = md-1;
            }else {
                l = md+1;
            }
        }
    }
    return lis.size();
}*/

bool cmp(pii &a, pii &b ) {
    if (a.f == b.f) {
        return a.s > b.s;
    }
    return a.f < b.f;
}

int main() {
    speedup
    int n; cin >> n;
    vector<pii> a(n);
    vi pw(n), qw(n), wgn(n);
    for (int i = 0; i < n; i++) {
        int p, q; cin >> p >> q;
        a[i] = {p-q, p+q};
        pw[i] = p;
        qw[i] = q;
    }
    sort(a.begin(), a.end(), cmp);
    vi lds;
    lds.push_back(a[0].s);
    wgn[0] = 1;
    for (int i = 1; i < n; i++) {
        int l = 0, r = lds.size()-1; int as = -1;
        while (r >= l) {
            int md = (r+l)/2;
            if (lds[md] >= a[i].s) {
                as = md;
                r = md-1;
            }else {
                l = md+1;
            }
        }
        if (as == -1) {
            lds.push_back(a[i].s);
            wgn[i] = lds.size();
        }else {
            lds[as] = a[i].s;
            wgn[i] = as+1;
        }
    }
    cout << lds.size() << '\n';
    for (int i = 0; i < n; i++) {
        cout << (a[i].f+a[i].s)/2 << ' ' << (a[i].s-a[i].f)/2 <<  ' ' << wgn[i] << '\n';
    }
    return 0;
}
