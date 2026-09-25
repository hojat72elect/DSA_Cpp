#ifndef DSA_STACK_H
#define DSA_STACK_H

#pragma once
#include <stdexcept>
#include <vector>

template<typename T>
class Stack {
private:
    std::pmr::vector<T> _elements;

public:
    void push(const T &value) {
        _elements.push_back(value);
    }

    void push(T &&value) {
        _elements.push_back(std::move(value));
    }

    [[nodiscard]] bool isEmpty() const noexcept {
        return _elements.empty();
    }

    [[nodiscard]] std::size_t length() const noexcept {
        return _elements.size();
    }

    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Cannot pop from an empty stack!");
        }

        _elements.pop_back();
    }

    T &peek() {
        if (isEmpty()) {
            throw std::out_of_range("Cannot peek into an empty stack!");
        }

        return _elements.back();
    }

    const T& peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Cannot peek into an empty stack!");
        }

        return _elements.back();
    }
};


#endif //DSA_STACK_H
