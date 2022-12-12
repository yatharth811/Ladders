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
    ll n, m;
    cin >> n >> m;

    vi adj[n+1];
    while(m--){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vi a(n);
    rep(i,0,n){a[i] = i+1;}

    ll i = 0, j = 0, ans = 0;
    map<ll, ll> mp;


    while(j < n){
        // cout << i << " " << j << endl;
        mp[a[j]]++;
        ll toWhere = -1;
        for (auto x: adj[a[j]]){
            if (mp[x]){
                toWhere = max(toWhere, x);
            }
        }

        if (toWhere==-1){
            ans += j - i + 1;
        }
        else{
            rep(k,i,toWhere){
                mp[k]--;
            }
            i = toWhere;
            ans += j - i + 1;
        }

        // cout << i << " " << j << endl;
       
        j++;

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
