#ifndef TABLE_H
#define TABLE_H

#include <string>

using namespace std;

class Table
{
private:
    string tableID;
    int capacity;
    bool occupied;

public:
    Table();

    Table(string id, int cap, bool status);

    string getTableID() const;
    int getCapacity() const;
    bool isOccupied() const;

    void setOccupied(bool status);
};

#endif