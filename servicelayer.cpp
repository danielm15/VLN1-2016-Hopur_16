#include "servicelayer.h"

ServiceLayer::ServiceLayer()
{

}

vector<Genius> ServiceLayer::getGenius()
{
	DataLayer p;
	return p.getInfo();
}

//Sort fall TODO
/*
vector<Genius> ServiceLayer::sort()
{
	DataLayer d;
	std::sort(d.begin(), d.end());

}
*/


Genius ServiceLayer::find(string name) const
{
	DataLayer d;
    vector<Genius> GVector = d.getInfo();
	Genius g;

    for(size_t i = 0; i < GVector.size(); i++)
	{
        if (name == GVector[i].getName())
        {
            return GVector[i];
        }
    }
    throw -1;
}

