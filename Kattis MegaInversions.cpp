#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define LSB(x) ((x) & -(x))

class FenwickTree{
private:
    vector<ll> ft;
public:
    FenwickTree(int m){ft.resize(m+1, 0);}

    ll psq(int j){
        ll sum = 0;
        for (; j; j -= LSB(j)){
            sum += ft[j];
        }
        return sum;
    }

    ll rsq(int i, int j){
        return psq(j)-psq(i-1);
    }
    void update(int i, ll v){
        int sz = ft.size();
        for (; i < sz; i += LSB(i)){
            ft[i] += v;
        }
    }
};

int main(){
    speedup
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    FenwickTree T1(n), T2(n);
    reverse(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += T2.psq(a[i]-1);
        ll upd = T1.psq(a[i]-1);
        T1.update(a[i], 1);
        T2.update(a[i], upd);
    }
    cout << ans << endl;
    return 0;
}
