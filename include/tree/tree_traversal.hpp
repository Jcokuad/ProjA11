//tree_traversal.hpp
#pragma once
#include "linked_binary_tree.hpp"
#include <queue>
#include <deque>

namespace dsac::tree {

//container must be able to store 
//objects of type Position
template <typename Position, typename Container>
void preorder(Position p, Container& visited); // ToDo

template <typename Position, typename Container>
void postorder(Position p, Container& visited); // ToDo


template <typename Position, typename Container>
void breadthfirst(Position p, Container& visited); // ToDo


template <typename Position>
std::queue<Position> breadthfirst_2(Position p); // ToDo



template <typename Position, typename Container>
void inorder(Position p, Container& visited); // ToDo

}//end namespace