#ifndef DATALAYER_H
#define DATALAYER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <istream>
#include "genius.h"

class DataLayer
{
public:
    DataLayer();
    friend ostream& operator <<(ostream& out, const Genius& p1);
    friend istream& operator >>(istream& in, const Genius& p1);
    vector<Genius> getVector();
};

#endif DATALAYER_H
