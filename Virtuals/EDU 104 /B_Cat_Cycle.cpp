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
    ll n, k;
    cin >> n >> k;
    if (n%2){
        ll g = n/2;
        ll rom = ((k%n) + ((k-1)/g))%n;
        if (rom==0){
            cout << n << endl;
        }
        else{
            cout << rom << endl;
        }
    }
    else{
        if (k%n == 0){
            cout << n << endl;
        }
        else{
            cout << k%n << endl;
        }
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
