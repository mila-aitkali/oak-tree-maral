#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include <iostream>
#include <cassert>
#include "../src/hello.hpp"
using namespace std;

void test_squirrel_name() {
    Squirrel s("Nutty");
    assert(s.get_name() == "Nutty");
    cout << "PASS: test_squirrel_name\n";
}

void test_node_stores_data() {
    Squirrel s("Acorn");
    Node<Squirrel> node(&s);
    assert(node.get_data()->get_name() == "Acorn");
    cout << "PASS: test_node_stores_data\n";
}

void test_left_right_children() {
    Squirrel root_s("Root"), left_s("Left"), right_s("Right");
    Node<Squirrel> root(&root_s), left(&left_s), right(&right_s);

    root.set_left(&left);
    root.set_right(&right);

    assert(root.left()->get_data()->get_name()  == "Left");
    assert(root.right()->get_data()->get_name() == "Right");
    cout << "PASS: test_left_right_children\n";
}

void test_null_children_by_default() {
    Squirrel s("Lonely");
    Node<Squirrel> node(&s);
    assert(node.left()  == nullptr);
    assert(node.right() == nullptr);
    cout << "PASS: test_null_children_by_default\n";
}

int main() {
    test_squirrel_name();
    test_node_stores_data();
    test_left_right_children();
    test_null_children_by_default();
    cout << "\nAll tests passed!\n";
    return 0;
}