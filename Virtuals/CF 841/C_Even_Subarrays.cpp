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
    ll maxi  = INT_MIN;
    rep(i,0,n){cin >> a[i]; maxi = max(maxi, a[i]);}
    
    vi pre(n, a[0]);
    for (ll i = 1; i < n; i++){
        pre[i] = pre[i-1] ^ a[i];
    }

    auto cnt = [&] (vi &pre){
        ll ub = 1 << (64-(__builtin_clzll(maxi)));
        vi mp(ub, 0);
    
        ll ans = 0;
        for (ll i = 0; i < n; i++){
            ll m = 0;
            while(m*m < ub){
                if (pre[i] == m*m) ans++;
                ans += mp[(m*m)^pre[i]];
                m++;
            }
            mp[pre[i]]++;
        }

        return ans;
    };

    ll ggs = (n*(n+1))/2 - cnt(pre);
    cout << ggs << endl;
    
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
