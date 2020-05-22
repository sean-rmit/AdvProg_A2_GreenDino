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

void Bag::addTileToBack(char tile) {
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

char Bag::removeTileFront() {
    if (bag->head != nullptr) {
        Node* toRemove = bag->head;
        bag->head = bag->head->next;
        char tile = toRemove->tile;
        delete toRemove;
        return tile;
    } else {
        throw std::logic_error("Deleting on empty tilebag");
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

void Bag::fillBagWithTiles(int seed) {
    // temporary vector to fill up the TileBag
    std::vector<char> tempVector;

    // fill tempVector with red tiles
    for (int i = 0; i < RED_TILES_NUM; i++) {
        tempVector.push_back(RED);
    }
    // fill tempVector with yellow tiles
    for (int i = 0; i < YELLOW_TILES_NUM; i++) {
        tempVector.push_back(YELLOW);
    }
    // fill tempVector with dark blue tiles
    for (int i = 0; i < DARKBLUE_TILES_NUM; i++) {
        tempVector.push_back(DARKBLUE);
    }
    // fill tempVector with light blue tiles
    for (int i = 0; i < LIGHTBLUE_TILES_NUM; i++) {
        tempVector.push_back(LIGHTBLUE);
    }
    // fill tempVector with black tiles
    for (int i = 0; i < BLACK_TILES_NUM; i++) {
        tempVector.push_back(BLACK);
    }

    /* 
     *Shuffling TileBag by inserting from random tempVector positions into the TileBag
     *Reduce max index of tempVector by 1 every loop to adjust according to tempVector's size
     */
    int minIndex = 0; // min index of tempVector
    int maxIndex = 99; // max index of tempVector
    int RandIndex = -1; // random index generated
    // checks if a seed is provided, default seed value = 0 means no seed is provided
    if (seed == 0) {
        std::random_device engine;
        for (int i = 0; i < TILEBAG_SIZE; i++) {
            std::uniform_int_distribution<int> uniform_dist(minIndex, maxIndex);
            RandIndex = uniform_dist(engine);
            // tile added from tempVector to TileBag
            addTileToBack(tempVector.at(RandIndex));
            // tile erased from tempVector, reducing the size of tempvector by 1
            tempVector.erase(tempVector.begin() + RandIndex);
            maxIndex--;
        }
    }
    // if a seed is provided, the seed will be used
    else {
        std::default_random_engine engine(seed);
        for (int i = 0; i < TILEBAG_SIZE; i++) {
            std::uniform_int_distribution<int> uniform_dist(minIndex, maxIndex);
            RandIndex = uniform_dist(engine);
            // tile added from tempVector to TileBag
            addTileToBack(tempVector.at(RandIndex));
            // tile erased from tempVector, reducing the size of tempvector by 1
            tempVector.erase(tempVector.begin() + RandIndex);
            maxIndex--;
        }
    }
}