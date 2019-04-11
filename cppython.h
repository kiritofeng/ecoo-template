#ifndef _CPPYTHON
#define _CPPYTHON
/**
 * C++ implementation of Python-like functions:
 *
 * sum
 * reduce
 * any
 * all
 * reversed
**/
#define ITVT std::iterator_traits<InputIt>::value_type // I don't wish to type this again...
template<class InputIt>
inline bool all (std::function<bool(typename ITVT)> f, InputIt first, InputIt last) {
    for(;first!=last;++first){
        if(!f(*first)) return 0;
    }
    return 1;
}
template<typename T>
inline bool all (std::function<bool(T)> f, T t) {
    return f(t);
}
template<typename T, typename ... A>
inline bool all (std::function<bool(T)> f, T t, A... a) {
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
inline bool any (std::function<bool(T)> f, T t) {
    return f(t);
}
template<typename T, typename ... A>
inline bool any (std::function<bool(T)> f, T t, A... a) {
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
inline typename ITVT reduce (std::function<typename ITVT(typename ITVT, typename ITVT)> f, InputIt first, InputIt last) {
    typename ITVT ret=*first++;
    for(;first!=last;++first)
        ret=f(ret,*first);
    return ret;
}
template<class InputIt>
inline typename ITVT reduce (std::function<typename ITVT(typename ITVT, typename ITVT)> f, InputIt first, InputIt last, typename ITVT initial) {
    typename ITVT ret=initial;
    for(;first!=last;++first)
        ret=f(ret,*first);
    return ret;
}
template<typename T>
inline T reduce (std::function<T(T, T)> f, T t) {
    return t;
}
template<typename T, typename... A>
inline T reduce (std::function<T(T, T)> f, T t1, T t2, A... a) {
    return reduce(f, f(t1, t2), a...);
}
#undef ITVT // just to be safe
template<typename T> class ReverseIter {
public:
    ReverseIter(T &container) : container(container) {}
    typename T::reverse_iterator begin() {
        return container.rbegin();
    }
    typename T::reverse_iterator end() {
        return container.rend();
    }
    typename T::const_reverse_iterator cbegin() {
        return container.crbegin();
    }
    typename T::const_reverse_iterator cend() {
        return container.crend();
    }
private:
    T &container;
};
template<typename T> ReverseIter<T> reversed(T &container) {
    return ReverseIter<T>(container);
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
    print(a...);
}
#endif
