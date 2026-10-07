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
    for (int i = 1; i < MAXN; i++) {
        max_div[i] = i;
    }
    for (ll i = 2; i < MAXN; i++) {
        if (max_div[i] == i) {
            for (ll j = i*i; j < MAXN; j += i) {
                max_div[j] = i;
            }
        }
    }
}

int phi[MAXN];

void t1() {
    phi[1] = 1;
    for (int i = 2; i < MAXN; i++) {
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

int main() {
    pfactor();
    t1();
    int n; cin >> n;
    if (n==2) {
        cout << 1 << '\n';
        cout << 1 << '\n';
        return 0;
    }
    if (max_div[n] == n) {
        cout << n-2 << '\n';
        for (int i = 1; i <= n-2; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        return 0;
    }
    ll prod = 1;
    for (int i = 1; i < n; i++) {
        if (__gcd(i, n) == 1) {
            prod *= i;
            prod %= n;
        }
    }
    if (prod != 1) {
        cout << phi[n]-1 << '\n';
        for (int i = 1; i < n; i++) {
            if (__gcd(i, n) == 1 && i != prod) {
                cout << i << ' ';
            }
        }
        cout << '\n';
        return 0;
    }
    cout << phi[n] << '\n';
    for (int i = 1; i < n; i++) {
        if (__gcd(i, n)==1) {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}
