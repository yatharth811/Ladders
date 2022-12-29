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

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    
    ll o = 0, z = 0;
    for (auto x: s){
        if (x == '0'){
            z++;
        }
        else{
            o++;
        }
    } 

    // cout << o << ' ' << z << endl;

    ll l, r;
    l = (1 << o);
    r = (1 << n) - (1 << z) + 1;
    // cout << l <<"  "<< r << endl;
    for (ll i = l; i <= r; i++){
        cout << i << " \n"[i==r];
    }
    // cout << endl;
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
