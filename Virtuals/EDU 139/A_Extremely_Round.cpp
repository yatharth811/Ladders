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

vi dp(1000000, 0);
void precompute(){
    ll ans = 0;
    rep(i,1,1000000){
        ll cnt = 0;
        ll x = i;
        while(x!=0){
            cnt += (x%10 != 0 ? 1 : 0);
            x = x/10;
        }

        if (cnt == 1) ans++;
        dp[i] = ans;
    }
    // cout << ans << endl;
}


void solve(){
    ll n;
    cin >> n;
    cout << dp[n] << endl;
}

int main() {
    FAST;
    ll t=1;
    cin >> t;
    precompute();
    while(t--){
        solve();
    }
    return 0;
}
