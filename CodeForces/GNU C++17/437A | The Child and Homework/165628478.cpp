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
const int mxN = 103, oo = -0x3f3f3f3f;
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
 
int solve(int x){
    int s=0, p=1;
    while(x!=0){
        int digit=x%10;
        x/=10;
        if(digit!=0){
            s+=digit*p;
            p*=10;
        }
    }
    return s;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<string>v(4);
    map<int,string>mp;
    int ndx,ndxx,x=0,y=0,c=0,cc=0;
    mp[0]="A";
    mp[1]="B";
    mp[2]="C";
    mp[3]="D";
    bool f=false,k=false;
    lp(i,4) cin>>v[i];
    lp(i,4){
        lp(j,4){
            if(i!=j){
                if((v[i].size()-2)*2<=(v[j].size()-2)){
                    c++;
                    if(c==3){
                        ndxx=i;
                        f=true;
                    }
                }
            }
        }
        if(c==3) x++;
        c=0;
    }
    lp(i,4){
        lp(j,4){
            if(i!=j){
                if((v[i].size()-2)>=2*(v[j].size()-2)){
                    cc++;
                    if(cc==3){
                        ndx=i;
                        k=true;
                    }
                }
            }
        }
        if(cc==3) y++;
        cc=0;
    }
    if(x+y>1) cout<<mp[2];
    else if(f) cout<<mp[ndxx];
    else if(k) cout<<mp[ndx];
    else cout<<mp[2];
    return 0;
}