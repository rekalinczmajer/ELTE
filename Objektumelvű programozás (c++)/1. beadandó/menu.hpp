#include <iostream>
#include <string>
#include <vector>

#include "set.h"

class Menu{
  public:
    Menu(){}
    void run();
  private:
    Set _set;
    void remove();
    void add();
    void max();
    void write();
    void empty();
    void writeMenu();
    
};

void Menu::writeMenu()
{
     cout << " 0. - Quit" << endl;
     cout << " 1. - Remove an element from the set" << endl;
     cout << " 2. - Add an element to the set" << endl;
     cout << " 3. - Maximum of the set" << endl;
     cout << " 4. - Write set" << endl;
     cout << " 5. - Check if the set is empty" << endl;
}
void Menu::run()
{
    int n = 0;
    do{
        writeMenu();
        cout << endl << ">>>>" ; cin >> n;
        switch(n){
            case 1: remove();
                    break;
            case 2: add();
                    break;
            case 3: max();
                    break;
            case 4: write();
                    break;
            case 5: empty();
                    break;
        }
    }while(n!=0);
}
void Menu::remove()
{
    int num;
    cout << "The element you want to remove: "<<endl;
    cin >> num;
    try
    {
        _set.remove(num);
    }
    catch(const Set::Exeptions e)
    {
        if(e==Set::EMPTY)
        {
            std::cerr << "The set is empty." << '\n';
        }
        else if(e==Set::NOT_ELEMENT)
        {
             std::cerr << "No such element in the set" << '\n';
        }
        
    }
    
    
}
void Menu::add()
{
    int num;
    cout << "The element you want to add: "<< endl;
    cin >> num;
    try
    {
         _set.add(num);
    }
    catch(const Set::Exeptions e)
    {
        if(e==Set::EMPTY)
        {
            std::cerr << "The set is empty." << '\n';
        }
        else if(e==Set::ELEMENT)
        {
             std::cerr << "The element is already in the set." << '\n';
        }
        
    }
}
void Menu::max()
{
    try
    {
       int maximum =_set.get_max();
       std::cout <<"The maximum of the set: "<< maximum << "\n";
    }
    catch(const Set::Exeptions e)
    {
        if(e==Set::EMPTY)
        {
            std::cerr << "The set is empty." << '\n';
        }
        
    }
    
}
void Menu::write()
{
    cout << "The elements of the set: "<<endl;
    _set.print();
}
void Menu::empty()
{
    if(_set.is_empty())
    {
        cout <<"The set is empty"<<endl;
    }
    else
    {
        cout << "The set is not empty"<<endl;
    }
}