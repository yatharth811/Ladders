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
    vector<vector<ll>> a(n, vector<ll>(n, 0));
    vi temp;
    bool flag = true;
    rep(i,0,n){
        ll sum = 0;
        rep(j,i,n){
            cin >> a[i][j];
            sum += a[i][j];
        }
        temp.push_back(sum);
    }

    ll pp = 0;
    while(pp < n){
        if (a[pp][pp]==2){
            cout << 0 << endl;
            return;
        }
        pp++;
    }


    rep(i,0,n){
        ll prev = -1;

        rep(j,i,n){
            if (a[i][j] == 2){
                prev = i;
            }

            if (a[i][j] == 1 && prev!=-1){
                cout << 0 << endl;
                return;
            }
        }
    }

    // types 1: 012, 2:120, 3: 102
    ll z=-1,o=-1,t=INT_MAX;

    ll which = -1;
    rep(i,0,n-1){
        if (temp[i]!=0){
            which = i;
            break;
        }
    }




    rep(i,1,n){
        rep(j,1,n){
            if (a[i][j]==1 && a[i-1][j] == 2 && a[i][j-1]==1 && a[i-1][j-1]==1){
                cout << 0 << endl;
                return;
            }
        }
    }



    if (which == -1){
        cout << (1 << n) << endl;
        return;
    }




    // find 1
    rep(j,0,n){
        if (a[which][j] == 1) o = max(j, o);
        if (a[which][j] == 2) t = min(t, j);
    }

    if (t==INT_MAX){
        cout << 2 * (1 << (n-o-1-which)) << endl;
    }
    else{
        if (o!=-1 && t-o == 1){
            cout << 2 * (1 << (n-t-1-which)) << endl;
        }
        else if (o!=-1){
            cout << ((1<<(t-o+1-which)) - 2) * (1 << (n-t-1-which))<< endl;
        }
        else{
            cout << (t-which)*(t+1-which)*((1 << (n-t-1-which))) << endl;
        }
    }
}


int main() {
    FAST;
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
