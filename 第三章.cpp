#include<iostream>
#include<sstream>
using namespace std;
/*迭代器提供了[统一访问容器元素]的方法,是[通用算法]的基础*/

class A{
public:
    int x;
    A(int xx):x(xx){}
};
/*重载全局 << */
ostream& operator<<(ostream& out,A& t){
    out<<t.x<<"hahaha";
    return out;
}
void test(){
    A a(3);
    cout<<a<<endl;
}


#include<iterator>
/*
1.输入迭代器: 
    istream_iterator()
    istream_iterator(istream&)
    重载的主要操作符:   *  -> ++()  ++(int)   ==  !=
*/
void test1(){
    // 只有在输入非给定类型时,才会结束输入
    istream_iterator<int> ii1(cin);
    istream_iterator<int> ii2;
    while(1){
        cout<< *ii1 <<endl;
        ii1 ++;
        if(ii1 == ii2)
            break;
    }
}

/*
2.输出迭代器:
    ostream_iterator(ostream&)
    ostream_iterator(ostrema&,const char*)   输出的数据用 隔开
    重载的主要操作符:   *  ++()  ++(int)   = 
*/      
void test2(){
    ostream_iterator<int> oi1(cout);
    *oi1 = 1;
    oi1 ++;
    *oi1 = 45546;
    
    cout<<"==============="<<endl;
    ostream_iterator<int> oi2(cout,"  i am gap \n");
    *oi2 = 1;
    oi2 ++;
    *oi2 = 45546;

    cout<<"==============="<<endl;
    stringstream ss;
    ostream_iterator<int> oi3(ss);
    *oi3 = 21;
    oi3 ++;
    *oi3 = 45546;
    cout<<ss.str()<<endl;

    cout<<"=============="<<endl;
    istream_iterator<int> ii1(ss);
    cout<< *ii1 <<endl;

}
/*
3.前向迭代器:
    同时具备[输入输出]迭代器功能
    只能向前移动
    没有专门的迭代器类
*/
/*
4.双向迭代器:
    有前向迭代器的所有功能
    重载了 --()  --(int)
*/
/*
5.随机访问迭代器:
    有双向迭代器的所有功能
    还有指针的所有功能
    重载了  []
*/


int main(){
    test2();
}