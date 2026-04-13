//stackqueue/stack_queue_utils.hpp

#pragma once

#include "array/vector.hpp"
#include "list/doubly_linked.hpp"

#include "stackqueue/stack.hpp"
#include "stackqueue/queue.hpp"

#include <string>
#include <stdexcept>

std::string remove_duplicates(std::string input);

std::string clean_backspace_string(std::string input);

template <
    typename T, 
    typename StackContainer=dsac::array::Vector<T>,
    typename QueueContainer=dsac::array::Vector<T>
    >
bool stack_contains(
    dsac::stackqueue::stack<T, StackContainer>& st, 
    dsac::stackqueue::queue<T, QueueContainer>& qu, 
    const T& elt);