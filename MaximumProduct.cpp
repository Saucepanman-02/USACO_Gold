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

string low, high;
const int dig = 20;

ll memo[dig][2][2][2];
string btrack[dig][2][2][2];

ll dp(int pos, bool under, bool above, bool start) {
    if (pos == dig) {
        if (!start) {
            return 0;
        }
        return 1;
    }
    if (memo[pos][under][above][start] != -1) {
        return memo[pos][under][above][start];
    }
    int l = 0;
    if (!above) {
        l = low[pos]-'0';
    }
    int h = 9;
    if (!under) {
        h = high[pos]-'0';
    }
    /*
    if (l == 0 && h == 1) {
        string debug = "st";
    }*/
    ll mx = -1;
    int d = -1;
    for (int i = l; i <= h; i++) {
        if (i == 0 && !start) {
            continue;
        }
            if (mx < i*dp(pos+1, (under || i < h), (above || i > l), start || (i > 0))) {
                mx = i*dp(pos+1, (under || i < h), (above || i > l), start || (i > 0));
                d = i;
                string st = ""; ;
                if (pos != dig-1) {
                    st = btrack[pos+1][(under || i < h)][above || i > l][start || i > 0];
                }
                reverse(st.begin(), st.end());
                st.push_back(d+'0');
                reverse(st.begin(), st.end());
                btrack[pos][under][above][start] = st;
            }
    }
    if (!start && 0 == l && 0 <= h) {
        if ( mx < dp(pos+1, under || (0 < h), (above), 0)) {
            mx = dp(pos+1, under||(0 < h), above, 0);
            btrack[pos][under][above][0] = btrack[pos+1][under||(0 < h)][above][0];
        }
    }
    return (memo[pos][under][above][start] = mx);
}
int main() {
    ll a, b; cin >> a >> b;
    for (int i = 0; i < dig; i++) {
        low.push_back(a%10+'0');
        high.push_back(b%10+'0');
        a /= 10;
        b /= 10;
    }
    for (int i = 0; i < dig; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    memo[i][j][k][l] = -1;
                }
            }
        }
    }
    reverse(low.begin(), low.end());
    reverse(high.begin(), high.end());
    dp(0, 0, 0, 0);
    cout << btrack[0][0][0][0] << '\n';
    return 0;
}
