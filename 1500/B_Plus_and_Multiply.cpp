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
    ll n, a, b;
    cin >> n >> a >> b;
    
    // every number of the form a^x + by

    if (a==1){
        cout << (n%b == 1 || b == 1? "Yes" : "No") << endl;
        return;
    }


    ll i = 1;
    while(i <= n){
        if ((n-i)%b == 0){
            cout << "Yes" << endl;
            return;
        }

        i*=a;
    }   

    cout << "No" << endl;

    
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