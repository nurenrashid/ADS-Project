#include "../include/Table.h"

Table::Table()
{
    tableID = "";
    capacity = 0;
    occupied = false;
}

Table::Table(string id, int cap, bool status)
{
    tableID = id;
    capacity = cap;
    occupied = status;
}

string Table::getTableID() const
{
    return tableID;
}

int Table::getCapacity() const
{
    return capacity;
}

bool Table::isOccupied() const
{
    return occupied;
}

void Table::setOccupied(bool status)
{
    occupied = status;
}