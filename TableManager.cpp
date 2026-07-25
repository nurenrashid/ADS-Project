#include "../include/TableManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void TableManager::addTable(string id, int capacity, bool occupied)
{
    Table newTable(id, capacity, occupied);

    tables.push_back(newTable);

    tableIndex[id] = tables.size() - 1;
}

void TableManager::displayTables()
{
    cout << "\n===== TABLE LIST =====\n";

    for (int i = 0; i < tables.size(); i++)
    {
        cout << "Table : " << tables[i].getTableID() << endl;
        cout << "Capacity : " << tables[i].getCapacity() << endl;

        if (tables[i].isOccupied())
            cout << "Status : Occupied\n";
        else
            cout << "Status : Available\n";

        cout << "---------------------\n";
    }
}

void TableManager::searchTable(string id)
{
    if(tableIndex.find(id)==tableIndex.end())
    {
        cout<<"Table not found.\n";
        return;
    }

    int index = tableIndex[id];

    cout<<"\n===== TABLE FOUND =====\n";

    cout<<"Table : "<<tables[index].getTableID()<<endl;

    cout<<"Capacity : "<<tables[index].getCapacity()<<endl;

    if(tables[index].isOccupied())
        cout<<"Status : Occupied"<<endl;
    else
        cout<<"Status : Available"<<endl;
}

void TableManager::checkIn(string id)
{
    if(tableIndex.find(id)==tableIndex.end())
    {
        cout<<"Table not found.\n";
        return;
    }

    int index = tableIndex[id];

    if(tables[index].isOccupied())
    {
        cout<<"Table is already occupied.\n";
    }
    else
    {
    tables[index].setOccupied(true);
    history.push_back("Table " + id + " - Check In");

    saveTables();
    saveHistory();

    cout << "Check In Successful!" << endl;
}
}

void TableManager::checkOut(string id)
{
    if(tableIndex.find(id)==tableIndex.end())
    {
        cout<<"Table not found.\n";
        return;
    }

    int index = tableIndex[id];

    if(!tables[index].isOccupied())
    {
        cout<<"Table is already available.\n";
    }
    else
    {
   tables[index].setOccupied(false);
   history.push_back("Table " + id + " - Check Out");

   saveTables();
   saveHistory();

   cout << "Check Out Successful!" << endl;
    }
}

void TableManager::displayStatistics()
{
    int available = 0;
    int occupied = 0;

    for (Table& table : tables)
    {
        if (table.isOccupied())
            occupied++;
        else
            available++;
    }

    cout << "\n===== TABLE STATISTICS =====\n";
    cout << "Available Tables : " << available << endl;
    cout << "Occupied Tables  : " << occupied << endl;
    cout << "Total Tables     : " << tables.size() << endl;
}

void TableManager::displayHistory()
{
    cout << "\n===== HISTORY =====\n";

    if (history.empty())
    {
        cout << "No history available.\n";
        return;
    }

    for (const string& record : history)
    {
        cout << record << endl;
    }
}

void TableManager::loadTables()
{
    ifstream file("data/tables.txt");

    if (!file)
    {
        cout << "Error opening tables.txt!" << endl;
        return;
    }

    tables.clear();
    tableIndex.clear();

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string id, capacityStr, occupiedStr;

        getline(ss, id, ',');
        getline(ss, capacityStr, ',');
        getline(ss, occupiedStr, ',');

        int capacity = stoi(capacityStr);
        bool occupied = (occupiedStr == "1");

        addTable(id, capacity, occupied);
    }

    file.close();
}

void TableManager::saveTables()
{
    ofstream file("data/tables.txt");

    if (!file)
    {
        cout << "Error saving tables.txt!" << endl;
        return;
    }

    for (Table& table : tables)
    {
        file << table.getTableID() << ","
             << table.getCapacity() << ","
             << (table.isOccupied() ? 1 : 0)
             << endl;
    }

    file.close();
}

void TableManager::saveHistory()
{
    ofstream file("data/history.txt");

    if (!file)
    {
        cout << "Error saving history.txt!" << endl;
        return;
    }

    for (const string& record : history)
    {
        file << record << endl;
    }

    file.close();
}

void TableManager::loadHistory()
{
    ifstream file("data/history.txt");

    if (!file)
    {
        return;
    }

    history.clear();

    string line;

    while (getline(file, line))
    {
        history.push_back(line);
    }

    file.close();
}

void TableManager::addNewTable()
{
    string id;
    int capacity;

    cout << "Enter New Table ID: ";
    cin >> id;

    if (tableIndex.find(id) != tableIndex.end())
    {
        cout << "Table ID already exists.\n";
        return;
    }

    cout << "Enter Capacity: ";
    cin >> capacity;

    addTable(id, capacity, false);

    saveTables();

    cout << "Table added successfully!\n";
}

void TableManager::deleteTable(string id)
{
    if (tableIndex.find(id) == tableIndex.end())
    {
        cout << "Table not found.\n";
        return;
    }

    int index = tableIndex[id];

    tables.erase(tables.begin() + index);

    tableIndex.clear();

    for (int i = 0; i < tables.size(); i++)
    {
        tableIndex[tables[i].getTableID()] = i;
    }

    saveTables();

    cout << "Table deleted successfully!\n";
}

void TableManager::sortByTableID()
{
    sort(tables.begin(), tables.end(),
        [](const Table& a, const Table& b)
        {
            return a.getTableID() < b.getTableID();
        });

    tableIndex.clear();

    for (int i = 0; i < tables.size(); i++)
    {
        tableIndex[tables[i].getTableID()] = i;
    }

    cout << "Tables sorted by Table ID.\n";
}

void TableManager::sortByCapacity()
{
    sort(tables.begin(), tables.end(),
        [](const Table& a, const Table& b)
        {
            return a.getCapacity() < b.getCapacity();
        });

    tableIndex.clear();

    for (int i = 0; i < tables.size(); i++)
    {
        tableIndex[tables[i].getTableID()] = i;
    }

    cout << "Tables sorted by Capacity.\n";
}


void TableManager::searchByCapacity(int capacity)
{
    bool found = false;

    cout << "\n===== MATCHING TABLES =====\n";

    for (Table& table : tables)
    {
        if (table.getCapacity() >= capacity)
        {
            cout << "Table: " << table.getTableID() << endl;
            cout << "Capacity: " << table.getCapacity() << endl;

            if (table.isOccupied())
                cout << "Status: Occupied\n";
            else
                cout << "Status: Available\n";

            cout << "------------------------\n";

            found = true;
        }
    }

    if (!found)
    {
        cout << "No tables found.\n";
    }
}