#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
/*
    函数对象是[重载了 operator() 的类的实例],operator()是[函数调用运算符]
    发生器:无参
    一元函数:
    二元函数:
    一元判定函数:返回bool
    二元判定函数:返回bool
*/
/*
    一元函数:
    使用模板一元函数,必须要从 [unary_function] 派生,不用模板就不用
*/
class A{
    int sum;
public:
    A(){sum=0;cout<<"haha"<<endl;}
    void operator()(int n){
        cout<<sum<<endl;
        sum+=n;
    }
    void show(){
        cout<<sum<<endl;
    }
};

template<class T,class V>
class B:public unary_function<T,V>{
public:
    V sum;
    B(){sum=0;cout<<"im ()"<<endl;}
    B(T t){sum=t;cout<<"im (t)"<<endl;}
    B(const B& b):sum(b.sum){cout<<"copied!!!!"<<endl;}
    bool operator()(T n){
        cout<<"im ()()"<<endl;
        sum+=n;
        return 1;
    }
};

void test1(){
    int a[10];
    for(int i=0;i<10;i++)
        a[i]=i;
    A aa = for_each(a,a+10,A());
    aa.show();
    B<int,int> bb = for_each(a,a+10,B<int,int>());
    cout<<bb.sum<<endl;

    B<int,int> temp;                            // im ()
    cout<<"im temp() "<<temp(12)<<endl;         // im ()()
    B<int,int> bb1_5 = for_each(a,a+10,temp);   // im temp()
    cout<<bb1_5.sum<<endl;                      // 1


    /* 传进去的是B的[一个实例], 返回来的是这个进过处理后的[这个实例]*/
    B<int,int> bb2 = for_each(a,a+10,B<int,int>(123));
    cout<<bb2.sum<<endl;
}

/*
    二元函数:
        
*/
template<class T1,class T2,class V>
class Mysort:public binary_function<T1,T2,V>{
public:
    V operator()(T1 t1,T2 t2){
        return t1>t2;
    }
};
void test2(){
    int a[10];
    for(int i=0;i<10;i++)
        a[i] = i;
    sort(a,a+10,Mysort<int,int,bool>());
    for(int i=0;i<10;i++)
       cout<<a[i]<<" ";
   cout<<endl;
}

