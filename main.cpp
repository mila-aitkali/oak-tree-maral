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

    //        Cheeks
    //       /      \
    //   Squeaks   Mr. Fluffy Butt
    node_one.set_left(&node_two);
    node_one.set_right(&node_three);

    Node<Squirrel>* retrieved_left  = node_one.left();
    Node<Squirrel>* retrieved_right = node_one.right();

    cout << "Root:  " << node_one.get_data()->get_name()       << "\n";
    cout << "Left:  " << retrieved_left->get_data()->get_name()  << "\n";
    cout << "Right: " << retrieved_right->get_data()->get_name() << "\n";

    return 0;
}