#ifndef Set_H
#define Set_H
#include <vector>
#include <algorithm>

using namespace std;

class Set
{
    private: 
        vector <int> set;
        int max;
        void set_max();
    public:
        enum Exeptions {EMPTY,ELEMENT,NOT_ELEMENT};
        Set(){};
        Set(vector<int> p):set(p){ set_max();}
        bool is_empty(){return set.size()==0;}
        int get_max();
        void add(int a);
        void remove(int a);
        int get_size(){return set.size();}
        void print();
};
#endif
