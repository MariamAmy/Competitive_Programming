# include<bits/stdc++.h>
using namespace std;
 
#define ll              long long
#define ln              "\n"
#define lp(i, n)        for (int i = 0; i < n; i++)
#define all(v)   ((v).begin()), ((v).end())
#define sz(v)   ((int)((v).size()))
#define pb(x)   push_back(x)
#define MP    make_pair
 
const int mod = (int)(1e9 + 7);
const int mxN = 1e5+5, oo = -0x3f3f3f3f;
//vector <pair<int, int>> moves = {{-1,0}, {1,0}, {0,1}, {0, -1}, {1, -1}, {-1, 1}, {-1, -1},{1, 1}};
//printf("%0.6f\n",x)
 
ll fact(ll i){
    if(i == 1 || i == 0) return 1;
    i %= mod;
    return i *= fact(i-1);
}
 
ll llog(ll a, ll b){
    return log2(a) / log2(b);
}
 
ll gcd(ll a, ll b){ // a > b
    if(b==0) return a;
    return gcd(b, a%b);
}
 
ll power(ll b, ll p, ll m){   // O(log(p) base 2)
 if(p == 0) return 1;
 ll sq = power(b, p/2, m);
 sq = (sq*sq) % m;
 if(p%2 == 1)
  sq = (sq*b) % m;
 return sq%m;
}
 
int FactN_PrimePower(int n, int p){  // O(log(n) base p)
    int pow = 0;
    for(int i = p; i <= n ; i = i * p)
     pow += n/i;
    return pow;
}
 
ll sumPows(ll a, int k){ // Return a^1+a^1+a^2+.....a^k in O(k)
 if (k == 0)
  return 0;
 if (k % 2 == 1)
  return a * (1 + sumPows(a, k - 1));
 ll half = sumPows(a, k / 2);
 return half * (1 + half - sumPows(a, k / 2 -1) );
}
 
vector <vector<int>> v;
vector<bool> vis;
vector<int>ans;
 
void dfs(int x){
    vis[x]=true;
    ans.push_back(x);
    for(auto it:v[x])
        if(!vis[it])
            dfs(it);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,c=0; cin>>n>>m;
    v.resize(n+1);
    vis.resize(n+1);
    for (int i=1; i<=m; i++){
        int x,y; cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
        if(!vis[i]){
            ans.clear();
            dfs(i);
            bool f=true;
            for(auto it:ans)
                f &= (v[it].size()==2);
            if(f) c++;
        }
    cout<<c<<ln;
    return 0;
}