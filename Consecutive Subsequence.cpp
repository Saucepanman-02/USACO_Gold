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
    speedup
    int n; cin >> n;
    map<int, int> mp;
    map<int, int> pr;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int fans = 0, adx = 0;
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] < mp[a[i]-1]+1) {
            mp[a[i]] = mp[a[i]-1]+1;
            pr[a[i]] = i;
        }
        if (mp[a[i]] > fans) {
            fans = mp[a[i]];
            adx = a[i];
        }
    }
    cout << fans << endl;
    vi lans;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == adx) {
            lans.push_back(i);
            adx--;
        }
    }
    reverse(lans.begin(), lans.end());
    for (int u: lans) {
        cout << u+1 << ' ';
    }
    cout << '\n';
    return 0;
}
