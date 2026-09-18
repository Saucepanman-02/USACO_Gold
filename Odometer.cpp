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

const int dig = 20;
const int mx = 50;
ll memo[dig][mx][2][2];


int digit(ll n, int pos) {
    ll pw = pow(10, pos);
    return (n/pw)%10;
}

void reset() {
    for (int i = 0; i < dig; i++) {
        for (int j = 0; j < mx; j++) {
            for (int r = 0; r < 2; r++) {
                for (int l = 0; l < 2; l++) {
                    memo[i][j][r][l] = -1;
                }
            }
        }
    }
}

int t1, t2;
string num;

ll dp(int pos, int cnt, bool flag, int start) {
    if (pos == num.size()) {
        if (!start)
            return 0;
        if (t2 == -1) {
            if (cnt <= 20) {
                return 1;
            }else {
                return 0;
            }
        }
        if (t2 != -1) {
            if (cnt == 20) {
                return 1;
            }else {
                return 0;
            }
        }
    }
    if (memo[pos][cnt][flag][start] != -1) {
        return memo[pos][cnt][flag][start];
    }
    int lim = 9;
    if (!flag) {
        lim = num[pos]-'0';
    }
    ll cur = 0;
    if (t2 == -1) {
        for (int i = 0; i <= lim; i++) {
            if (start || (i != 0)) {
                cur += dp(pos+1, cnt+(i == t1? -1: 1), flag || (i < lim), 1);
            }
        }
        if (!start)
            cur += dp(pos+1, cnt, flag || (0 < lim), 0);
    }else {
        if (start || t1 != 0) {
            if (t1 <= lim) {
                cur += dp(pos+1, cnt-1, flag || (t1 < lim), 1);
            }
        }
        if (start || t2 != 0) {
            if (t2 <= lim) {
                cur += dp(pos+1, cnt+1, flag || (t2 < lim), 1);
            }
        }
        if (!start && lim != 0) {
            cur += dp(pos+1, cnt, 1, 0);
        }
    }
    return (memo[pos][cnt][flag][start] = cur);
}

ll count(ll a) {
    num = to_string(a);
    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        reset();
        t1 = i; t2 = -1;
        ans += dp(0, 20, 0, 0);
    }
    ll dup = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = i+1; j < 10; j++) {
            reset();
            t1 = i, t2 = j;
            dup += dp(0, 20, 0, 0);
        }
    }
    //cout << ans << ' ' << dup << '\n';
    return ans-dup;
}
int main() {
    usopen("odometer")
    ll a, b; cin >> a >> b;
    cout << count(b)-count(a-1) << '\n';
    return 0;
}
