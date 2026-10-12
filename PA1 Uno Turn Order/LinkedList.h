//
// Created by comet on 9/17/2026.
//

#pragma once
#include "Node.h"
#include "List.h"
using namespace std;

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr) {}
    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
    }

    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
    }

    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }

    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

    /* TODO:
        - addAnywhere()
        deleteAnywhere()
        reverse()
        concat()
    */

    void addAnywhere(int position, T* value) override {
        int posTracker = 0;
        Node<T>* current = head_;

        // zero position
        if (position == 0) {
            addFront(value);
            return;
        }

        // Check that position is > 0
        if (position < 0) {
            cout << "Position invalid" << endl;
            return;
        }

        // Find insert location
        while (current != nullptr && posTracker < position - 1) {
            current = current->next;
            posTracker++;
        }

        // If position is outside 0 to size_
        if (current == nullptr) {
            cout << "Position invalid." << endl;
            return;
        }

        // Insert at position
        Node<T>* fresh = new Node<T>(value);
        fresh->next = current->next;
        current->next = fresh;
    }

    void deleteAnywhere(int position) override {

    }

    void reverse() override {

    }

    void concat(List<T>* other) override {

    }

private:
    Node<T>* head_;
};