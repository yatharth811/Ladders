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
    vector<vector<ll>> a(n+1, vector<ll>(n+1, -3));    
    ll hm = (n*(n-1))/2;
    if (n%2){

        rep(i,0,hm){
            if (i&1){cout << -1 << " ";}
            else cout << 1 << " "; 
        }
        cout << endl;
    }
    else{
        vi score(n+1, 0);
        ll row = 1, col = n;
        while(row < col){
            a[row][col] = 0;
            row++;
            col--;
        }

        // cout << row << col << endl;

        ll what = +1;
        for (ll i = 0; i < row; i++){
            what = 1;
            for (ll j = i+1; j <= n; j++){
                if (a[i][j] == 0){
                    what = 1;
                }
                else{
                    a[i][j] = what;
                    what = what*-1;
                }

            }
        }

        for (ll i = row; i < n; i++){
            what = -1;
            for (ll j = i+1; j <= n; j++){
                a[i][j] = what;
                what = what*-1;
            }
        }


        rep(i,1,n){
            rep(j, i+1, n+1){
                cout << a[i][j] << " ";
                
                if (a[i][j] == 0){
                    score[i]++;
                    score[j]++;
                }
                else if (a[i][j] == 1){
                    score[i] += 3;
                }
                else {
                    score[j] += 3;
                }
            }
            // cout << endl;

        }


        cout<< endl;
        // cout << "CHECK:" << endl;
        // rep(i,1,n+1){
        //     cout << score[i] << " ";
        // }
        // cout << endl;
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
