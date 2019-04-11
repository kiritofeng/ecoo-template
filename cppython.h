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
 * filter
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
    if(first == last) return 0;
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
template<typename T> class _cppython_reversed_iterator {
public:
    _cppython_reversed_iterator(T &container) : container(container) {}
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
template<typename T> _cppython_reversed_iterator<T> reversed(T &container) {
    return _cppython_reversed_iterator<T>(container);
}
/*
template<typename T> class _cppython_filter_iterator {
public:
    _cppython_filter_iterator(std::function<bool(typename T::value_type)> _f, T &_container) : f(_f), container(_container) {}
    class iterator: public std::iterator<
                        std::input_iterator_tag,
                        typename T::value_type> {
        public:
            iterator& operator++() {
                return next(*this);
            }
    };
    typename T::iterator begin() {
        return container.begin();
    }
    typename T::iterator end() {
        return container.end();
    }
    typename T::iterator next(typename T::iterator it) {
        while(it != end()) {
            if(f(*it)) return it;
            it++;
        }
    }
private:
    T &container;
    std::function<bool(typename T::value_type)> f;
};
template<typename T> _cppython_filter_iterator<T> filter(std::function<bool(typename T::value_type)> f,T &container) {
    return _cppython_filter_iterator<T>(f, container);
}
*/
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
