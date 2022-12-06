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

ll pwr(ll a, ll b, ll m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll dfs(ll s, vi* adj, vi& visited, map<pair<ll,ll>, ll> &m){
    visited[s] = 1;
    ll ans = 0;
    for (auto x: adj[s]){
        if (visited[x] == -1 && m[{s, x}] == 0){
            ans += 1 + dfs(x, adj, visited, m);
        }
    }
    return ans;

}

void solve(){
    ll n, k;
    cin >> n >> k;

    map<pair<ll, ll>, ll> m;
    vi adj[n];
    rep(i,1,n){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        m[{a, b}] = c;
        m[{b, a}] = c;
    }

    vi visited(n, -1);
    ll ans = (pwr(n, k%(MOD-1), MOD) - (n%MOD))%MOD;

    rep(i,0,n){
        if (visited[i] == -1){
            ll temp = dfs(i, adj, visited, m) + 1;
            ans -= (pwr(temp, k%(MOD-1), MOD) - (temp%MOD))%MOD;
            ans = (ans+MOD)%MOD;
        }
    }

    cout << ans <<endl;
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
