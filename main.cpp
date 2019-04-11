// gotta go fast
#ifdef OPTIMIZE
    #pragma GCC optimize "Ofast"
    #pragma GCC optimize "unroll-loops"
    #pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#endif
// standard headers
#include<bits/stdc++.h>
#ifndef __WIN32__
  #include<bits/extc++.h>
#endif
// personal headers
#include "cppython.h"
#include "debug.h"
// useful macros
#define gets(x) fgets(x,sizeof(x),stdin)
#define allOf(x) x.begin(),x.end()
// typedefs
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;
// input and output overrides
template<typename T1,typename T2>
std::istream &operator >>(std::istream &in,std::pair<T1,T2> &p){
    in>>p.first>>p.second;
    return in;
}
template<typename T1,typename T2>
std::ostream &operator <<(std::ostream &out,std::pair<T1,T2> p){
    out<<"("<<p.first<<","<<p.second<<")";
    return out;
}
// bitmask manipulations
inline bool cb(int msk,int i){
    return msk&(1<<i);
}
inline int sb(int msk,int i){
    return msk|(1<<i);
}
inline int ub(int msk,int i){
    return msk&~(1<<i);
}
inline int tb(int msk,int i){
    return msk^(1<<i);
}
// standard constants
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    #ifdef DEBUG
        std::cerr << "YOU ARE IN DEBUG MODE. IF YOU ARE ABOUT TO SUBMIT, CORRECT YOUR DEFINES AND CONSTANTS NOW." << std::endl;
    #else
        const char* INPUT_FILE = "";
        freopen(INPUT_FILE,"r",stdin);
        fclose(stderr);
    #endif
    for(int _testcase = 1; _testcase <= 10; ++_testcase){
  
    }
}
