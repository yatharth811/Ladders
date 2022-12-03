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
    vector<vector<ll>> a(2, vector<ll>(n));
    rep(i,0,2){
        rep(j,0,n){
            cin >> a[i][j];
        }
    }

    if (n==1){
        cout << 0 << endl;
        return;
    }

    vi down(n, 0), up(n, 0);

    down[0] = a[1][0];
    rep(i,1,n){
        down[i] = down[i-1] + a[1][i];
    }

    up[n-1] = a[0][n-1];
    per(i,n-2, -1){
        up[i] = up[i+1] + a[0][i];
    }

    ll ans = min(down[n-2], up[1]);

    rep(i,1,n-1){
        ans = min(ans, max(down[i-1], up[i+1]));
    }

    cout << ans << endl;


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
