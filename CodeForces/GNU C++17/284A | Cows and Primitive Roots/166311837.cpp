# include<bits/stdc++.h>
#include<sstream>
using namespace std;
 
#define ll              long long
#define ln              "\n"
#define lp(i, n)        for (int i = 0; i < n; i++)
#define all(v)   ((v).begin()), ((v).end())
#define sz(v)   ((int)((v).size()))
#define pb(x)   push_back(x)
#define MP    make_pair
 
const int mod = (int)(1e9 + 7);
const int mxN = 103, oo = 0x3f3f3f3f;
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
    if(a==0) return b;
    return gcd(b%a, a);
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
 
//    Euler’s Totient Function
 
//Euler’s Totient function Φ (n)
//for an input n is the count of numbers in {1, 2, 3, …, n} that are relatively prime to n (with 1),
//i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.
//Φ(5) = 4
//gcd(1, 5) is 1, gcd(2, 5) is 1,
//gcd(3, 5) is 1 and gcd(4, 5) is 1
 
//Approach: There is always at least one primitive root for all primes. 
//So, using Eulers totient function we can say that f(p-1) is the required answer where f(n) is euler totient function.
//Below is the implementation of the above approach
 
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    bool f=false;
    ll p,c=1; cin>>p;
    for(ll i=2; i<p-1; i++){
        if(gcd(i,p-1)==1) c++;
    }
    cout<<c;
    return 0;
}
 
 
 
 