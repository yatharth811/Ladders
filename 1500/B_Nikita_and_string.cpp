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
    string s;
    cin >> s;   

    ll n = s.size();
    vi pre(n+2, 0), suf(n+2);

    rep(i,1,n+1){
        pre[i] = pre[i-1] + (s[i-1] == 'a');
        suf[n-i+1] = suf[n-i+2] + (s[n-i] == 'a');
    }

    ll ans = 0;
    for (ll i = 0; i <= n; i++){
        ll cntb = 0;
        for (ll j = i+1; j <= n+1; j++){
            ans = max(ans, pre[i] + suf[j] + cntb);
            cntb += (j-1 < n && s[j-1] == 'b' ? 1 : 0);
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
