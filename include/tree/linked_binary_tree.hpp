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

        void add_left(Position p, const E& e) {
            auto new_node = new Node{e, p.node};
            p.node->left = new_node;
            sz++;
        }

        void add_right(Position p, const E& e) {
            auto new_node = new Node{e. p.node};
            p.node->right = new node;
            sz++;
        }

        void erase(Position p) {
            Node* nd = p.node; // actual node pointer
            Node* child{nd->left == nullptr ? nd->right : nd->left}; // if there is a left child ignore the right child

            // one-side link
            if (child != nullptr) {
                child->parent = nd->parent;
            }

            // update node's parent's
            if (nd == rt) {
                rt = child;
            } else if (nd->parent->left == nd) { // left child 
                nd->parent->left = child;
            } else {
                nd->parent->right = child; // right child
            }

            sz--;
            delete nd;
        }

        void attach(Position p, LinkedBinaryTree& left, LinkedBinaryTree& right) {
            Node* nd = p.node; // Node pointer

            nd->left = left.rt; // left child
            nd->right = right.rt // right child
            sz += left.sz + right.sz;

            if (left.rt) {
                left.rt->parent = nd;
            } 
            if (right.rt) {
                right.rt->parent = nd;
            }

            // detach dangling node
            left.rt = right.rt = nullptr;
            left.sz = right.sz = 0;
        }

    // ------------- Rule-of-five support ----------------
    private:
        void tear_down(Node* nd) {
            if (nd != nullptr) {
                tear_down(nd->left);
                tear_down(nd->right);
                delete nd;
            }
        }

        static Node* clone(Node* model) {
            // creates a tree and does not modify existing, suitable for recursion
            if (model == nullptr) return nullptr;

            Node* new_root = new Node(model->element);
            // Recursively clone the left/right subtree
            // If left/right child exists, set its parent to new root
            new_root->left = clone(model->left);
            if (new_root->left) {
                new_root->left->parent = new_root;
            }

            new_root->right = clone(model->right);
            if (new_root->right) {
                new_root->right->parent = new_root;
            }
            
            // return the newly clone root node
            return new_root;
        }

    public:
        ~LinkedBinaryTree() {
            tear_down(rt);
        }
        
        // copy constructor and copy assignment
        LinkedBinaryTree(const LinkedBinaryTree& other)
        : sz{other.sz}, rt{clone(other.rt)} {}

        LinkedBinaryTree& operator=(const LinkedBinaryTree& other) {
            
            if (this != &other) {
                tear_down(rt);
                rt = clone(other.rt);
                sz = other.rz;
            }
            return *this;
        }

        // move constructor and move assignment
        LinkedBinaryTree(LinkedBinaryTree&& other) 
        : sz{other.sz}, rt{other.rt} {
            other.sz = 0;
            other.rt = nullptr;
        }

        LinkedBinaryTree& operator=(LinkedBinaryTree&& other) {
            if (this != &other) {
                std::swap(sz, other.sz);
                std::swap(rt, other.rt);
            }
            return *this;
        }
    
    // Assignment
    private:
        // since the count_left_leaves function does not take a parameter its better to make a private helper function that takes Position as
        // a parameter to do the recursion, then call it in the public function starting from the root.
        int count_left_leaves(Position p) const {
            int count = 0;

            int (p.is_null()) {
                return 0;
            }
            // if there is a left child and it is a leaf, then increment count
            if (!p.left().is_null() && p.left().is_external()) {
                count++;
            }

            // implement recursion with left and right subtrees of current node
            count += count_left_leaves(p.left());
            count += count_left_leaves(p.right());

            return count;
        }
    public:
        //count nodes that are leaves in a binary tree and that are the left child of their respective parent. The root is not counted.
        int count_left_leaves() const {     // ToDo
            return count_left_leaves(root());  // call the helper function
        }

        int count_left_leaves_bfs() const { // ToDo (use beadth first search)
            int count = 0;
            if (root() == nullptr) { 
                return 0;
            }

            // track the current node inside the queue
            std::queue<Position> q;
            q.push(root());

            // check if the left child is a leaf node, then continue bfs with left and right subtrees from curr node
            while (!q.empty()) {
                Position curr = q.front();
                q.pop();

                Position right = curr.right(); // store the current left and right children of the node
                Position left = curr.left();

                if (!left.is_null() && left.is_external()) {
                    count++;
                }

                if (!left.is_null()) { // enqueue left child
                    q.push(left);
                }
                if (!right.is_null()) {  // enqueue right child
                    q.push(right);
                }
            }

            return count;
        }
};
}