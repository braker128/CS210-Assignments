//
// Created by comet on 9/15/2026.
//

#pragma once

#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
class ArrayList : public List<T> {
public:
    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }

    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) return true;
        }
        return false;
    }

    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }
        std::cout << std::endl;
    }

    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }

    /* TODO:
        - addAnywhere()
        deleteAnywhere()
        reverse()
        concat()
    */

    void addAnywhere(int position, T* value) override {
        // Check if array is full
        if (size_ >= CAPACITY) {
            std::cout << "Maximum players reached." << std::endl;
            return;
        }

        // Check if position is valid
        if (position > size_ || position < 0) {
            std::cout << "Position invalid." << std::endl;
            return;
        }

        // Move all players 1 position further
        for (int i = size_; position < i; i--) {
            data_[i] = data_[i - 1];
        }

        // Insert player at array position + increment
        data_[position] = value;
        size_++;
    }
/*
    - position is 0-indexed. position == 0 means the current front, that should behave identically
    to deleteFront.

    - The valid range is [0, size - 1] inclusive, note this is not the same range as addAnywhere.

    - Think about why an empty list, or position == size, it’s a valid add target.

    - Anything outside that range is invalid. Print a message and return, don’t touch the list, don’t
    crash.

    - Same two-delete rule as deleteFront: free the T the node or slot points at, then remove the
    slot or node itself.

    - LinkedList doesn’t track its length yet. Add a size member to it, the same way ArrayList
    already has one, and update it in addFront, deleteFront, addAnywhere, and deleteAnywhere,
    every place the list grows or shrinks. Both bounds checks above depend on it being correct.
*/
    void deleteAnywhere(int position) override {
        if (size_ == 0) {
            std::cout << "No players left." << std::endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    void reverse() override {

    }

    void concat(List<T>* other) override {

    }



private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};