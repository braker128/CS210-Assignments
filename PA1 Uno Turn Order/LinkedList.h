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

        // If position is outside range 0 to size_
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
        int posTracker = 0;
        Node<T>* current = head_;

        // zero position
        if (position == 0) {
            deleteFront();
            return;
        }

        // Check that position is valid
        if (position < 0) {
            cout << "Position invalid" << endl;
            return;
        }

        // Find delete location
        while (current != nullptr && posTracker < position - 1) {
            current = current->next;
            posTracker++;
        }

        // Check that current and current->next exist
        if (current == nullptr || current->next == nullptr) {
            cout << "Position invalid." << endl;
            return;
        }

        // Delete at position
        Node<T>* doomed = current->next;
        current->next = doomed->next;
        delete doomed->data;
        delete doomed;

    }

    void reverse() override {
        Node<T>* previous = nullptr;
        Node<T>* current = head_;

        // Flips pointer direction
        while (current != nullptr) {
            Node<T>* temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }

        head_ = previous;
    }

    void concat(List<T>* other) override {
        // Check dynamic cast
        LinkedList<T>* casting = dynamic_cast<LinkedList<T>*>(other);
        if (casting == nullptr) {
            cout << "Lists are of different types." << endl;
            return;
        }

        // If this list is empty
        if (head_ == nullptr) {
            head_ = casting->head_;
            casting->head_ = nullptr;
            return;
        }

        // If casting list is empty
        if (casting->head_ == nullptr) {
            return;
        }

        // Traverse to end of list; current->next == nullptr
        Node<T>* current = head_;
        while (current->next != nullptr) {
            current = current->next;
        }

        // Connect end of list to casting + set casting list to empty
        current->next = casting->head_;
        casting->head_ = nullptr;
    }

private:
    Node<T>* head_;
};