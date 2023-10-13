#include<iostream>
#include <array>


template<class T, size_t N>
struct Array
{
    T m_ele[N];

    T& operator [] (size_t i )
    {
        return m_ele[i];
    }

    const T& operator [] (size_t i) const
    {
        return m_ele[i];
    }

    T& at(size_t i){
        if(i<0 || i>N) [[unlikely]] throw std::runtime_error("out of range");
        return m_ele[i];
    }

    const T& at(size_t i) const {
        if(i<0 || i>N) [[unlikely]] throw std::runtime_error("out of range");
        return m_ele[i];
    }

    size_t size() const {
        return N;
    }

    T* begin()
    {
        return m_ele;
    }
    T* end()
    {
        return m_ele+N;
    }

    using iterator = T*;
};


void foo(Array<int,10> &arr)
{
    for(size_t i = 0;i<arr.size();i++)
    {
        arr.at(i)=i;
    }
}

int main()
{
    Array<int,10> arr;
    arr[0] = 1;

    foo(arr);

    for(auto i = arr.begin();i!=arr.end();i++)
    {
        std::cout<<*i<<std::endl;
    }
    return 0;
}