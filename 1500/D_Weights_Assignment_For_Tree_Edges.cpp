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
    ll n, root = -1;
    cin >> n;
    vi parent(n+1), perm(n+1);
    rep(i,1,n+1){cin >> parent[i]; if (parent[i] == i) root = i;}
    rep(i,1,n+1){cin >> perm[i];}
    vi dis(n+1, -1);
    vi ans(n+1, 0);

    if (perm[1] != root){cout<<-1<<endl; return;}
    
    dis[root] = 0;
    rep(k,2,n+1){
        ll i = perm[k];
        ll j = perm[k-1];
        if (dis[parent[i]]==-1){
            cout << -1 << endl;
            return;
        }
        else{
            dis[i] = dis[j] + 1;
            ans[i] = dis[j] - dis[parent[i]] + 1;
            // cout << i << " " <<  dis[i] << " " << parent[i] << " " << dis[parent[i]] << endl;
        }
    }
    rep(i,1,n+1){
        cout << ans[i] << " ";
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
