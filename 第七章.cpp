#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;

/*
    序列容器:顺序容器
        vector
        deque
        list
    关联容器:
        set
        multiset
        map
        multimap
    容器适配器:
        stack
        queue
        priorityqueue
*/
#include<vector> 
void test_vector(){
    vector<int> v;
    v.push_back(22);
    /* 通过赋值引用,改变 */
    int &x = v.at(0);
    x = 1;
    cout<<x<<"  "<<v[0]<<endl;
}
#include<deque>
void test_deque(){
    /* 没有capacity*/
}
#include<list>
void test_list(){
    list<int> l;
    for(int i=0;i<10;i++)
        l.push_back(i);
    for(int i=0;i<10;i++)
        l.push_back(4);
    list<int> l2(++l.begin(),--l.end());
    /* remove */
    l.remove(4);

    /* 只能 ++ */
    l.insert(++(++l.begin()),4,99);
    /* sort */
    l.sort(greater<int>());
    /* unique */
    l.unique();
    /* splice*/
    l.splice(++l.begin(),l2,++l2.begin(),--l2.end());
    /* reverse */
    l.reverse();
    /* max_size */
    cout<< l.max_size() <<endl;
    /* merge */
    l2.merge(l2);
    /* remove_if */
    l.remove_if(bind2nd(greater<int>(), 88));

    for(list<int>::iterator i=l.begin();i!=l.end();i++)
        cout<< *i <<"  ";
    cout<<endl;

    for(list<int>::iterator i=l2.begin();i!=l2.end();i++)
        cout<< *i <<"  ";
    cout<<endl;
}

#include<queue>
void test_queue(){
    queue<int,list<int> > q;
    queue<int,deque<int> > q1;
    queue<int,vector<int> > q2;
    q.push(12);
    q.push(122);
    q.pop();
    cout<< q.front() << "  " << q.back() <<endl;
}

void test_priority_queue(){
    int a[10] = {23,4,35,546,67,468,578,234,5,45};
    priority_queue<int,vector<int>, greater<int> > p(a,a+sizeof(a)/sizeof(int));
    while(!p.empty()){
        cout<<p.top()<<endl;
        p.pop();
    }
}
/**********************
    bitset
*/

#include<bitset>
void test_bitset(){
    for(int i=0;i< 1<<5 ;i++)
        cout<<i<<" "<< bitset<5>(i) <<endl;

    string str = "11001";
    /* 从左开始数 */
    cout<< bitset<8>(str) <<endl;
    cout<< bitset<8>(str,1) <<endl;
    cout<< bitset<8>(str,1,3) <<endl;

    bitset<8> b(6);
    bitset<8> b2(7);
    cout<< b <<endl;
    cout<< (b>>=1) <<endl;
    cout<< (b<<1) <<endl;
    
    /* 逻辑运算符 
        &=     &
        |=     |
        ^=     ^
        <<=    <<
        >>=    >>
        ~
    */
    cout<< ~b <<endl;
    cout<< (b | b2) <<endl;
    cout<< (b & b2) <<endl;
    cout<< (b ^ b2) <<endl;

    /*
        to_string()
        size()
        count()     1的个数
        any()       是否有1
        none()      是否没有1,即是否为0
        test()      看位是否为1
        []
        to_ulong
        set()       设为全1,(可指定)
        flip()      位翻转, (可指定)
        reset       设为全0

    */
    cout<<  bitset<12>(string("1010100101")).to_ulong() <<endl;
    cout<<  bitset<12>(string("1010100101")).to_string() <<endl;

    cout<<b<<endl;
    /* 从右向左数, 从0开始 */
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<endl;
    }
}

