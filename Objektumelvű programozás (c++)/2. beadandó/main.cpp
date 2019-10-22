#include <iostream>
#include "contest.hpp"
#include "angler.hpp"

using namespace std;

void average(const string &name,int &cnt)
{
    ContestEnor t(name);
    for(t.first(); !t.end(); t.next())
    {
        if(t.current().avg>=3.0)
        {
            cout<< t.current().angler <<"  "<< t.current().contest << "  "<< t.current().avg << endl;
            cnt++;
        }
        
    }
}

void maximum(const string &name, string &m_id)
{
    int maximum=0;
    string id="";

    AnglerEnor t(name);
    for(t.first(); !t.end(); t.next()){
        if(t.current().contests>maximum)
        {
            id = t.current().id;
            maximum=t.current().contests;
        }
        
    }
    if(id=="")
    {
        cout << "Every angler cought something at every contest."<<endl;
        m_id="";
    }
    else 
    {
        cout << id << "  did not catch anything at " << maximum << "  contests" <<endl;
        m_id=id;
    }
}
//#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{

    string filename;
    cout<<"Please enter the name of the input file:"; cin>>filename;

    try{
        int i=0;
        average(filename,i);
    }
    catch(ContestEnor::FileError err)
    {
        cerr<<"Can't find the input file:"<<filename<<endl;
    }

    //Second task
    cout<<"Second task\n";

    try{
        string a;
        maximum(filename,a);
       
    }catch(ContestEnor::FileError err)
    {
        cerr<<"Can't find the input file:"<<filename<<endl;
    }
    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("avg1","1 angler, 0 fish")
{
    string filename="t1.txt";
    int count=0;
    average(filename,count);
    CHECK(count==0);

}
TEST_CASE("avg2","1 angler, 1 fish")
{
    string filename="t2.txt";
    int count=0;
    average(filename,count);
    CHECK(count==1);
}
TEST_CASE("avg3","2 angler")
{
    string filename="t3.txt";
    int count=0;
    average(filename,count);
    CHECK(count==2);
}
TEST_CASE("maximum1 ","no angler")
{
    string a;
    string filename="t4.txt";
    maximum(filename,a);
    CHECK(a=="");
}
TEST_CASE("maximum2","1 angler")
{
    string a;
    string filename="t5.txt";
    maximum(filename,a);
    CHECK(a=="IMIBA");
}
TEST_CASE("max3","more than 1 angler")
{
    string a;
    string filename="t6.txt";
    maximum(filename,a);
    CHECK(a=="IMIBA");
}
#endif
