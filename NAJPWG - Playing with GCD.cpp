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
#define floor(n, r) (ll)(n/r)
#define pil pair<int, ll>
#define max(a, b) (a >= b? a: b)
#define min(a, b) (a <= b? a: b)

const int MAXN=1e5+10;

int phi[MAXN];

void t() {
    for (int i = 1; i < MAXN; i++) {
        phi[i] = i;
    }
    for (int j = 2; j < MAXN; j++) {
        if (phi[j] == j) {
            for (int i = j; i < MAXN; i += j) {
                phi[i] -= phi[i]/j;
            }
        }
    }
}

ll ans[MAXN];

int main() {
    t();
    ans[0] = 0;
    for (int i = 1; i < MAXN; i++) {
        ans[i] = (i-phi[i])+ans[i-1];
    }
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int x; cin >> x;
        cout << "Case " << i+1 << ": "<< ans[x] << endl;
    }
    return 0;
}
