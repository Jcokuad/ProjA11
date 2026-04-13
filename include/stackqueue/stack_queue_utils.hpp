//stackqueue/stack_queue_utils.hpp

#pragma once

#include "array/vector.hpp"
#include "list/doubly_linked.hpp"

#include "stackqueue/stack.hpp"
#include "stackqueue/queue.hpp"

#include <string>
#include <stdexcept>

std::string remove_duplicates(std::string input) {
    // Vector does not need to be specified here since it is already defined as the default container in stack.hpp
    dsac::stackqueue::stack<char> dup; 

    for (char let : input) {  // checks input from left to right
        if (!dup.empty() && dup.top() == let) { // if the curr char matches the top of the stack, it gets popped
            dup.pop();
        } else {
            dup.push(let); // if it does not match, then push to the stack
        }
    }
    std::string reverse; // the answer needs to be reversed since stack is LIFO
    while (!dup.empty()) {
        reverse += dup.top();
        dup.pop(); // removes the top after it is stored in reverse
    }

    std::string output; // reverse string to correct order in output
    for (int i = static_cast<int>(reverse.size()) - 1; i >= 0; i--) {
        output += reverse[i];
    }

    return output;
}

std::string clean_backspace_string(std::string input) {
    dsac::stackqueue::stack<char> b;

    for (char let : input) {
        if (let == '<') {   // if curr char is '<' then pop the top of the stack
            if (!b.empty()) {
                b.pop(); 
            }
        } else {
            b.push(let); // if not backspace then push to stack
        }
    }

    std::string reverse; // the answer needs to be reversed since stack is LIFO
    while (!b.empty()) {
        reverse += b.top();
        b.pop(); // removes the top after it is stored in reverse
    }

    std::string output; // adds reverse string to output to correct the order
    for (int i = static_cast<int>(reverse.size()) - 1; i >= 0; i--) {
        output += reverse[i];
    }

    return output;
}

template <
    typename T, 
    typename StackContainer=dsac::array::Vector<T>,
    typename QueueContainer=dsac::array::Vector<T>
    >
bool stack_contains(
    dsac::stackqueue::stack<T, StackContainer>& st, 
    dsac::stackqueue::queue<T, QueueContainer>& qu, 
    const T& elt) {
        if (!qu.empty()) {
            throw std::invalid_argument("Queue must start empty");
        }

        bool search = false;
        while (!st.empty()) {  // while stack is not empty, check the top value
            T curr = st.top(); // checks every value in the stack
            st.pop(); 

            if (curr == elt) {
                search = true; // if the top of the stack is equal to the value we are looking for
            }
            qu.push(curr); // push values from stack to queue
        }

        while (!qu.empty()) {
            st.push(qu.front()); // push values back to the stack making stack reversed
            qu.pop(); // clear queue
        }

        while(!st.empty()) {
            qu.push(st.top()); // push the stack back to the queue again
            st.pop(); // clear stack
        }

        while(!qu.empty()) {
            st.push(qu.front()); // push the queue back to the stack putting it back in original order
            qu.pop(); // clear queue
        }

        return search;
    }