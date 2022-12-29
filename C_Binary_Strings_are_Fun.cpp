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
    string s;
    cin >> s;

    ll o = (s[0]=='1');
    ll z = (s[0]=='0');

    ll ans = 0;
    
    rep(i,1,n){
        if (s[i]=='0'){
            o++;
            // auto need = i + 1 - o;



        }
        else {
            z++;


        }


        // ans += 
        // if 

    }

    cout << o << " " << z << endl;

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
