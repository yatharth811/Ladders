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
    string s;
    cin >> s;

    ll a = 0, b = 0, c = 0, ans = INT_MAX;
    for (auto x: s){
        if (x == 'a'){
            if (a == 0) a++;
            else{
                a++;
                if (a > b && a > c){
                    ans = min(ans, a+b+c);
                }
                a = 1;
                b = 0;
                c = 0;
            }
        }
        else if (x == 'b' && a!=0){
            b++;
        }
        else if (x == 'c' && a!=0){
            c++;
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << endl;
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
