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

void pikachu(ll n){
    ll cs = n%4, wo = n/4;

    if (cs == 0){
        cout << wo << " " << wo  << " " << 2*wo << endl;
    }
    else if (cs  == 1){
        cout << 1 << " " << 2*wo  << " " << 2*wo << endl;
    }
    else if (cs == 2){
        cout << 2 << " " << 2*wo  << " " << 2*wo << endl;
    }
    else{
        cout << 1 << " " << 2*wo+1  << " " << 2*wo+1 << endl;
    }
}



void solve(){
    ll n, k;
    cin >> n >> k;

    if (k == 3){
        pikachu(n);
    }
    else{
        vi a(k, n/k);
        ll rem = n%k;
        
        ll hm = ceil(rem, 2);

        rep(i,0,hm){
            a[i] = 2;
        }

        if (rem&1) a[0] = 1;

        rep(i, hm, 2*hm){
            a[i] = a[i]*2;
        }


        for (auto x: a){
            cout << x << " ";
        }
        cout << endl;

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
