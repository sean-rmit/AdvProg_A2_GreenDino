#include "BoxLid.h"

#include <exception>
#include <iostream>


Lid::Lid() {
    lid = new LinkedList();
    lid->head = nullptr;
}

Lid::~Lid() {
    clearLid();
}

Lid::Lid(Lid& other) {

}

unsigned int Lid::size() {
    Node* current = lid->head;
    int length = 0;
    while (current != nullptr) {
        ++length;
        current = current->next;
    }
    return length;
}

void Lid::addTileToBack(char tile) {
    Node* newTile = new Node();
    newTile->tile = tile;
    newTile->next = nullptr;

    if (lid->head == nullptr) {
        lid->head = newTile;
    } else {
        Node* current = lid->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newTile;
    }
}

char Lid::removeTileFront() {
    if (lid->head != nullptr) {
        Node* toDelete = lid->head;
        char tile = toDelete->tile;
        lid->head = lid->head->next;
        delete toDelete;
        return tile;
    } else {
        throw std::logic_error("Deleting on empty boxlid");
    }
}

void Lid::clearLid() {
    while (lid->head != nullptr) {
        removeTileFront();
    }
}

std::string Lid::getTilesAsString() {
    std::string allTilesAsString;
    Node* current = lid->head;
    while (current != nullptr) {
        allTilesAsString += current->tile;
        current = current->next;
    }
    return allTilesAsString;
}