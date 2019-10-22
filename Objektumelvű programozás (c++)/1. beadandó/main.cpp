#include <iostream>
#include <string>
#include <vector>
#include "menu.hpp"
#include "set.h"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    Menu menu;
    menu.run();
    
    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "set.h"
//Test cases
TEST_CASE("create", "empty") 
{
    Set s;
    CHECK(s.is_empty() == true);

    Set o;
    o.add(1);
    CHECK(o.is_empty() == false);

    o.remove(1);
    CHECK(o.is_empty() == true);
    
}
TEST_CASE("find max")
{
    vector <int> elements={1,2,3,4,5,6};
    Set m(elements);
    CHECK(m.get_max()==6);
    elements={-1,-2,-3,-4,-5,-6};

    Set mm(elements);
    CHECK(mm.get_max()==-1);
    mm.remove(-1);
    CHECK(mm.get_max()==-2);
    mm.add(9);
    CHECK(mm.get_max()==9);
    
}
TEST_CASE("add elements")
{
    Set a;
    a.add(1);

    CHECK(a.get_size()==1);

    a.add(2);
    a.add(5);

    CHECK(a.get_size()==3);

    a.add(-5);

    CHECK(a.get_size()==4);

    Set t;
    for(int i=0;i<10;i++)
    {
        t.add(i);
        CHECK(t.get_size()==i+1);
    }

    
}
TEST_CASE("remove elements")
{
    Set r;
    for(int i=0;i<10;i++)
    {
        r.add(i);
    }
    for(int i=0;i<10;i++)
    {
        r.remove(i);
        CHECK(r.get_size()==9-i);
    }
}

#endif