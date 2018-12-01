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
// python-like functions
template<class InputIt>
inline bool all(InputIt first,InputIt last,std::function<bool(typename std::iterator_traits<InputIt>::value_type)> f){
    for(;first!=last;++first){
        if(!f(*first)) return 0;
    }
    return 1;
}
template<class InputIt>
inline bool any(InputIt first,InputIt last,std::function<bool(typename std::iterator_traits<InputIt>::value_type)> f){
    for(;first!=last;++first){
        if(f(*first)) return 1;
    }
    return 0;
}
template<class InputIt>
inline typename std::iterator_traits<InputIt>::value_type sum(InputIt first,InputIt last){
    typename std::iterator_traits<InputIt>::value_type ret=typename std::iterator_traits<InputIt>::value_type(0);
    for(;first!=last;++first)
        ret+=*first;
    return ret;
}
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
  for(int _testcase=1;_testcase<=10;++_testcase){
  
  }
}
