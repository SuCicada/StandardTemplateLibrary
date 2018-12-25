#include<iostream>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;

/* 
    变异算法:
        复制:
            copy
            copy_backward
        交换:
            swap
            swap_ranges
            iter_swap
        变换:
            transform
        替换:
            replace
            replace_if
            replace_copy
            replace_copy_if
        填充:
            fill
            fill_n
        生成:
            generate
            generate_n
*/

void test1(){
    /* 复制 */
    /* copy */
    int a[5]={1,2,3,5,5};
    int b[5];
    copy(a,a+5,b);
    copy(b,b+5,ostream_iterator<int>(cout," ")); cout<<endl;
    #include<vector>
    /* copy_backward */
    /* 给vector复制*/
    /* 法一*/
    vector<int> v2;
    copy(a,a+5,back_inserter(v2));
    /* 法二   使用begin()复制,必须要提前定义好vector空间大小*/
    vector<int> v(10);  
    copy_backward(a,a+5,v.end()-3);
    copy(v2.begin(),v2.end(),ostream_iterator<int>(cout," ")); cout<<endl;
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," ")); cout<<endl;
}

void test2(){
    /* 交换 */
    /* swap */
    int a[5]={1,2,3,5,5};
    int b[5]={33,45,2,999,99};
    swap(a,b);
    copy(a,a+5,ostream_iterator<int>(cout," ")); cout<<endl;
    copy(b,b+5,ostream_iterator<int>(cout," ")); cout<<endl;

    swap_ranges(a,a+3,b);
    copy(a,a+5,ostream_iterator<int>(cout," ")); cout<<endl;
    copy(b,b+5,ostream_iterator<int>(cout," ")); cout<<endl;

    iter_swap(a,b);
    copy(a,a+5,ostream_iterator<int>(cout," ")); cout<<endl;
    copy(b,b+5,ostream_iterator<int>(cout," ")); cout<<endl;
}
void test3(){
    /* 变换 */
    /* transform 
        一元函数
    */
    int a[5]={1,32,3,45,8};
    int b[8];
    /* 改自己 */
    transform(a,a+5,a,bind1st(multiplies<int>(),10));
    copy(a,a+5,ostream_iterator<int>(cout," ")); cout<<endl;
    /* 给别人 */
    transform(a,a+5,b,bind1st(multiplies<int>(),10));
    copy(b,b+5,ostream_iterator<int>(cout," ")); cout<<endl;

    /* 接收二元函数 ,给c*/
    int c[6];
    transform(a,a+5,b,c,minus<int>());
    copy(c,c+5,ostream_iterator<int>(cout," ")); cout<<endl;

    /* 给值时,可以适用copy函数的做法,使用[back_inserter]*/
}
void test4(){
    /* 替换 */
    int a[10]={1,2,34,4,5,5,5,8,9,9};
    copy(a,a+10,ostream_iterator<int>(cout," ")); cout<<endl;
    /* replace */
    replace(a,a+10,5,8080);
    copy(a,a+10,ostream_iterator<int>(cout," ")); cout<<endl;
    /* replace_if */
    replace_if(a,a+10,bind2nd(less<int>(),5),-10);
    copy(a,a+10,ostream_iterator<int>(cout," ")); cout<<endl;

    /* replace_copy */
    std::vector<int> v;
    replace_copy(a,a+10,back_inserter(v),8080,0);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," ")); cout<<endl;

    /* replace_copy_if */
    replace_copy_if(a,a+10,back_inserter(v),bind2nd(greater<int>(), 10),10);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," ")); cout<<endl;
}
void test5(){
    int a[5];
    /* 填充 */
    /* fill */
    fill(a,a+5,100);
    copy(a,a+5,ostream_iterator<int>(cout," ")); cout<<endl;

    /* fill_n */
    int b[10];
    fill_n(b,4,99);
    copy(b,b+10,ostream_iterator<int>(cout," ")); cout<<endl;

    std::vector<int> v;
    fill_n(back_inserter(v),5,90);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," ")); cout<<endl;

}
int fibo(){
    static int a=0;
    static int b=1;
    int t = b;
    b = b + a;
    a = t;
    return b;
}
void test6(){
    /* 生成 */
    /* generate */
    int a[10];
    generate(a,a+10,fibo);
    copy(a,a+10,ostream_iterator<int>(cout," ")); cout<<endl;
    /* generate_n */
    generate_n(a,10,fibo);
    copy(a,a+10,ostream_iterator<int>(cout," ")); cout<<endl;


}
int main(){
    test6();
}