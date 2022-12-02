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
    ll n, l, r;
    cin >> n >> l >> r;
    vi a(n);
    rep(i,0,n){cin >> a[i];}
    sort(a.begin(), a.end());
    ll ans = 0;

    rep(i,0,n){
        // l <= a[i] + x <= r
        // l - a[i] <= x <= r - a[i]
        ll c = upper_bound(begin(a), end(a), r - a[i]) - begin(a) - 1; // last element with r - a[i]
        ll d = upper_bound(begin(a), end(a), l - a[i] - 1) - begin(a); // first element with l - a[i]
        if (d <= c) ans += c-d+ (d <= i && i <= c ? 0 : 1);
    }

    cout << ans/2 << endl;

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
