/* stl包括:容器,算法,迭代器 */


#include<iostream>
/* 命名空间 */
namespace myspace{
    void fun(){
        std::cout<<"this is myspace"<<std::endl;
    }
}
namespace yourspace{
    void fun(){
        std::cout<<"that is yourspace"<<std::endl;
    }
}
using namespace yourspace;
using namespace std;

int main(){
    cout<<"can i ignore std"<<endl;
    myspace::fun();
    fun();
}