#include "TileBag.h"

#include <exception>
#include <iostream>

Bag::Bag() {
    bag = new LinkedList();
    bag->head = nullptr;
}

Bag::~Bag() {
    clearBag();
}

Bag::Bag(Bag& other) {

}

unsigned int Bag::size() {
    Node* current = bag->head;
    int length = 0;
    while (current != nullptr) {
        ++length;
        current = current->next;
    }
    return length;
}

void Bag::addTileToBack(tilePtr tile) {
    Node* newTile = new Node();
    newTile->tile = tile;
    newTile->next = nullptr;

    if (bag->head == nullptr) {
        bag->head = newTile;
    } else {
        Node* current = bag->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newTile;
    }
}

void Bag::removeTileFront() {
    if (bag->head != nullptr) {
        Node* toDelete = bag->head;
        bag->head = bag->head->next;
        delete toDelete;
    } else {
        throw std::logic_error("Deleting on empty list");
    }
}

void Bag::clearBag() {
    while (bag->head != nullptr) {
        removeTileFront();
    }
}

std::string Bag::getTilesAsString() {
    std::string allTilesAsString;
    Node* current = bag->head;
    while (current != nullptr) {
        allTilesAsString += current->tile;
        current = current->next;
    }
    return allTilesAsString;
}