#include <fstream>
#include <sstream>
#include <string>
#pragma once

struct Contest
{
    std::string angler;
    std::string contest;
    double avg;
};


class ContestEnor
{
    private:
        std::ifstream _f;
        Contest _cur;
        bool _end;
    public:
        enum FileError{MissingInputFile};
        ContestEnor(const std::string &str) throw (FileError){ _f.open(str); if(_f.fail())throw MissingInputFile;}
        void first() {next();}
        Contest current() const { return _cur;}
        bool end() const { return _end;}
        void next()
        {
            std::string line;
            getline(_f , line);
            if( !(_end = _f.fail()) ){
                std::istringstream is(line);
                is >> _cur.angler >> _cur.contest;
                std::string fish;
                int size;
                int count=0;
                double s=0.0;
                for( is >> fish >> size ; !is.fail(); is >> fish >> size ){
                    s+=size;
                    count++;
                }
                if(count>0){
                    _cur.avg = (s/count) /10.0;
                }
                else
                {
                    _cur.avg=0;
                }
            }
        }
};