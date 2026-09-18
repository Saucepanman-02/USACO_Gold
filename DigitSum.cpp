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

ll memo[dig][2];
ll cnt[dig][2];

ll dp(int pos, bool under) {
    if (pos == dig) {
        return 0;
    }
    if (memo[pos][under] != -1) {
        return memo[pos][under];
    }
    int h = 9;
    if (!under) {
        h = num[pos]-'0';
    }
    if (pos == dig-1) {
        cnt[pos][under] = h+1;
        return memo[pos][under] = (h*(h+1))/2;
    }
    ll cur = 0;
    for (int i = 0; i <= h; i++) {
        cur += (dp(pos+1, under || i < h)+i*cnt[pos+1][under || i < h]);
        cnt[pos][under] += cnt[pos+1][under||i<h];
    }
    return (memo[pos][under] = cur);
}

int main() {
    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        a--;
        num = "";
        for (int i = 0; i < dig; i++) {
            memo[i][0] = memo[i][1] = -1;
            cnt[i][0] = cnt[i][1] = 0;
            num.push_back(a%10+'0');
            a /= 10;
        }
        reverse(num.begin(), num.end());
        ll sub = dp(0, 0);
        num = "";
        for (int i = 0; i < dig; i++) {
            memo[i][0] = memo[i][1] = -1;
            cnt[i][0] = cnt[i][1] = 0;
            num.push_back(b%10+'0');
            b /= 10;
        }
        reverse(num.begin(), num.end());
        cout << dp(0, 0)-sub << '\n';
    }
    return 0;
}
