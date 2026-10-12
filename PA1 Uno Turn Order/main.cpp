#include <iostream>
#include "List.h"
#include "Player.h"

using namespace std;
int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    unique_ptr<List<Player>> table = makeList<Player>();
    cout << "Michael, Steve, Chloe, and John sit down at the table." << endl;
    table->addFront(new Player(26, "John"));   // 3
    table->addFront(new Player(33, "Chloe"));  // 2
    table->addFront(new Player(6, "Steve"));   // 1
    table->addFront(new Player(2, "Michael")); // 0
    table->print(); cout << endl;

    cout << "Jesse pulls up a chair between Steve and Chloe." << endl;
    table->addAnywhere(2, new Player(12, "Jesse"));
    table->print(); cout << endl;

    cout << "Chloe plays a Reverse card!" << endl;
    table->reverse();
    table->print(); cout << endl;

    cout << "Steve runs out of cards and steps away." << endl;
    table->deleteAnywhere(3);
    table->print(); cout << endl;

    cout << "A second table with Janet, Henry, and Tim forms." << endl;
    unique_ptr<List<Player>> table2 = makeList<Player>();
    table2->addFront(new Player(22, "Tim"));
    table2->addFront(new Player(49, "Henry"));
    table2->addFront(new Player(13, "Janet"));
    table2->print(); cout << endl;

    cout << "The two tables join together." << endl;
    table->concat(table2.get());
    table->print();
    table2->print(); // Nothing prints because table2 is empty
    cout << endl;


    return 0;
}
