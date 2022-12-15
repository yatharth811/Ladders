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
    string s;
    cin >> n >> s;

    map<string, ll> m;

    rep(i,1,n){
        if (i > 0 && i < n-2){
            string x = s.substr(i-1, 2);
            string y = s.substr(i+1, 2);
            m[x]++;
            if (m[y]){
                cout << "YES" << endl;
                return;
            }

            // cout << x << endl;
            // cout << y<< endl;
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
