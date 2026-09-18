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

string num;
const int dig = 20;
ll memo[dig][2][2][11];

ll dp(int pos, bool under, bool start, int d) {
    if (pos == num.size()) {
        if (start) {
            return 1;
        }
        return 1;
    }
    if (memo[pos][under][start][d] != -1) {
        return memo[pos][under][start][d];
    }
    int h = 9;
    if (!under) {
        h = num[pos]-'0';
    }
    ll cur = 0;
    for (int i = 0; i <= h; i++) {
        if (i == d)
            continue;
        if (start) {
            cur += dp(pos+1, under || i < h, start, i);
        }else if (i != 0) {
            cur += dp(pos+1, under || i < h, start || i > 0, i);
        }
    }
    if (!start) {
        cur += dp(pos+1, under||(0 < h), 0, 10);
    }
    return (memo[pos][under][start][d] = cur);
}

int main() {
    ll a, b; cin >> a >> b;
    a--;
    ll sub = 0;
    if (a >= 0) {
        for (int i = 0; i < dig; i++) {
            for (int u = 0; u < 2; u++) {
                for (int s = 0; s < 2; s++) {
                    for (int d = 0; d < 11; d++) {
                        memo[i][u][s][d] = -1;
                    }
                }
            }
        }
        num = to_string(a);

        sub = dp(0, 0, 0, 10);
    }
    for (int i = 0; i < dig; i++) {
        for (int u = 0; u < 2; u++) {
            for (int s = 0; s < 2; s++) {
                for (int d = 0; d < 11; d++) {
                    memo[i][u][s][d] = -1;
                }
            }
        }
    }
    num = to_string(b);
    cout << dp(0, 0, 0, 10)-sub << '\n';
    return 0;
}
