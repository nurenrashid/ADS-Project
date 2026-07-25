#include <iostream>
#include "../include/TableManager.h"

using namespace std;

int main()
{
    TableManager manager;
    manager.loadTables();
    manager.loadHistory();

    int choice;
    string id;

    do
    {
        cout << "\n=====================================\n";
        cout << "   FOOD COURT TABLE TRACKER\n";
        cout << "=====================================\n";
        cout << "1. View All Tables\n";
        cout << "2. Search Table\n";
        cout << "3. Search by Capacity\n";
        cout << "4. Check In\n";
        cout << "5. Check Out\n";
        cout << "6. View Statistics\n";
        cout << "7. View History\n";
        cout << "8. Add New Table\n";
        cout << "9. Delete Table\n";
        cout << "10. Sort by Table ID\n";
        cout << "11. Sort by Capacity\n";
        cout << "12. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.displayTables();
            break;

        case 2:
            cout << "Enter Table ID: ";
            cin >> id;
            manager.searchTable(id);
            break;

            case 3:
    int capacity;

    cout << "Enter minimum capacity: ";
    cin >> capacity;

    manager.searchByCapacity(capacity);

    break;


        case 4:
            cout << "Enter Table ID: ";
            cin >> id;
            manager.checkIn(id);
            break;

        case 5:
            cout << "Enter Table ID: ";
            cin >> id;
            manager.checkOut(id);
            break;

        case 6:
            manager.displayStatistics();
            break;

        case 7:
            manager.displayHistory();
            break;

        case 8:
           manager.addNewTable();
           break;

        case 9:
           cout << "Enter Table ID: ";
           cin >> id;
           manager.deleteTable(id);
           break;

case 10:
    manager.sortByTableID();
    break;

case 11:
    manager.sortByCapacity();
    break;

case 12:
    cout << "Thank you for using Food Court Tracker!\n";
    break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while (choice != 12);

    return 0;
}