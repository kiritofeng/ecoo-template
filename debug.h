#ifndef _DEBUG
#define _DEBUG
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
            std::cerr<<t<<" ";
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
#endif
