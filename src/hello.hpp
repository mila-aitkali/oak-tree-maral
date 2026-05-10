#pragma once
#include <string>
using namespace std;

class Squirrel {
  private:
    string name;
  public:
    Squirrel(string name);
    string get_name();
};

template <typename T>
class Node {
  private:
    T* data;
    Node<T>* left_child;
    Node<T>* right_child;
  public:
    Node(T* data);
    void set_left(Node<T>* node);
    void set_right(Node<T>* node);
    Node<T>* left();
    Node<T>* right();
    T* get_data();
};

// Template definitions must live in the header
template <typename T>
Node<T>::Node(T* data) : data(data), left_child(nullptr), right_child(nullptr) {}

template <typename T>
void Node<T>::set_left(Node<T>* node) { left_child = node; }

template <typename T>
void Node<T>::set_right(Node<T>* node) { right_child = node; }

template <typename T>
Node<T>* Node<T>::left() { return left_child; }

template <typename T>
Node<T>* Node<T>::right() { return right_child; }

template <typename T>
T* Node<T>::get_data() { return data; }
