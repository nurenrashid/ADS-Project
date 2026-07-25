#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include <vector>
#include <unordered_map>
#include "Table.h"

using namespace std;

class TableManager
{
private:
    vector<Table> tables;
    unordered_map<string, int> tableIndex;
    vector<string> history;

public:
    void addTable(string id,int capacity,bool occupied);
    void displayTables();
    void searchTable(string id);
    void checkIn(string id);
    void checkOut(string id);

    void displayStatistics();
    void displayHistory();

    void loadTables();
    void saveTables();

    void loadHistory();
    void saveHistory();

    void addNewTable();
    void deleteTable(string id);

    void sortByTableID();
    void sortByCapacity();

    void searchByCapacity(int capacity);
};

#endif