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

ll bs(vi &a, ll x){
    ll n = a.size();
    ll l = -1, r = n;
    while(r-l > 1){
        ll m = l + (r-l)/2;
        if (a[m] <= x){l = m;}
        else{r=m;}
    }

    return l;
}

void solve(){
    ll n;
    cin >> n;
    vi a(n);
    map<ll, ll> m;
    ll maxi = -1;
    rep(i,0,n){cin >> a[i]; m[a[i]]++; maxi = max(maxi, m[a[i]]);} 

    vi b;


    for (auto [_, y]: m){
        b.push_back(y);
    }

    sort(b.begin(), b.end());
    vi pre(b.size(), 0), suf(b.size(), 0);
    pre[0] = b[0];
    suf[b.size()-1] = b.back();
    rep(i,1,b.size()){
        pre[i] = pre[i-1] + b[i];
    }

    // per()

    ll ans = INT_MAX;
    for (auto x: b){
        ll l = bs(b, x-1);
        ll r = l+1;
        if (l == -1){
            ans = min(ans, pre.back() - ((ll)pre.size())*x);
        }
        else {
            ans = min(ans, pre[l] + (pre.back() - pre[l]) - ((ll)b.size()-1-l)*x);
        }
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
