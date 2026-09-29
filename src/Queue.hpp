#pragma once
#include <deque>
#include <stdexcept>

template<typename T>
class Queue {
private:
    std::deque<T> _elements;

public:
    void enqueue(const T &value) {
        _elements.push_back(value);
    }

    void enqueue(T &&value) {
        _elements.push_back(std::move(value));
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Cannot dequeue from an empty queue!");
        }

        T result = std::move(_elements.front());
        _elements.pop_front();
        return result;
    }

    T &peekFront() {
        if (isEmpty()) {
            throw std::out_of_range("Cannot peek to the front of an empty queue!");
        }

        return _elements.front();
    }

    const T &peekFront() const {
        if (isEmpty()) {
            throw std::out_of_range("Cannot peek to the front of an empty queue!");
        }

        return _elements.front();
    }

    [[nodiscard]] bool isEmpty() const noexcept {
        return _elements.empty();
    }

    [[nodiscard]] std::size_t length() const noexcept {
        return _elements.size();
    }

    void clear() noexcept {
        _elements.clear();
    }
};
