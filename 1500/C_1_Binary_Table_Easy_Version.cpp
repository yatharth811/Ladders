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


void cnt2(ll i, ll j, vector<vector<ll>> &a, vector<vector<ll>>& ans){

    vector<pair<ll, ll>> vp;
    vector<pair<ll, ll>> vs;
    rep(k,0,2){
        rep(l,0,2){
            if (a[i+k][j+l] == 1){
                vp.push_back({i+k, j+l});
            }
            else{
                vs.push_back({i+k, j+l});
            }
        }
    }

    ans.push_back({vp[0].first, vp[0].second, vs[0].first, vs[0].second, vs[1].first, vs[1].second});
    ans.push_back({vp[1].first, vp[1].second, vs[0].first, vs[0].second, vs[1].first, vs[1].second});

    a[i][j] = 0;
    a[i+1][j] = 0;
    a[i][j+1] = 0;
    a[i+1][j+1] = 0;
}

void cnt1(ll i, ll j, vector<vector<ll>>& a, vector<vector<ll>>& ans){

    vector<pair<ll, ll>> vp;
    vector<pair<ll, ll>> vs;

    rep(k,0,2){
        rep(l,0,2){
            if (a[i+k][j+l] == 1){
                vp.push_back({i+k, j+l});
            }
            else{
                vs.push_back({i+k, j+l});
            }
        }
    }

    ans.push_back({vp[0].first, vp[0].second, vs[0].first, vs[0].second, vs[1].first, vs[1].second});
    a[vp[0].first][vp[0].second] = 0;
    a[vs[0].first][vs[0].second] = 1;
    a[vs[1].first][vs[1].second] = 1;
    
    cnt2(i, j, a, ans);
}


void cnt3(ll i, ll j, vector<vector<ll>>& a, vector<vector<ll>>& ans){
    vector<ll> he;
    rep(k,0,2){
        rep(l,0,2){
            if (a[i+k][j+l] == 1){
                he.push_back(i+k);
                he.push_back(j+l);
            }
        }
    }

    ans.push_back(he);
    a[i][j] = 0;
    a[i+1][j] = 0;
    a[i][j+1] = 0;
    a[i+1][j+1] = 0;
}

void cnt4(ll i, ll j, vector<vector<ll>> &a, vector<vector<ll>>& ans){

    ans.push_back({i, j, i, j+1, i+1, j});
    a[i][j] = 0;
    a[i][j+1] = 0;
    a[i+1][j] = 0;
    cnt1(i, j, a, ans);

}


void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n+1, vector<ll>(m+1));

    vector<string> viso(n+1);
    rep(i,1,n+1){
        cin >> viso[i];
    }

    rep(i,1,n+1){
        rep(j,0,m){
            a[i][j+1] = viso[i][j] - '0';
        //    std::cout << a[i][j+1] << " ";
        }
        // std::cout << endl;

    }

    vector<vector<ll>> ans;

    rep(i,1,n){
        rep(j,1,m){
            ll cnt = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1];

            if (cnt == 0){
                continue;
            }
            else if (cnt == 1){
                cnt1(i, j, a, ans);
            }
            else if (cnt == 2){
                cnt2(i, j, a, ans);
            }
            else if (cnt == 3){
                cnt3(i, j, a, ans);
            }
            else{
                cnt4(i, j, a, ans);
            }

            // std::cout << cnt << endl;

        }
    }
 

    ll x = ans.size();
    std::cout << x << endl;
    rep(i,0,x){
        rep(j,0,6){
           std:: cout << ans[i][j] << " ";
        }
        std::cout << endl;
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
