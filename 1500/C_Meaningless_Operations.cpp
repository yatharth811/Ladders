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
    
    vi a;
    ll x = n, sum = 0;
    while(x!=0){
        a.push_back(x&1);
        sum += (x&1);
        x = x >> 1;
    }
    reverse(a.begin(), a.end());

    if (sum == a.size()){
        // print largest divisor
        ll div = 1;
        for (ll i = 2; i*i <= n; i++){
            if (n%i == 0){
                div = max({div, i, n/i});
            } 
        }

        cout << div << endl;

    }
    else{
        ll num = 0;
        rep(i,0,a.size()){
            num += (1 << i);
        }
        cout << num << endl;
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
