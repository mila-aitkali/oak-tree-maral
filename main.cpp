#include <iostream>
#include "src/hello.hpp"
using namespace std;

int main() {
    Squirrel cheeks("Cheeks");
    Squirrel squeaks("Squeaks");
    Squirrel fluffybutt("Mr. Fluffy Butt");

    Node<Squirrel> node_one(&cheeks);
    Node<Squirrel> node_two(&squeaks);
    Node<Squirrel> node_three(&fluffybutt);

    node_one.set_left(&node_two);
    node_one.set_right(&node_three);

    string root  = node_one.get_data()->get_name();
    string left  = node_one.left()->get_data()->get_name();
    string right = node_one.right()->get_data()->get_name();

    cout << "    " << root << "\n";
    cout << "    /      \\" << "\n";
    cout << left << "   " << right << "\n";

    return 0;
}