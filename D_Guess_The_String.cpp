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

    // window remains from 1 to n
    ll i = 1, j = 1;

    vector<char> s(n+1);

    while(j++ <= n){
        cout << "? 2 " << i << " " << j << endl;
        ll res;
        cin >> res;

        if (res == j){
            cout << "? 1 " << j << endl;
            cin >> s[j];
        }
        else{

        }

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
