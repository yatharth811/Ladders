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


void dfs(ll x, ll parent, vector<ll>* adj, map<pair<ll, ll>, ll>& m, ll toStart){
    
    for (auto y: adj[x]){
        if (y!=parent){
            m[{x, y}] = toStart;
            m[{y, x}] = toStart;
            toStart = toStart ^ 2 ^ 5;
            dfs(y, x, adj, m, toStart);
        }
    }

}

void solve(){
    ll n;
    cin >> n;
    vi adj[n];
    map<pair<ll, ll>, ll> m;

    vi deg(n, 0);
    vector<pair<ll, ll>> edges;
    rep(i,1,n){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);

        edges.push_back({a, b});
        deg[a]++;
        deg[b]++;
    }

    for (auto x: deg){
        if (x > 2) {
            cout << -1 << endl;
            return;
        }
    }

    dfs(0, -1, adj, m, 2);
    for (auto x: edges){
        cout << m[x] << " ";
    }

    cout << endl;

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
