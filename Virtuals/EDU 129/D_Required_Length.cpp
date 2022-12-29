#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ll;
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
    ll n, x;
    cin >> n >> x;

    // bfs ? on x and transitions being its digits; 

    map<ll, bool> vis;
    map<ll, ll> dis;
    queue<ll> q;
    q.push(x);
    dis[x] = 0;
    vis[x] = true;

    ll timer = 0;
    while(!q.empty()){
        auto g = q.front();
        // cout << g << endl;
        q.pop();

        // transitions
        vi trans;
        auto k = g;
        ll cnt = 0;
        while(g!=0){
            trans.push_back(g%10);
            g = g/10;
            cnt++;
        }

        if (cnt == n){
            cout << dis[k] << endl;
            return;
        }


        for (auto y: trans){
            auto flag = vis.find(y*k)==vis.end();
            if (flag && y <= (1e19)/k){
                vis[y*k] = true;
                q.push(y*k);
                dis[y*k] = dis[k] + 1;
            }
        }

    }

    cout << -1 << endl;

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
