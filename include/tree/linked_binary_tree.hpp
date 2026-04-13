//tree/linked_binary_tree.hpp
#pragma once

#include <iostream>
#include <vector>
#include <queue>

#include "tree_traversal.hpp"

namespace dsac::tree {
template <typename E>
class LinkedBinaryTree{
    protected:
        class Node {
            //public for convenience
            public:
                E element;
                Node* parent;
                Node* left{nullptr};
                Node* right{nullptr};
                Node(E e, Node* p=nullptr): element{e}, parent{p}{};
        };// end of Node class

    protected:
        Node* rt{nullptr}; // root
        int sz{0}; // size

    public:
        class Position {
            private:
                // Raw pointer to a Node
                Node* node;
                // allow outer class access to node pointer
                friend class LinkedBinaryTree;
            public:
                // Wraps a Node* pointer 
                //(default is nullptr)
                Position(Node* nd=nullptr); // ToDo

                // operator (based on node pointer)
                bool operator==(Position other) const; // ToDo

                bool operator!=(Position other) const; // ToDo

                bool is_null() const; // ToDo

                bool is_root() const; // ToDo

                bool is_external() const; // ToDo

                E& element(); // ToDo
                
                const E& element() const; // ToDo

                Position parent() const; // ToDo

                Position left() const; // ToDo

                Position right() const; // ToDo
                
                std::vector<Position> children() const; // ToDo

                int num_children() const; // ToDo

        };  // end of Position class
        LinkedBinaryTree() = default; //tree with zero nodes

        int size() const; // ToDo

        bool empty() const; // ToDo

        Position root() const; // ToDo

        std::vector<Position> positions() const; // ToDo

        void add_root(const E& e=E()); // ToDo

        void add_left(Position p, const E& e); // ToDo

        void add_right(Position p, const E& e); // ToDo

        void erase(Position p); // ToDo

        void attach(Position p, LinkedBinaryTree& left, LinkedBinaryTree& right); // ToDo

    // ------------- Rule-of-five support ----------------
    private:
        void tear_down(Node* nd); // ToDo

        static Node* clone(Node* model); // ToDo

    public:
        ~LinkedBinaryTree(); // ToDo
        
        // copy constructor and copy assignment
        LinkedBinaryTree(const LinkedBinaryTree& other); // ToDo

        LinkedBinaryTree& operator=(const LinkedBinaryTree& other); // ToDo

        // move constructor and move assignment
        LinkedBinaryTree(LinkedBinaryTree&& other); // ToDo

        LinkedBinaryTree& operator=(LinkedBinaryTree&& other); // ToDo

    // Assignment
    public:
        int count_left_leaves() const; // ToDo

        int count_left_leaves_bfs() const; // ToDo
};
}