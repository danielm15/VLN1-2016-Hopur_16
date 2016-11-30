#include "servicelayer.h"

using namespace std;

ServiceLayer::ServiceLayer()
{

}

vector<Genius> ServiceLayer::sortVector()
{
    DataLayer d;
    vector<Genius> GVector = d.getInfo();

    sort(GVector.begin(), GVector.end());

    return GVector;
}



//Search fall TODO

