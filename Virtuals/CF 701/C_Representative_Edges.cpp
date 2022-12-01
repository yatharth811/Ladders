#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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


bool isEqual(ll a, float b){
    return abs(a - b) <= 1e-4; 
}



void solve(){
    ll n;
    cin >> n;
    vi a(n);
    rep(i,0,n){cin >> a[i];}

    if (n==1 || n == 2){
        cout << 0 << endl;
        return;
    }
    

    ll ans = INT_MAX;
    // choosing starting element
    for (ll i = 0; i < n; i++){ 
        // element which determines the common difference
        for (ll j = i+1; j < n; j++){
            // a[j] = a[i] + (j-i)*d
            float commonDifference = (a[j]-a[i])/(1.0*(j-i));

            ll cnt = 0;
            rep(k,0,i){
                cnt += isEqual(a[k], a[i] + commonDifference*(k-i));
            }

            rep(k,i+1,n){
                cnt += isEqual(a[k], a[i] + commonDifference*(k-i));
            }

            ans = min(ans, n-cnt-1);

        }
    }

    cout << ans << endl;
    
}


int main(){
    FAST;
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
