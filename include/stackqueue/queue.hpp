#pragma once

#include "array/vector.hpp"
#include "list/doubly_linked.hpp"

namespace dsac::stackqueue {
/// A simplified version of the STL queue class
template <typename T, typename Container=dsac::list::DoublyLinkedList<T>>
class queue {
    private:
        Container data;

    public:
        /// return the number of elements currently in the queue
        int size() const;
        
        /// return whether the queue is currently empty
        bool empty() const;

        /// return const reference to the first element of the queue
        const T& front() const;

        /// return live (non-const) reference to the first element of the queue
        T& front();

        /// return const reference to the last element of the queue
        const T& back() const;

        /// return live (non-const) reference to the last element of the queue
        T& back();

        /// add an element to the back of the queue
        void push(const T& elem);

        /// remove the first element from the queue
        void pop();
};

}  // namespace dsac::stackqueue
