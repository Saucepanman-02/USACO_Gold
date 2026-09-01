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

int main() {
    speedup
    int n; ll m; cin >> n >> m;
    vll a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= m*i;
        a[i] *= -1;
    }
    vll lis;
    int i = 1;
    for (; i <= n; i++) {
        if (a[i] < 0) {
            continue;
        }
        int l = 0, r = lis.size()-1; int as = -1;
        while (r >= l) {
            int md = (r+l)/2;
            if (lis[md] > a[i]) {
                as = md;
                r = md-1;
            }else {
                l = md+1;
            }
        }
        if (as == -1) {
            lis.push_back(a[i]);
        }else {
            lis[as] = a[i];
        }
    }
    cout << n-lis.size() << '\n';
    return 0;
}Ra
