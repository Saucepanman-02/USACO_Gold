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
#define pid pair<int, db>

int n, k;
vi c;
const int MAX = 505;
bitset<MAX> memo[MAX][MAX];
int vis[MAX][MAX];

bitset<MAX> dp(int pos, int sum) {
    if (sum == 0 && pos >= 0) {
        memo[pos][sum][0] = 1;
        return memo[pos][sum];
    }
    if (pos==0 && sum > 0) {
        return memo[pos][sum];
    }
    if (vis[pos][sum]) {
        return memo[pos][sum];
    }
    vis[pos][sum] = true;
    bitset<MAX> a = dp(pos-1, sum);
    if (sum >= c[pos-1]) {
        bitset<MAX> b = dp(pos-1, sum-c[pos-1]);
        for (int j = k; j >= c[pos-1]; j--) {
            if (b[j-c[pos-1]]) {
                b.set(j);
            }
        }
        for (int i = 0; i <= k; i++) {
            a[i] = a[i] || b[i];
        }
    }
    return (memo[pos][sum]=a);
}


int main() {
    speedup
    cin >> n >> k;
    c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    bitset<MAX> temp;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            vis[i][j] = false;
            memo[i][j] = temp;
        }
    }
    bitset<MAX> final = dp(n, k);
    vi ans;
    for (int i = 0; i <= k; i++) {
        if (final[i]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int u: ans) {
        cout << u << ' ';
    }
    cout << endl;
    return 0;
}
