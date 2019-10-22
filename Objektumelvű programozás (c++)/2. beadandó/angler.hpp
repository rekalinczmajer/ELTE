#include "contest.hpp"
#include <string>
#pragma once

struct Angler {
    std::string id;
    int contests;
};

class AnglerEnor{
    private:
        ContestEnor _ct;
        Angler _cur;
        bool _end;
    public:
        AnglerEnor(const std::string &str): _ct(str) { };
        void first() {_ct.first(); next();}
        Angler current() const { return _cur;}
        bool end() const { return _end;}
        void next()
        {
            if( !(_end = _ct.end()) )
            {
                _cur.id = _ct.current().angler;
                _cur.contests = 0;
                for( ; !_ct.end() && _ct.current().angler == _cur.id; _ct.next() )
                {
                    if(_ct.current().avg==0)
                    {
                        _cur.contests++;
                    }
                }
                   
            }
        }
        
};
