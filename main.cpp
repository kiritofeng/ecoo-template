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
// debugging functions
namespace debug{
    #ifdef DEBUG
        inline void line(){
            std::cerr<<std::endl;
        }
        template<typename T>
        inline void line(T t) {
            std::cerr << t << std::endl;
        }
        template<typename T,typename... A>
        inline void line(T t,A... a){
            std::cerr<<t<<"\t";
            line(a...);
        }
        template<class InputIt>
        inline void iterator(InputIt first,InputIt last){
            if(first==last) return;
            std::cerr<<"["<<*(first++);
            for(;first!=last;++first)
                std::cerr<<", "<<*first;
            std::cerr<<"]";
        }
        template<typename... A>
        inline void printf(const char *S,A... a){
            fprintf(stderr,S,a...);
        }
        template<typename T>
        inline T value(T t){
            std::cerr<<t<<std::endl;
            return t;
        }
    #else
        inline void line(){}
        template<typename T,typename... A>inline void line(T t,A... a){}
        template<class InputIt>inline void iterator(InputIt first,InputIt last){}
        template<typename... A>inline void printf(const char *S,A... a){}
        template<typename T>inline T value(T t){return t;}
    #endif
};

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
/**
 * C++ implementation of Python-like functions:
 * 
 * sum
 * reduce
 * any
 * all
**/
#define ITVT typename std::iterator_traits<InputIt>::value_type // I don't wish to type this again...
template<class InputIt>
inline bool all (std::function<bool(ITVT)> f, InputIt first, InputIt last) {
    for(;first!=last;++first){
        if(!f(*first)) return 0;
    }
    return 1;
}
template<typename T>
inline bool all (std::function<bool(typename t)> f, T t) {
    return f(t);
}
template<typename T, typename... A>
inline bool all (std::function<bool(typename t)> f, T t, A... a) {
    return f(t) and all(f, a...);
}
template<class InputIt>
inline bool any (std::function<bool(typename ITVT)> f, InputIt first, InputIt last) {
    for(;first!=last;++first){
        if(f(*first)) return 1;
    }
    return 0;
}
template<typename T>
inline bool any (std::function<bool(typename t)> f, T t) {
    return f(t);
}
template<typename T, typename... A>
inline bool any (std::function<bool(typename t)> f, T t, A... a) {
    return f(t) or all(f, a...);
}
template<class InputIt>
inline typename ITVT sum (InputIt first, InputIt last) {
    typename ITVT ret=typename ITVT(0);
    for(;first!=last;++first)
        ret+=*first;
    return ret;
}
template<class InputIt>
inline typename ITVT reduce (std::function<ITVT(typename ITVT, typename ITVT)> f, InputIt first, InputIt last, typename ITVT initial=typename ITVT(0)) {
    typename ITVT ret=initial;
    for(;first!=last;++first)
        ret=*f(ret,first);
    return ret;
}
template<typename T>
inline T reduce (std::function<T(T, T)> f, T t) {
    return t;   
}
template<typename T, typename A... a>
inline T reduce (std::function<T(T, T)> f, T t1, T t2, A... a) {
    return reduce(f, f(t1, t2), a...);
}
#undef ITVT // just to be safe
inline void print() {
    std::cout << std::endl;
}
template<typename T>
inline void print(T t) {
    std::cout << t << std::endl;
}
template<typename T, typename ... A>
inline void print(T t, A... a) {
    std::cout << t << " ";
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
        INPUT_FILE = "";
        freopen(INPUT_FILE,"r",stdin);
        fclose(stderr);
    #endif
    for(int _testcase = 1; _testcase <= 10; ++_testcase){
  
    }
}