/***********************************
    算术类:
        加法    plus<T>          二元
        减法    minus<T>         二元
        乘法    multiplies<T>     二元
        除法    divides<T>       二元
        模取    modules<T>       二元
        否定    negate<T>        一元  !!!
    关系类:
        等于    equal_to<T>      二元
        不等于  not_equal_to<T>   二元
        大于    greater<T>       二元
        大于等于 greater_equal<T> 二元
        小于    less<T>          二元
        小于等于 less_equal<T>    二元
    逻辑运算类:
        与      logical_and<T>   二元
        或      logical_or<T>    二元
        非      logical_not<T>   二元                
*/
void test3(){
    cout<<"====== 算术 ============"<<endl;
    plus<int> myplus;
    cout<< myplus(234,3234.34) <<endl;
    minus<int> myminus;
    cout<< myminus.operator()(234,3234.34) <<endl;   // 显式调用
    cout<< multiplies<int>()(234,3234.34) <<endl;  // 临时对象
    cout<< divides<int>().operator()(2399994,3234.34) <<endl; //临时对象+显示调用
    cout<< negate<int>()(2344) <<endl;

    cout<< "====== 关系 ============" <<endl;
    cout<< equal_to<int>()(345,4354) <<endl;
    cout<< not_equal_to<int>()(345,4354) <<endl;
    cout<< greater<int>()(345,4354) <<endl;
    cout<< greater_equal<int>()(345,4354) <<endl;
    cout<< less<int>()(345,4354) <<endl;
    cout<< less_equal<int>()(345,4354) <<endl;

    cout<< "====== 逻辑 ============" <<endl;
    cout<< logical_and<int>()(234,324) <<endl;
    cout<< logical_or<int>()(234,324) <<endl;
    cout<< logical_not<int>()(234) <<endl;

}
/********************************************************
    函数适配器:
        绑定:
            bindlst()   将二元函数降为一元函数
            bind2nd()   将二元函数降为一元函数
        取反:
            not1()      针对一元函数
            not2()      针对二元函数
        成员函数适配器:
            mem_fun()
            mem_fun_ref()
        普通函数适配器:
            ptr_fun()
*/
class A4{  // for test4()
public:
    int x;
    A4(int xx):x(xx){}
    A4(){x=10;}
    static void show(){
        cout<<"sss"<<endl;
    }
    void show2(){
        cout<<"A4 "<<x<<endl;
    }
};
void fun4(int x){ // for test4()
    cout<<"fun4: "<<x<<endl;
}
bool fun5(int x, int y){ // for test4()
    return x<y;
}
#include<iterator>
#include<vector>
#include<typeinfo>
void test4(){
    cout<< "======== 绑定 ===========" <<endl;
    int a[10];
    for(int i=0;i<10;i++)
        a[i]=i;
    // cout<< typeid([](const int& x){cout<<x<<endl;}).name() <<endl;
    // // B<int,int> bb = for_each(a,a+10,f);
    // // cout<<bb.sum<<endl;
    binder1st<minus<int> > f = bind1st(minus<int>(),100);
    cout<< f(111) <<endl;
    cout<< count_if(a,a+10, bind2nd(less<int>(), 5)) <<endl;

    /* c++11标准  */
    cout<<"c++11标准"<<endl;
    using namespace std::placeholders;
    std::function<int(int)> f2 = bind(multiplies<int>(),std::placeholders::_1,12);
    // cout<< typeid(f2).name() <<endl;
    cout<< f2(10) <<endl;;
    cout<< (bind(plus<int>(),_1,22)(1111)) <<endl;

    function<int(int)> b2 = bind(plus<int>(),_1,5);
    function<int(int)> b3 = bind(b2,5);
    cout<< count_if(a,a+10, b3) <<endl;
 
    cout<< count_if(a,a+10, bind(greater<int>(),23,_1) );  // 为什么不能用_2

    cout<< "======== 取反 ===========" <<endl;
    cout<< count_if(a,a+10, not1(bind1st(less<int>(), 5))) <<endl;
    sort(a,a+10, not2(less<int>()));
    copy(a,a+10, ostream_iterator<int>(cout, " |"));
    cout<<endl;

    cout<< "======== 成员函数适配器 =========" <<endl;
    // std::vector<A4> v = {A4(),A4(),A4(),A4()};
    std::vector<A4> v;
    for(int i=0;i<4;i++)
        v.push_back(A4(i));
    for_each(v.begin(), v.end(), mem_fun_ref(&A4::show2));
    
    std::vector<A4*> vp;
    for(int i=0;i<4;i++)
        vp.push_back(new A4(i));
    auto mmm = mem_fun(&A4::show2);
    for_each(vp.begin(), vp.end(), mmm);
    cout<<typeid(mem_fun(&A4::show2)).name()<<endl;
    
    /* c++11 标准*/
    for_each(v.begin(), v.end(), mem_fn(&A4::show2));

    cout<< "======== 普通函数适配器 =========" <<endl;
    for_each(a,a+10, fun4);
    for_each(a,a+10, ptr_fun(fun4));
    cout<< count_if(a, a+10, bind1st(ptr_fun(fun5),4)) <<endl;

}
void testc11_17(){
    int a[10];
    *(a-1) = 9;
    for_each(a,a+10, [](int& x){
        cout<<*(&x-1)<<endl;
        x=*(&x-1)+1;});
    for_each(a,a+10, [](int x){cout<<"c11 "<<x<<endl;});

    auto aa = "223";
    auto b = 393;
    /* c++17  */
    // auto f = [](auto x){cout<<x<<endl;};
    // f(1);
}
int main(){
    test1();
    // A4::show();
    // testc11_17();
}   