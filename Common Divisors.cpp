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

const int MAXN = 1e6+10;

int f[MAXN];

int main() {
    for (int i = 0; i < MAXN; i++) {
        f[i] = 0;
    }
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        f[c]++;
    }
    for (int d = MAXN-1; d >= 1; d-- ) {
        int sum = 0;
        for (int j = d; j < MAXN; j += d) {
            sum += f[j];
            if (sum >= 2) break;
        }
        if (sum >= 2) {
            cout << d << endl;
            return 0;
        }
    }
    return 0;
}
