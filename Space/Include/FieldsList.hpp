#pragma once

#include <vector>
#include <list>
#include <random>
#include <iostream>


using Number    = unsigned int;
using Field     = std::vector<Number>;
using List      = std::list<Field>;

// typename


struct Range {
    unsigned int left;
    unsigned int right;
};



class FieldsList
{
public:
    FieldsList (
        unsigned int fieldSize,
        unsigned int listSize,
        Range range
    );

    void update ();
    void print ();

    // list getList() const;


private:
    void addField ();
    void removeField ();

    Number  generateNumber ();
    Field   generateField ();
    List    generateList ();

    List list_;

    Range range_;
    unsigned int fieldSize_;
    unsigned int listSize_;
};
