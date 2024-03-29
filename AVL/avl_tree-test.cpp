/*
 * avl_tree-test.cc    (c) Tommy Olsson, IDA, 2007-05-02
 */
#include <iostream>
#include "avl_tree.h"

using namespace std;

int main() {
    AVL_Tree<int>  avl_tree;
/*
    for (int i = 1; i <= 11; i++)
        avl_tree.insert(i);
*/

    avl_tree.insert(44);
    avl_tree.insert(20);
    avl_tree.insert(56);
    avl_tree.insert(35);
    avl_tree.insert(50);
    avl_tree.insert(60);
    avl_tree.insert(45);
    avl_tree.insert(61);
    avl_tree.remove(35);

    try {
        cout << "AVL-träd efter insättning av 1, 2,..., 11:\n\n";
        avl_tree.print_tree(cout);
        cout << endl;
    } catch (const exception& e) {
        cout << '\n' << e.what() << endl;
        cout << "AVL-träd innehåller efter insättning av 1, 2,..., 11:\n\n";
        avl_tree.print(cout);
        cout << endl;
    }

    unsigned int choice;
    unsigned int value;

    while (true) {
        cout << endl;
        cout << "1 - Sätt in.\n";
        cout << "2 - Ta bort.\n";
        cout << "3 - Sök värde.\n";
        cout << "4 - Sök minsta.\n";
        cout << "5 - Sök största.\n";
        cout << "6 - Töm trädet.\n";
        cout << "7 - Skriv ut ordnat.\n";
        cout << "8 - Skriv ut träd.\n";
        cout << "0 - Avsluta.\n" << endl;
        cout << "Val: ";
        cin >> choice;
        cout << endl;

        try {
            switch (choice) {
            case 0:
                cout << "Slut." << endl;
                return 0;
            case 1:
                cout << "Värde att sätta in: ";
                cin >> value;
                avl_tree.insert(value);
                break;
            case 2:
                cout << "Värde att ta bort: ";
                cin >> value;
                avl_tree.remove(value);
                break;
            case 3:
                cout << "Värde att söka efter: ";
                cin >> value;
                if (avl_tree.member(value))
                    cout << "Värdet " << value << " finns i trädet." << endl;
                else
                    cout << "Värdet " << value << " finns ej i trädet." << endl;
                break;
            case 4:
                if (avl_tree.empty())
                    cout << "Trädet är tomt!" << endl;
                else
                    cout << "Minsta värdet i trädet är " << avl_tree.find_min() << endl;
                break;
            case 5:
                if (avl_tree.empty())
                    cout << "Trädet är tomt!" << endl;
                else
                    cout << "Största värdet i trädet är " << avl_tree.find_max() << endl;
                break;
            case 6:
                /* Detta borde förstås bekräftas! */
                avl_tree.clear();
                cout << "Trädet är tömt!" << endl;
                break;
            case 7:
                if (avl_tree.empty()) {
                    cout << "Trädet är tomt!" << endl;
                } else {
                    avl_tree.print(cout);
                    cout << endl;
                }
                break;
            case 8:
                if (avl_tree.empty()) {
                    cout << "Trädet är tomt!" << endl;
                } else {
                    avl_tree.print_tree(cout);
                    cout << endl;
                }
                break;
            default:
                cout << "Felaktigt val!" << '\b' << endl;
                break;
            }
        } catch (const exception& e) {
            cout << e.what() << endl;
        } catch (...) {
            cout << "Ett okänt fel har inträffat." << endl;
        }
    }

    return 0;
}
