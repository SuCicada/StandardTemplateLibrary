#include<iostream>
using namespace std;
/*模板分为:函数模板,类模板*/
/*
    2.2 traits
    STL强调软件的[复用],traits依靠[显示模板特殊化],
    将因类型不同而变化的代码,用统一接口包装
*/

class MyInt{
public:
    void f(int p){
        cout<<"MyInt "<<p<<endl;
    }
};
class MyFloat{
public:
    void f(int p){
        cout<<"MyFloat "<<p<<endl;
    }
};

/*1.定义基本模板类*/
template<class T>
class BasicTemplate{}; // 什么都不用写,说明这只是一个模板类


/*2.模板特化*/
template<>
class BasicTemplate<MyInt>{
public:
    typedef int Num;
};
template<>
class BasicTemplate<MyFloat>{
public:
    typedef float Num;
};

/*3.统一模板调用类 编制*/
#define traitsNum typename BasicTemplate<T>::Num 
template<class T>
// typename BasicTemplate<T>::Num func(T& t,typename BasicTemplate<T>::Num para){
traitsNum func(T& t,traitsNum para){
    t.f(para);
    return para; 
}
// ======或者=====
template<class T>
class ClassAction{
public:
    typedef typename BasicTemplate<T>::Num traitsNum;
    traitsNum func(T& t,traitsNum para){
        t.f(para);
        return para; 
    }
};

/*
关于类内的操作符重载
https://blog.csdn.net/whyglinux/article/details/602329
类的成员函数后面加 const，表明这个函数不会对这个类对象的数据成员（准确地说是非静态数据成员）作任何改变。
有 const 修饰的成员函数（指 const 放在函数参数表的后面，而不是在函数前面或者参数表内），只能读取数据成员，不能改变数据成员；
没有 const 修饰的成员函数，对数据成员则是可读可写的。
*/







int main()
{
    MyInt i;
    MyFloat f;
    // ClassAction::func(i,223);
    func(i,222);
}