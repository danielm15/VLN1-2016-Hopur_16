#ifndef COMPUTERMODEL_H
#define COMPUTERMODEL_H

#include <iostream>
#include <string>
#include <iomanip>

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
    unsigned int getId() const;

    /**
     * @brief getModelName getter
     * @return _modelName
     */
    string getModelName() const;

    /**
     * @brief getMakeYear getter for private variable _makeYear
     * @return _makeYear
     */
    unsigned int getMakeYear() const;

    /**
     * @brief getType getter for private variable _type
     * @return _type
     */
    string getType() const;

    /**
     * @brief getBuilt getter for private variable _built
     * @return _built
     */
    bool getBuilt() const;

    /**
     * @brief operator == Checks if two objects are the same
     * @param g1
     * @param p2
     * @return bool
     */
    friend ostream& operator <<(ostream& out, const ComputerModel& p1);

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
