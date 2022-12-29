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

    ll m;
    cin >> m;
    vi b(m);
    rep(i,0,m){cin >> b[i];}


    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    if (b[0] > a[0]){
        cout << "Bob" << endl;
    }
    else{
        cout << "Alice" << endl;
    }

     if (b[0] < a[0]){
        cout << "Alice" << endl;
    }
    else{
        cout << "Bob" << endl;
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
