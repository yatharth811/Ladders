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
    ll n, s = 0;
    cin >> n;
    vi a(n);
    rep(i,0,n){cin >> a[i]; s += a[i];}

    if (s&1){
        ll ans = INT_MAX;
        for (auto &x: a){
            ll cnt = 0;
            if (x&1){
                while(x&1){
                    cnt++;
                    x = x >> 1;
                }
            }
            else{
                while(!(x&1)){
                    cnt++;
                    x = x >> 1;
                }
            }
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
    else{
        cout << 0 << endl;
    }

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
