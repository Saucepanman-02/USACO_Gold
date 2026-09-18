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

string num1, num2;
const int dig = 2005;
const int MOD = 1e9+7;
int m;
ll memo[dig][dig][2][2];
int d;
int pw[dig];

int n;

ll dp(int pos, int mod, bool under, bool above) {
    if (pos == num1.size()){
        return (mod==0);
    }
    if (memo[pos][mod][under][above] != -1) {
        return memo[pos][mod][under][above];
    }
    int l = 0;
    if (!above) {
        l = num1[pos]-'0';
    }
    int h = 9;
    if (!under) {
        h = num2[pos]-'0';
    }
    ll cur = 0;
    if (pos%2 == 0) {
        for (int i = l; i <= h; i++) {
            if (i == d) {
                continue;
            }
            cur += dp(pos+1, (mod-(i*pw[n-1-pos])%m+m)%m,  under || (i < h), above || (i > l));
            cur %= MOD;
        }
    }else {
        if (d >= l && d <= h) {
            cur += dp(pos+1, (mod-(d*pw[n-1-pos])%m+m)%m,  under || (d < h), above || (d > l));
            cur %= MOD;
        }
    }
    return (memo[pos][mod][under][above] = cur);
}

int main() {
    cin >> m >> d;
    cin >> num1 >> num2;
    n = num1.size();
    for (int i = 0; i < dig; i++) {
        for (int r = 0; r < dig; r++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    memo[i][r][j][k] = -1;
                }
            }
        }
    }
    pw[0] = 1;
    for (int i = 1; i < dig; i++) {
        pw[i] = (pw[i-1]*10)%m;
    }
    cout << dp(0, 0, 0, 0) << '\n';
    return 0;
}
