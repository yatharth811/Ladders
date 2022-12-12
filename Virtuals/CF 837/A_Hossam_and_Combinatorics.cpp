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
    vi a(n);
    ll mini = INT_MAX, maxi = INT_MIN;
    map<ll, ll> m;
    rep(i,0,n){cin >> a[i]; mini = min(mini, a[i]); maxi = max(maxi, a[i]); m[a[i]]++;}

    ll d = maxi - mini;

    if (d==0){
        cout << (n*(n-1)) << endl;
        return;
    }



    ll ans = 0;
    rep(i,0,n){
        ans += m[a[i]-d] + m[a[i]+d];
        // m[a[i]]++;
    }

    cout << ans <<endl;

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
