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

bool bs(vi &a, ll x){
    ll n = a.size();
    ll l = -1, r = n;
    while(r-l > 1){
        ll m = l + (r-l)/2;
        if (a[m] <= x){l = m;}
        else{r=m;}
    }

    return (l!=-1 && a[l]==x);
}

void solve(){
    ll x = 1;
    ll n;
    cin >> n;
    vi a;
    while(x*x*x < n){
        a.push_back(x*x*x);
        x++;
    }

    for (auto x: a){
        if (bs(a, n-x)){
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;

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
