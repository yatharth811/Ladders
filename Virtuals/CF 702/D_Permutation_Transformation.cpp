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

ll dp[101];

void build(vi &a, ll depth){

    if (a.size()==0) return;

    ll maxi = INT_MIN, ind = -1, n = a.size();

    rep(i,0,n){
        if (a[i] > maxi){
            maxi = a[i];
            ind = i;
        }
    }

    dp[maxi] = depth;


    vi b, c;

    rep(i,0,ind){
        b.push_back(a[i]);
    }
    rep(i,ind+1, n){
        c.push_back(a[i]);
    }

    build(b, depth+1);
    build(c, depth+1);

}

void solve(){

    memset(dp ,0, sizeof dp);
    ll n;
    cin >> n;
    vi a(n);
    rep(i,0,n){cin >> a[i];}

    build(a, 0);

    rep(i,1,n+1){
        cout << dp[a[i-1]] << " "; 
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
