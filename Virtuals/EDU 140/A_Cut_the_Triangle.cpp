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
    vector<pi> a;
    map<ll, ll> m, n;
    rep(i,0,3){
        ll x, y;
        cin >> x >> y;
        m[x]++;
        n[y]++;
        a.push_back({x, y});
    }


    if (m.size() <= 2 && n.size() <=2){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
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