/*********************
    关联容器:
        set
*/
#include<set>
void test_set(){
    multiset<int> s;
    for(int i=0;i<10;i++)    s.insert(i);
    for(int i=0;i<10;i++)    s.insert(3);
    /* 迭代器只能++ ,不能+n  */
    /* insert */    
    s.insert(s.begin(),99);
    s.insert(s.begin(),88);
    /* erase */
    s.erase(3);  
    for(multiset<int>::iterator i=s.begin();i!=s.end();i++)    
        cout<< (*i) <<"  ";
    cout<<endl;
    
    /* lower_ bound    >=    */
    cout<< *(s.lower_bound(5)) <<endl;
    /* upper_bound     >     */
    cout<< *(s.upper_bound(5)) <<endl;
    /* count */
    cout<< s.count(4) <<endl;
    /* equal_range*/
    pair<multiset<int>::iterator, multiset<int>::iterator> p = s.equal_range(88);
    cout<<"首次等于: "<< *p.first<<" 最后一次等于(的后一个): "<< *p.second <<" "<<endl;

    /* find */
    cout<< *s.find(4) <<endl;
    /* swap */

    multiset<int, greater<int> > s2(s.begin(), s.end());
    for(multiset<int>::iterator i=s2.begin();i!=s2.end();i++)    
        cout<< (*i) <<"  ";
    cout<<endl;
}   
template<class T,class pred=less<T> >
class Myset:public set<T,pred>{
public:
    Myset():set<T>(){}
    void insert(T i){
        set<T>::insert(i);
    }
    void show(){
        typename set<T>::iterator i;
        for(i=set<T>::begin();i!=set<T>::end();i++)
            cout<< (*i) <<"  ";
        cout<<endl;
    }
};
void test_set2(){
    Myset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.show();
}
/*************
    map
        同set
*/

#include<map>
void test_map(){
    map<int, int, greater<int> > m;
    /* 添加 */
    pair<int, int> p1(11,3454);
    m.insert(p1);
    m.insert(std::pair<int,int>(22,43543));
    m[33] = 43534;

    cout<<m[22]<<endl;
    /* 遍历 */
    map<int,int>::iterator i;
    for(i=m.begin();i!=m.end();i++)
        cout<< (*i).first <<" - "<< (*i).second <<endl;
    cout<<endl;

    map<int,int>::iterator ii;
    pair<int,int> p;
    ii = m.begin();
    p = *ii;
    cout<<p.first<<" "<<p.second<<endl;
}

/*******
    插入迭代器:
        类:
            back_insert_iterator
            front_insert_iterator
            insert_iterator
        函数:
            back_inserter()
            front_inserter()
    逆向迭代器:
        reverse_iterator
        //////////reverse_bidirectional_iterator
    迭代器函数:
        advance()      前移, += 操作
        distance() 　　 算距离

*/
#include<list>
#include<iterator>
void test_iterator(){
    list<int> v;
    /* 插入迭代器 */
    back_insert_iterator<list<int> > bii(v);
    *bii = 1; bii ++;
    *bii++ = 2;
    *back_inserter(v) = 3;
    back_insert_iterator<list<int> > bii2 = back_inserter(v);
    *bii2 = 35;
    ++++++++++bii2 = 353;

    front_insert_iterator<list<int> > fii(v);
    *(fii++) = 4;
    *(front_insert_iterator<list<int> >(v)) = 5;
    *front_inserter(v) = 6;
    front_inserter(v) = 7;

    insert_iterator<list<int> > ii(v,++++v.begin());
    ii = 23342432;

    for(list<int>::iterator i=v.begin();i!=v.end();i++) cout<< *i <<"  "; cout<<endl;

    /* 逆向迭代器 */
    reverse_iterator<list<int>::iterator> first(v.end());
    reverse_iterator<list<int>::iterator> last(v.begin());
    while(first!=last)   cout<< *first++ <<" ";  cout<<endl; 

    // reverse_bidirectional_iterator<list<int>::iterator, int> f(v.end());
    // reverse_bidirectional_iterator<list<int>::iterator, int> l(v.begin());
    // while(f!=l)   cout<< *f++ <<" ";  cout<<endl; 


    /* 迭代器函数 */
    copy(v.begin(), v.end(), ostream_iterator<int>(std::cout,"  ")); cout<<endl;
    list<int>::iterator temp = find(v.begin(), v.end() ,4);
    cout<< *temp <<endl;
    advance(temp,1);
    cout<< *temp <<endl;
    cout<< distance(temp,v.begin());
}

int main(){
    // test_vector();
    // test_list();
    // test_priority_queue();
    // test_bitset();
    // test_set2();
    test_iterator();
}