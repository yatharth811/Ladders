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
    rep(i,0,n){cin >> a[i];}

    sort(a.begin(), a.end());


    ll l = -1, r = -1, diff = INT_MAX;

    rep(i,1,n){
        if (a[i] - a[i-1] < diff){
            l = i-1;
            r = i;
            diff = a[i] - a[i-1];
        }
    }

    vi b(n);
    b[0] = a[l];
    b[n-1] = a[r];

    ll idx = 1;
    rep(i,r+1,n){
        b[idx++] = a[i];
    }
    rep(i,0,l){
        b[idx++] = a[i];
    }

    rep(i,0,n){
        cout << b[i] << " \n"[i==n-1];
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
