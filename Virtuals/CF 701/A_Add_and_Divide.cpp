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
    ll a, b;
    cin >> a >> b;

    ll ans = LLONG_MAX;
    for (ll i = 0; i < 30; i++){
        ll div = b+i;
        ll dov = a;

        // cout << dov << " " << div << endl;

        ll cnt = div == 1 ? 1 : 0;
        div = (div == 1 ? div+1: div);
        while(dov!=0){
            dov = dov / div;   
            cnt++;
        }

        ans = min(ans, cnt + i);

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
