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
    vi x;
    rep(i,0,n){
        cin >> a[i];
        if (a[i]==0) x.push_back(i);
    }

    ll ans = 0;
    if (x.size()==0){
        cout << 0 << endl;
    }
    else{
        ll l = 0, r = n-1;
        while(a[l]!=0){
            l++;
        }
        while(a[r]==1){
            r--;
        }

        // jump from l-1 to r
        cout << r + 1 - l + 1 << endl;
    }

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
