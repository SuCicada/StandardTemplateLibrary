#include<iostream>
#include<algorithm>
#include<vector>
/*
    非变异算法:
        循环:
            for_each         接收一元函数 
        查询: 
            find             接收值
            find_if          接收一元函数, 返回第一次的[指针/迭代器]
            find_first_of    接收两组指针/迭代器,  只要有一个就好,要第一个
            adjacent_find    接收一组指针/迭代器
            find_end         接收两组指针/迭代器,  我都要,要最后一个
            search           接收两组指针/迭代器,  我都要,要第一个
            search_n         几个几
        记数:
            count
            count_if
        比较:
            equal     返回迭代
            mismatch  返回双迭代
*/
int fun1(int x){
    return x+1;
}
class A{
public:
    int sum = 0;
    void operator()(int x){
        sum+=x;
    }
};
void test1(){
    #define cout std::cout 
    #define endl std::endl 
    /* for_each
        可以是全局函数,一元函数
     */
    int a[10];
    for(int i=0;i<10;i++)
        a[i] = i;
    cout<< std::for_each(a,a+sizeof(a)/sizeof(int), A()).sum <<endl;
    /* FOR C++11 */
    std::for_each(a,a+10,[](int x){cout<<x<<endl;});
}
void test2(){
    using namespace std;
    /* 查询 */
    int a[]={1,34,134,5,234,1,2,2,224,34,999,999,999,234,134,5,234,52,46,34,56};
    int size = sizeof(a)/sizeof(int);

    /* find */
    cout<< find(a,a+size,5)-a <<endl;
    /* find_if */
    cout<< *find_if(a,a+size, bind2nd(greater<int>(),91)) << endl;
    /* find_first_of */
    int b[] = {134,5,234}; int size2 = sizeof(b)/sizeof(int);
    cout<< find_first_of(a,a+size, b,b+size2)-a <<endl;
    /* adjacent_find */
    cout<< adjacent_find(a,a+size)-a <<endl;
    /* find_end */
    cout<< find_end(a,a+size, b,b+size2)-a <<endl;
    /* search */
    cout<< search(a,a+size, b,b+size2)-a <<endl;
    /* search_n */
    cout<< search_n(a,a+size, 3,999)-a <<endl;
}
void test3(){
    /* 记数 */
    /* count */
    using namespace std;
    int a[]={1,34,134,5,234,1,2,2,224,34,999,999,999,6};
    int size = sizeof(a)/sizeof(int);
    cout<< count(a,a+size, 999) <<endl;

    /* count_if */
    cout<< count_if(a,a+size, not1(bind2nd(not2(less<int>()),44))) <<endl;
}
void test4(){
    /* 比较 */
    /* equal */
    int a[]={23,1,34,134,6,213};
    int b[]={1,34,134,6};
    int size = sizeof(a)/sizeof(int);
    cout<< std::equal(a+1,a+size-1, b) <<endl;
    #include<string>
    std::string s = "asdfdsa";
    cout<< std::equal(s.begin(),s.end(),s.rbegin()) <<endl;

    /* mismatch */
    std::pair<int*,int*> p = std::mismatch(a+1,a+size,b);
    cout<< *p.first << "  " << p.second-b <<endl;

}
int main(){
    test4();
}