#pragma once
#include <stdexcept>
#include <vector>

template<typename T>
class Stack {
private:
    std::vector<T> _elements;

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

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Cannot pop from an empty stack!");
        }

        T result = std::move(_elements.back());
        _elements.pop_back();
        return result;
    }

    T &peek() {
        if (isEmpty()) {
            throw std::out_of_range("Cannot peek into an empty stack!");
        }

        return _elements.back();
    }

    const T &peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Cannot peek into an empty stack!");
        }

        return _elements.back();
    }

    void clear() noexcept {
        _elements.clear();
    }
};
