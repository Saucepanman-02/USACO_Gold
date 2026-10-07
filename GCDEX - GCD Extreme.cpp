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

const int MOD = 1e9+9;
const int MAXN = 1e6+10;

int max_div[MAXN];

void pfactor() {
    for (int i = 2; i < MAXN; i++) {
        max_div[i] = -1;
    }
    for (ll i = 2; i < MAXN; i++) {
        if (max_div[i] == -1) {
            max_div[i] = i;
            for (ll j = i*i; j < MAXN; j += i) {
                max_div[j] = i;
            }
        }
    }
}

int phi[MAXN];

void t1() {
    for (int i = 1; i < MAXN; i++) {
        phi[i] = i;
    }
    for (int i = 2; i < MAXN; i++) {
        if (phi[i] == i) {
            for (int j = i; j < MAXN; j += i) {
                phi[j] -= phi[j]/i;
            }
        }
    }
}

void t2() {
    phi[1]=1;
    for (int i = 2; i < MAXN; i++) {
        phi[i] = i-1;
    }
    for (int i = 2; i < MAXN; i++) {
        for (int j = 2*i; j < MAXN; j += i) {
            phi[j] -= phi[i];
        }
    }
}

ll f[MAXN];
ll ans[MAXN];

int main() {
    pfactor();
    t1();
    for (int i = 0; i < MAXN; i++) {
        f[i] = 0;
        ans[i] = 0;
    }
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            f[j] += (j/i)*(ll)phi[i];
        }
    }
    for (int i = 1; i < MAXN; i++) {
        ans[i] = ans[i-1]+(f[i]-i);
    }
    int x;
    while (cin >> x && x) {
        cout << ans[x] << endl;
    }
    return 0;
}
