#ifndef _ARRAY1D_H
#define _ARRAY1D_H

template <typename T>
class Array1D {

public:
    Array1D(int size = 0);
    Array1D(const Array1D<T>& v);
    ~Array1D() { delete[] element; }
    T& operator[](int i) const;
    int Size() { return size; }
    Array1D<T>& operator=(const Array1D<T>& v);
    Array1D<T> operator+() const; //一元加法操作符
    Array1D<T> operator+(const Array1D<T>& v) const;
    Array1D<T> operator-() const; //一元减法操作符
    Array1D<T> operator*(const Array1D<T>& v) const;
    Array1D<T>& operator+=(const T& x);

private:
    int size;
    T *element; //一维数组  
};

template<typename T>
Array1D<T>::Array1D(int size)
{
    if (size < 0)
        throw BadInitializer();
    this->size = size;
    element = new T[size];

}

template<typename T>
Array1D<T>::Array1D(const Array1D<T>& v)
{
    size = v.size;
    element = new T[size];
    for (int i = 0; i < size; i++)
        element[i] = v.element[i];
}

template<typename T>
T& Array1D<T>::operator[](int i) const
{
    if (i < 0 || i >= size)
        throw OutOfBounds();
    return element[i];
}




#endif
