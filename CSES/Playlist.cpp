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
    vi a(n);
    rep(i,0,n){cin >> a[i];}

    ll ans = 1;
    multiset<ll> s;
    ll i = 0, j = 1;
    s.insert(a[i]);

    while(j < n){

        if (s.find(a[j])==s.end()){
            s.insert(a[j++]);
            ans = max(ans, (ll)s.size());
        }
        else{
            while(a[i]!=a[j]){
                s.erase(s.find(a[i++]));
            }
            s.erase(s.find(a[i++]));
            s.insert(a[j++]);
        }
        
    }

    cout << ans << endl;
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
