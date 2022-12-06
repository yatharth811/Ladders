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
    ll ans = 0;
    for (ll i = 1; i*i <= 2*n+1; i+=2){
        if (i <= (i*i)/2 && (i*i)/2 <= n-1){
            ans++;
        }
    }
    cout<< ans << endl;
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
