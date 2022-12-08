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
    ll freq[3] = {0};
    rep(i,0,n){cin >> a[i]; freq[a[i]%3]++;}
    ll ans = 0;
    // cout << freq[0] << " " << freq[1] << " " << freq[2] << endl;
    

    if (freq[0]!=n/3 || freq[1]!=n/3 || freq[2]!=n/3){
        vi sad;
        rep(i,0,3){if (freq[i] > n/3) sad.push_back(i);}
        

        if (sad.size()==2){
            if (sad[0] == 0 && sad[1] == 1){
                cout << 2*(freq[0] - n/3) + (freq[1] - n/3) << endl;
            }
            else if (sad[0] == 0 && sad[1]==2){
                cout << (freq[0] - n/3) + 2*(freq[2] - n/3) << endl;
            }
            else{
                cout << 2*(freq[1] - n/3) + (freq[2] - n/3) << endl;
            }
        }
        else{
            if (sad[0] == 0){
                cout << (n/3-freq[1]) + 2*(n/3 - freq[2]) << endl;
            } 
            else if (sad[0]==1){
                cout << (n/3-freq[2]) + 2*(n/3 - freq[0]) << endl;
            }
            else{
                cout << (n/3-freq[0]) + 2*(n/3 - freq[1]) << endl;
            }

        }

    }
    else{
        cout << 0 << endl;
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
