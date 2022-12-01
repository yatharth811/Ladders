#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=a;i>b;i--)
#define endl '\n'

const ll MAX = INT_MAX;
const ll MIN = INT_MIN;
const ll MOD = 1e9 + 7;

ll ceil(ll a, ll b) {
    return (a + b - 1) / b; 
}

void solve(){
    ll n, q, k;
    cin >> n >> q >> k;
    vi a(n);
    rep(i,0,n){cin >> a[i];}

    vi ans(n);
    rep(i,1,n-1){
        ans[i] = max(a[i+1] - a[i-1] - 2, 0ll);
    }
    ans[0] = a[1] - 2;
    ans[n-1] = k+1 - a[n-2] - 2;

    vi pre(n);
    pre[0] = ans[0];
    rep(i,1,n){
        pre[i] = pre[i-1] + ans[i];
    }


    while(q--){
        ll l, r;
        cin >> l >> r;
        l--;
        r--;

        if (l == r) cout << k-1 << endl;
        else{
            cout << pre[r-1] - pre[l] + (a[l+1]-2) + max((k+1 - a[r-1]-2), 0ll) << endl;
        }
    }

}


int main() {
    FAST;
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
