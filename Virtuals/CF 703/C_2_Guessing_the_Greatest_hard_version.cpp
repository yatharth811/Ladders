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
    

    ll l = 1, r = n;
    ll pos;

    while(r-l > 1){
        ll mid = l + (r-l)/2;

        // figure out where the second most lies in whole window
        cout << "? " << l << " " << r << endl;
        cin >> pos;

        // now either pos lies to <= mid or > mid
        ll res;
        if (pos <= mid){
            cout << "? " << l << " " << mid << endl;
            cin >> res;
            if (res == pos){
                // max lies in this window
                r = mid;
            }
            else{
                l = mid;
            }

        }
        else{
            cout << "? " << mid << " " << r << endl;
            cin >> res;

            if (res == pos){
                // max lies in this window
                l = mid;
            }
            else{
                r = mid;
            }

        }

    }

    cout << "? " << l << " " << r << endl;
    cin >> pos;
    if (l == pos){
        cout << "! " << r << endl;
    }
    else{
        cout << "! " << l << endl;
    }


}


int main() {
    // FAST;
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
