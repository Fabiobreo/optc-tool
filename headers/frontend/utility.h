#ifndef UTILITY_H
#define UTILITY_H

#include <character.h>
#include <mycharacter.h>
#include <map>

class Utility
{
public:
    std::vector<Character*>* characters = nullptr;
    std::map<std::string, Material*>* materials = nullptr;
    std::map<std::string, int>* familiesMap = nullptr;
    std::map<int, std::vector<MyCharacter*>>* myCharacters = nullptr;
    std::string currentTab = "Stats";
    unsigned long id = 0;
    bool editMode = false;

    // Sorting variables
    std::string primarySortCondition = "Id";
    bool primarySortAscendingOrder = true;
    bool primarySortIncludeLimit = false;

    std::string secondarySortCondition = "";
    bool secondarySortAscendingOrder = true;
    bool secondarySortIncludeLimit = false;
};

#endif // UTILITY_H
