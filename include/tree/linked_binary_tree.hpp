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
                Position(Node* nd=nullptr) : node{nd} {};

                // operator (based on node pointer)
                bool operator==(Position other) const {
                    return node == other.node;
                }

                bool operator!=(Position other) const {
                    return node != other.node;
                }

                bool is_null() const {
                    return node == nullptr;
                }

                bool is_root() const {
                    return node->parent == nullptr;
                }

                bool is_external() const {
                    return (node->left == nullptr) && (node->right == nullptr);
                }

                E& element() {
                    return node->element;
                }
                
                const E& element() const {
                    return node_element;
                }

                Position parent() const {
                    return Position(node->parent);
                }

                Position left() const {
                    return Position(node->left);
                }

                Position right() const {
                    return Position(node->right);
                }
                
                std::vector<Position> children() const {
                    
                    std::vector<Position> result;

                    //left child if valid
                    if (node->left != nullptr) {
                        result.push_back(Position(node->left));
                    }
                    if (node->right != nullptr) {
                        result.push_back(Position(node->right));
                    }

                    return result;
                }

                int num_children() const {

                    int result{0};
                    if (node->left != nullptr) {
                        result++;
                    }

                    if (node->right != nullptr) {
                        result++;
                    }
                    return result;
                }

        };  // end of Position class
        LinkedBinaryTree() = default; //tree with zero nodes

        int size() const {
            return sz;
        }

        bool empty() const {
            return sz.empty():
        }

        Position root() const {
            return Position(rt);
        }

        std::vector<Position> positions() const {
            std::vector<Position> gather;
            if (rt) {
                inorder(Position(rt), gather);
            }

            return gather;
        }

        void add_root(const E& e=E()) {
            rt = new Node(e, nullptr);
            sz = 1;
        }

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