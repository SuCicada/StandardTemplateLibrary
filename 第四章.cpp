#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

/***********************
    标准输入输出流
*/
void test1(){
    string s;
    cin>>s;  // cin 以空格为界定符
    /*
    使用get
        int get(); //返回输入流的[一个字符]的[ASCII]
        istream& get;
        istream& getline; 会将界定符拿走,但不显示
    */

    char str[10];
    char str2[10];
    int n;
    n = cin.get();
    cin.get(str,3,'0');  //缓冲区长度算[结束符],即 \0
    cin.getline(str2,5);    
    cout<<n<<"  "<<str<<"   "<<str2<<endl;
}
void test2(){
    /*
    流错误
    good()
    fail()   非法数据
    eof()    流末尾
    bad()   致命错误
    */
    while(1){
        int n;
        cin>>n;
        if(cin.good()) cout<<"good()"<<endl;
        if(cin.fail()){
            cout<<"fail()"<<endl;
            cin.clear();   // 清空状态标识位
            cin.get();  // 可用来清空缓冲区
        } 
        if(cin.eof()) cout<<"eof()"<<endl;
        if(cin.bad()) cout<<"bad()"<<endl;
    }
}

/******************************
    文件输入输出流
*/
void test3(){
    /*读写法一*/
    ofstream out("test.txt");
    out<<"ni hoa a aidi "<<endl;
    out.close();
    ifstream in;
    in.open("test.txt",ios::in);

    char aa[22];
    in.getline(aa,sizeof(aa));
    cout<<aa;
    in.close();
    
    cout<<"======================"<<endl;
    /*读写法二之二进制法*/ 
    // write()
    // read()
    struct A{
        int x;
        char c;
        A(){}
        A(int xx,char cc):x(xx),c(cc){}
    };
    ofstream out2;
    out.open("test.txt");
    A a1(23,'d');
    out.write((const char*)&a1,sizeof(A));
    out.close();

    ifstream in2("test.txt");
    A a2;
    in2.read((char*)&a2,sizeof(A));
    cout<<a2.x<<" "<<a2.c<<endl;
}
void test4(){
    /*
    输入输出流缓冲
    ios::beg    开始位置
    ios::cur    当前位置
    ios::end    结束位置
    seekp()    移动
    */
    stringstream ss;
    fstream file("test.txt",ios::app);
    ss<<"123456";
    ss>>file.rdbuf();
    // file.write("aidjijiji",11);
    file.close();
    file.open("test.txt",ios::in);
    cout<<file.rdbuf();
    file.seekp(4,ios::beg);
    file.close();
}





int main(){
    test4();
}