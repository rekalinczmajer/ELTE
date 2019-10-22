#include <iostream>
#include <algorithm>
#include <vector>
#include "set.h"

using namespace std;

void Set::set_max()
{
    if(!is_empty())
    {
       sort(set.begin(),set.end(),greater<int>());
       max=set[0];
    }
  
}
void Set::add(int a)
{
    vector<int>::iterator it = find(set.begin(), set.end(), a);
    if(it == set.end())
    {
        set.push_back(a);
    }
    else
    {
        throw ELEMENT;
    }
    
    set_max();
}

void Set::print()
{
    for(unsigned int i=0;i<set.size();i++)
    {
        cout << set[i] << " ";
    }
    cout << endl;
}
void Set::remove(int a)
{
    if(is_empty())
    {
        throw EMPTY;
    }
    else
    {
        vector<int>::iterator it = find(set.begin(), set.end(), a);
        if ( it != set.end() )
        {
            set.erase(it);
        }
        else 
        {
            throw NOT_ELEMENT;
        }
        set_max();
    }
}
int Set::get_max()
{
    if(is_empty())
    {
        throw EMPTY;
    }
    else
    {
        return max;
    }
}