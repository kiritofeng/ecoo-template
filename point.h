template<typename T=int>
struct point{
    T x,y;
    point(T _x,T _y):x(_x),y(_y){}
    inline point operator +(const point<T> p)const{
        return point(x+p.x,y+p.y);
    }
    inline point operator -(const point<T> p)const{
        return point(x-p.x,y-p.y);
    }
    inline T operator *(const point<T> p)const{
        return x*p.x+y*p.y;
    }
    inline T operator ^(const point<T> p)const{
        return x*p.y-y*p.x;
    }
    inline bool operator <(const point<T> p)const{
        return x<p.x||(x==p.x&&y<p.y);
    }
    inline bool operator >(const point<T> p)const{
        return x>p.x||(x==p.x&&y>p.y);
    }
    inline bool operator <=(const point<T> p)const{
        return x<p.x||(x==p.x&&y<=p.y);
    }
    inline bool operator >=(const point<T> p)const{
        return x>p.x||(x==p.x&&y>=p.y);
    }
};
