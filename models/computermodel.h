#ifndef COMPUTERMODEL_H
#define COMPUTERMODEL_H

#include <string>

using namespace std;

class ComputerModel
{
public:
    ComputerModel();

    /**
     * @brief ComputerModel
     * @param modelName
     * @param makeYear
     * @param type
     * @param build
     */
    ComputerModel(string modelName, unsigned int makeYear, string type, bool build);

    /**
     * @brief ComputerModel
     * @param id
     * @param modelName
     * @param makeYear
     * @param type
     * @param build
     */
    ComputerModel(unsigned int id, string modelName, unsigned int makeYear, string type, bool build);

    /**
     * @brief getId getter for id
     * @return _id
     */
    unsigned int getId();

    /**
     * @brief getModelName getter
     * @return _modelName
     */
    string getModelName();

    /**
     * @brief getMakeYear getter for private variable _makeYear
     * @return _makeYear
     */
    unsigned int getMakeYear();

    /**
     * @brief getType getter for private variable _type
     * @return _type
     */
    string getType();

    /**
     * @brief getBuilt getter for private variable _built
     * @return _built
     */
    bool getBuilt();

    /**
     * @brief operator == Checks if two objects are the same
     * @param g1
     * @param p2
     * @return bool
     */
    friend bool operator ==(const ComputerModel& c1, const ComputerModel& c2);

private:
    unsigned int _id;
    string _modelName;
    unsigned int _makeYear;
    string _type;
    bool _built;
};

#endif // COMPUTERMODEL_H
