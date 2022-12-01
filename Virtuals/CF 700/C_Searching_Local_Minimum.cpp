#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=a;i>b;i--)

const ll MAX = INT_MAX;
const ll MIN = INT_MIN;
const ll MOD = 1e9 + 7;

ll ceil(ll a, ll b) {
    return (a + b - 1) / b; 
}

void solve(){
    ll n;
    cin >> n;
    ll l = 0, r = n+1;

    while(true){
        
        ll mid = l + (r-l)/2;
        ll a = INT_MAX, b, c = INT_MAX;
            
        cout << "? " << mid << endl;
        cin >> b;

        if (mid!=1){
            cout << "? " << mid-1 << endl;
            cin >> a;
        }
        
        if (mid!=n){
            cout << "? " << mid+1 << endl;
            cin >> c;
        }

        if (b < min(a, c)){
            cout << "! " << mid << endl;
            break;
        }
        else if (b > a){
            r = mid;
        }
        else{
            l = mid;
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
