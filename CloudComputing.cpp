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
#define ceil(n, r) (ll)((n+r-1)/r)
#define floor(n, r) (ll)(n/r);
#define pil pair<int, ll>

struct E {
    int c, t, v;
};


bool cmp(E &a, E &b) {
    if (a.t == b.t) {
        return a.v < b.v;
    }
    return a.t > b.t;
}

int main() {
    int n; cin >> n;
    vector<E> a(n);
    int MAXC = 2000*50;
    for (int i = 0; i < n; i++) {
        cin >> a[i].c >> a[i].t >> a[i].v;
        a[i].v *= -1;
    }
    int m; cin >> m;
    a.resize(n+m);
    for (int i = n; i < n+m; i++) {
        cin >> a[i].c >> a[i].t >> a[i].v;
        a[i].c *= -1;
    }
    sort(a.begin(), a.end(), cmp);
    vll dp(MAXC+1, -1e15);
    dp[0] = 0;
    vll ndp(MAXC+1, -1e15);
    ndp[0] = 0;
    for (int i = 0; i < n+m; i++) {
        for (int cr = 0; cr <= MAXC; cr++) {
            ndp[cr] = dp[cr];
            if ((cr-a[i].c) >= 0 && (cr-a[i].c) <= MAXC && dp[cr-a[i].c] != (ll)(-1e15)) {
                ndp[cr] = max(ndp[cr], dp[cr-a[i].c]+a[i].v);
            }
        }
        for (int j = 0; j <= MAXC; j++) {
            dp[j] = ndp[j];
        }
    }
    ll ans = 0;
    for (int i = 0; i <= MAXC; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
