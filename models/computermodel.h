#ifndef COMPUTERMODEL_H
#define COMPUTERMODEL_H

#include <string>

using namespace std;

class ComputerModel
{
public:
    ComputerModel();

    /**
     * @brief ComputerModel Constructing new object of computer
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
     * @brief getBuild getter for private variable _build
     * @return _build
     */
    bool getBuild();

private:
    unsigned int _id;
    string _modelName;
    unsigned int _makeYear;
    string _type;
    bool _build;
};

#endif // COMPUTERMODEL_H
