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


ll msqt(ll x){
    ll l = 0, r = x;

    while(r-l > 1){
        ll m = l + (r-l)/2;
        if (m*m <= x) l = m;
        else r = m;
    }

    return l;

}

void solve(){
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    for (ll i = 1; i <= msqt(x); i++){
        ans += max((min((x/i)-1, y)-i), 0ll);
    }
    cout << ans << endl;
}


int main() {
    FAST;
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
