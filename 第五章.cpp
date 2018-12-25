#include<iostream>
#include<string>
using namespace std;
/*
    string 
*/
void know(){
    /*
    创建: 
        迭代器法(数组,string)   
    */
    string s1="123456";
    string s2(s1,1,3);
    /*
        插入:
            insert
            append
    */
    /*
        替换:
            replace
    */
    cout<<string("1111111111111").replace(1,5,"---------")<<endl;
    /*
        查询:
            stting::npos   找不见返回
            find
            rfind
            find_first_of     与包含的[任何一个字符]符合就返回
            find_first_not_of  
            find_last_of
            find_last_not_of
    */
    cout<<string("123345").find_first_not_of("123")<<endl;  
    /*
        删除:
            erase:
                下标范围
                迭代器所指(单个)
                迭代器范围
    */

}

void split(string s,string n){
    int nn;    
    while((nn = s.find(n))!=string::npos){
        cout<<nn<<endl;
        string t = s.substr(0,nn);
        s = s.substr(nn+n.size());
        cout<<t<<"|"<<s<<endl;
    }
    cout<<s<<endl;
}
#include<sstream>
void split2(string s){
    stringstream ss;
    ss<<s;
    string t;
    while(!ss.eof()){
        ss>>t;
        getline(ss,t);
        cout<<t<<endl;
    }
}
string trim(string s){
    cout<<s<<endl;
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ")+1);
    return s;
}
int main(){
    string s="123  dsaf dfaen";
    split(s," ");
    split2(s);
    cout<<trim("     ddjfidjfi      ")<<"|"<<endl;
}
