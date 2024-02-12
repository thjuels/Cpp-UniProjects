#include "container.h"
#include <iostream>

Container::Container(int cap) : capacity(cap), size(0) {
    storage = new int[capacity];
}

Container::~Container() {
    delete[] storage;
}

void Container::insert(int element) {
    if (size == capacity) {
        std::cout << "Container is full." << std::endl;
        return;
    }
    storage[size++] = element;
}

void Container::remove(int element) {
    int i;
    for (i = 0; i < size; i++) {
        if (storage[i] == element) {
            break;
        }
    }
    if (i == size) {
        std::cout << "Element not found." << std::endl;
        return;
    }
    // Shift elements
    for (int j = i; j < size - 1; j++) {
        storage[j] = storage[j + 1];
    }
    size--;
}

bool Container::contains(int element) const {
    for (int i = 0; i < size; i++) {
        if (storage[i] == element) {
            return true;
        }
    }
    return false;
}

void Container::increaseCapacity(int additionalSpace) {
    int *newStorage = new int[capacity + additionalSpace];
    for (int i = 0; i < size; i++) {
        newStorage[i] = storage[i];
    }
    delete[] storage;
    storage = newStorage;
    capacity += additionalSpace;
}

int Container::getCapacity() const {
    return capacity;
}

int Container::getSize() const {
    return size;
}