#include<iostream>
#include<stdio.h>
#include<ctime>
#include<cstdlib>
using namespace std;

class Student{
private:
    int score;
public:
    void set(int c){
        score = c;
    }
    void show(){
        cout<<score<<endl;
    }
};

class Teacher{
private:
    float score;
public:
    void set(float c){
        score = c;
    }
    void show(){
        cout<<score<<endl;
    }
};

template<class T>
class Num{};

template<>
class Num<Student>{
public:
    typedef int num;
};

template<>
class Num<Teacher>{
public:
    typedef float num;
};

template<class T>
typename Num<T>::num set(T& t, typename Num<T>::num num){
    t.set(num);
    return num;
}

int main()
{  
    srand(time(0));
    Student s[10];
    Teacher t[10];
    for(int i=0;i<10;i++)
    {
        set(s[i], ((double)rand()/1000000));
        set(t[i], ((double)rand()/1000000));
    }
    for(int i=0;i<10;i++){
        s[i].show();
    }
    cout<<"==============="<<endl;
    for(int i=0;i<10;i++){
        t[i].show();
    }
    return 0;
}
