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

bool check(ll mid, vector<vector<ll>> &map){

    ll n = map.size(), m = map[0].size();
    vector<vector<ll>> toy(n, vector<ll>(m));

    rep(i,0,n){
        rep(j,0,m){
            toy[i][j] = (map[i][j] >= mid);
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(m, toy[0][0]));
    rep(i,1,n){
        dp[i][0] = toy[i][0] + dp[i-1][0];
    }
    rep(j,1,m){
        dp[0][j] = toy[0][j] + dp[0][j-1];
    }

    rep(i,1,n){
        rep(j,1,m){
            dp[i][j] = toy[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    rep(i,mid-1,n){
        rep(j,mid-1,m){
            if (dp[i][j] - (j>=mid ? dp[i][j-mid] : 0) - (i>=mid ? dp[i-mid][j] : 0) + (i >=mid && j >= mid ? dp[i-mid][j-mid] : 0) == mid*mid) return true;
        }
    }


    return false;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> map(n, vector<ll>(m));
    rep(i,0,n){rep(j,0,m){cin >> map[i][j];}}

    ll l = 1, r = min(n, m) + 1;

    while(r-l > 1){
        ll mid = l + (r-l)/2;
        if (check(mid, map)) l = mid;
        else r = mid;

    }

    cout << l << endl;


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
