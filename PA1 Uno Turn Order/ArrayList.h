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

        // Move affected players 1 position further
        for (int i = size_; position < i; i--) {
            data_[i] = data_[i - 1];
        }

        // Insert player at array position + increment
        data_[position] = value;
        size_++;
    }

    void deleteAnywhere(int position) override {
        // Check if array is not empty
        if (size_ == 0) {
            std::cout << "No players left." << std::endl;
            return;
        }

        // Check if position is valid
        if (position > size_ || position < 0) {
            std::cout << "Position invalid." << std::endl;
            return;
        }

        // Delete object at position
        delete data_[position];

        // Move affected players 1 position back
        for (int i = position; i < size_ - 1; i++) {
            data_[i] = data_[i + 1];
        }

        // Decrement + set old pointer to nullptr
        size_--;
        data_[size_] = nullptr;
    }

    void reverse() override {
        // Bounds 0 -> size_ - 1
        T* temp = nullptr;
        for (int i = 0, j = size_ - 1; i < j; i++, j--) {
            temp = data_[j];
            data_[j] = data_[i];
            data_[i] = temp;
        }
    }

    void concat(List<T>* other) override {
        // Check dynamic cast
        ArrayList<T>* casting = dynamic_cast<ArrayList<T>*>(other);
        if (casting == nullptr) {
            cout << "Lists are of different types." << endl;
            return;
        }
        // Check if remaining indexes in array can fit all of other
        if (CAPACITY - size_ < casting->size_) {
            cout << "New list has too many elements to fit." << endl;
            return;
        }
        // Move pointers from casting to this
        for (int i = 0; i < casting->size_; i++) {
            data_[size_] = casting->data_[i];
            casting->data_[i] = nullptr;
            size_++;
        }

        // Set casting array size to 0 (empty)
        casting->size_ = 0;
    }



private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};