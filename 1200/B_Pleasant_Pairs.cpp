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
    ll n;
    cin >> n;
    map<ll, ll> m;
    vi a(n+1);
    rep(i,1,n+1){cin >> a[i]; m[a[i]]++;}

    ll ans = 0;

    rep(j,2,n+1){

        for (ll x = a[j]; x <= 2*n; x+=a[j]){
            ll idx = x - j;

            if (idx > 0 && idx < j){
                ans += ((a[idx]*a[j]) == x);
            }

        }


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
