#include "List.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    List myList;

    myList.insert_at_head(10);
    myList.insert_at_tail(20);
    myList.insert_at_tail(30);
    myList.insert_at_head(5);

    cout << "List:" << endl;
    myList.print();

    cout << "\nReversed List:" << endl;
    myList.prev_print();

    cout << "\nSearching for 20:" << endl;
    myList.search_target(20);

    cout << "\nInserting 15 after 20:" << endl;
    myList.insert_at_target(15, 20);
    myList.print();

    cout << "\nRemoving 30:" << endl;
    myList.remove(30);
    myList.print();

    cout << "\nRemoving 5:" << endl;
    myList.remove(5);
    myList.print();

    cout << "\nRemoving 10:" << endl;
    myList.remove(10);
    myList.print();

    getch();
    return 0;
}
