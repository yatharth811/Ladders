#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,a,b) for(ll i=a;i<b;i++)

/*
KEYNOTES:
------------------------------------------
merge(X,identity_element) = X
------------------------------------------
------------------------------------------
identity_transformation.combine(X) = X
------------------------------------------
------------------------------------------
ALWAYS: older_update.combine(newer_update)
------------------------------------------
*/

struct node
{
    int v = 9;         //1
    int id;
    // use more variables if you want more information
    // these default values should be identity_element
    node(){}
    node(int val){ // this is the leaf
        v = val;       //2 
    }
    void merge(const node &l,const node &r){ // store the thing you wanna query       
        // v = l.v + r.v;  //3
        // if we wanted the maximum, then we would do
        v = min(l.v,r.v);
        if (v == l.v) id = l.id;
        else id = r.id;
    }
};

struct update
{
    int v = 0;   // 4
    // use more variables if you want more information
    // these default values should be identity_transformation
    update(){}
    update(int val){
        v = val;  // 5
    }
    // combine the current update with the other update (see keynotes)
    void combine(update &other,const int32_t &tl,const int32_t &tr){
        v += other.v; // 6
        
        // you can be sure that the "other" is newer than current
        
    }
    // store the correct information in the node x
    void apply(node &x,const int32_t &tl,const int32_t &tr){
        x.v += (tr - tl + 1) * v;             //7
        
    }
};

struct segtree
{
    int len;
    vector<node> t;
    vector<update> u;
    vector<bool> lazy;
    node identity_element;
    update identity_transformation;
    segtree(int l){
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node();
        identity_transformation = update();
    }
    
    void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr){
        if(!lazy[v]) return;
        int32_t tm = (tl + tr) >> 1;
        apply(v<<1,tl,tm,u[v]);
        apply(v<<1|1,tm+1,tr,u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }
    
    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd){
        if(tl != tr){
            lazy[v] = 1;
            u[v].combine(upd,tl,tr);
        }
        upd.apply(t[v],tl,tr);
    }
    
    template<typename T>
    void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
        if(tl == tr){
            t[v] = arr[tl];
            t[v].id = tl;
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr,v<<1,tl,tm);
        build(arr,v<<1|1,tm+1,tr);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }
    
    node query(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
        if(l > tr || r < tl){
            return identity_element;
        }
        if(tl >= l && tr <= r){
            return t[v];
        }
        pushdown(v,tl,tr);
        int32_t tm = (tl + tr) >> 1;
        node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
        ans.merge(a,b);
        return ans;
    }
    
    // rupd = range update
    void rupd(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
        if(l > tr || r < tl){
            return;
        }
        if(tl >= l && tr <= r){
            apply(v,tl,tr,upd);
            return;
        }
        pushdown(v,tl,tr);
        int32_t tm = (tl + tr) >> 1;
        rupd(v<<1,tl,tm,l,r,upd);
        rupd(v<<1|1,tm+1,tr,l,r,upd);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }
    
    public:
    template<typename T>
    void build(const T &arr){
        build(arr,1,0,len-1);
    }
    node query(const int32_t &l,const int32_t &r){
        return query(1,0,len-1,l,r);
    }
    void rupd(const int32_t &l,const int32_t &r,const update &upd){
        rupd(1,0,len-1,l,r,upd);
    }
};

string func(string str, int k)
{ 
//    string str;cin>>str;
//    int k;cin>>k;
   vector<int>v;
   int p1=0,p2=1;
   while(k>0){
       if(p2-p1>k){
           v.push_back(str[p1]);
           p1++;
           p2=p1+1;
        }
        if(v.size()==0&&str[p2]=='0'){
                p2++;
                continue;
        }
        if(str[p2]<str[p1]){
                k-=(p2-p1);
                p1=p2;
        }
        p2++;
   }
   rep(i,p1,str.size())
   v.push_back(str[i]);
   
    string result = "";

   for(auto x:v)result += (char)x;
//    cout<<(char)x;
//    cout<<"\n";
    return result;
}


string removeKdigits(string num, ll k)
{
    ll n = num.size();
	stack<char> st;

	for (char c : num) {
		while (!st.empty() && k > 0 && st.top() > c) {
			st.pop();
			k -= 1;
		}

        st.push(c);
	}

	while (!st.empty() && k--) st.pop();



    string x = "";
	while (!st.empty()) {
		x += st.top();
		st.pop();
	}
    
    reverse(x.begin(), x.end());
	return x;
}


string solve(string s, ll k){
    // string s;
    // cin >> s;
    int n = (int) s.size();
    vector<int> v;
    for (auto z : s) {
        v.push_back(z - '0');
    }
    // int k; cin >> k;
    k = n - k;
    string ans = "";
    char tk = '9';
    for (int i = 0; i + k - 1 < n; i++) {
        if (s[i] == '0' ) continue;
        tk = min(tk, s[i]);
    }
    ans += tk;
    int idx = -1;
    for (int i = 0; i + k - 1 < n; i++) {
        if (s[i] == tk) {
            idx = i;
            break;
        }
    }
    segtree st(n);
    st.build(v);
    for (int i = 1; i < k; i++) {
        int low = st.query(idx + 1, n - k + i).v; 
        int ID = st.query(idx + 1, n - k + i).id;
        idx = ID;
        ans += char(low + '0'); 
    }

    // int ida = 0;
    // while(ida < n && ans[ida] != 9){
    //     ida++;
    // }

    // reverse(s.begin(), s.end());
    // for(int i =0; i < ida; i++){
    //     ans[i] = s[i];
    // }

    // reverse(ans.begin(), ans.end());


    

    // cout << ans << endl;
    return ans;

}

int rnd(int a, int b){
    return a + rand() % (b - a + 1);
}

template <typename T = std::mt19937>
auto random_generator() -> T {
    auto constexpr seed_bytes = sizeof(typename T::result_type) * T::state_size;
    auto constexpr seed_len = seed_bytes / sizeof(std::seed_seq::result_type);
    auto seed = std::array<std::seed_seq::result_type, seed_len>();
    auto dev = std::random_device();
    std::generate_n(begin(seed), seed_len, std::ref(dev));
    auto seed_seq = std::seed_seq(begin(seed), end(seed));
    return T{seed_seq};
}

auto generate_random_alphanumeric_string(std::size_t len) -> std::string {
    static constexpr auto chars =
        "0123456789";
    thread_local auto rng = random_generator<>();
    auto dist = std::uniform_int_distribution{{}, std::strlen(chars) - 1};
    auto result = std::string(len, '\0');
    std::generate_n(begin(result), len, [&]() { return chars[dist(rng)]; });
    return result;
}



string rndStr(){
    ll x = rnd(1, 9);
    char c = (char)(x+48);

    string to = c + generate_random_alphanumeric_string(5);
    return to;
}


void check(string s, int w, string myAnswer, string correctAnswer){
    // This function acts as the checker.
    if(myAnswer == correctAnswer) return;
    cout<<"Found the WA test"<<endl;
    cout << "S = " << s << endl;
    cout<<"W = "<<w<<endl;
    cout<<"myAnswer = "<<myAnswer<<endl;
    cout<<"correctAnswer = "<<correctAnswer<<endl;
    exit(0);
}


int main() {
    for(int i=1;;i++){
        // string s = rndStr();
        int w = 2;
        string s = "6004392";
        string myAnswer = solve(s, w);
        string correctAnswer = func(s, w);
        check(s, w, myAnswer, correctAnswer);
        cout<<"Passed test: "<<i<<endl;
    }
}