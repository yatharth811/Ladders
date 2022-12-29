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

ll multi(ll a, ll b){
    a = a%MOD;
    b = b%MOD;
    return (a*b)%MOD;
}

void solve(){
    ll n;
    cin >> n;


    ll ans = multi(multi(multi(n, n+1), 2*n+1), 166666668);
    n--;
    ans = ans%MOD +  multi(multi(multi(n, n+1), 2*n+1), 166666668) + multi(multi(n, n+1), 500000004);

    cout << multi(ans, 2022) << endl;
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
