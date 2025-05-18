// Copyright 2021 NNTU-CS
#include "train.h"

void Train::addCar(bool light) {
    Car* newTrainCar = new Car{light, nullptr, nullptr};
    if (!first) {
        first = newTrainCar;
        first->next = first;
        first->prev = first;
    } else {
        Car* lastTrainCar = first->prev;
        lastTrainCar->next = newTrainCar;
        newTrainCar->prev = lastTrainCar;
        newTrainCar->next = first;
        first->prev = newTrainCar;
    }
}
int Train::getLength() {
    if (!first) return 0;

    Car* currentTrainCar = first;
    if (!currentTrainCar->light) {
        currentTrainCar->light = true;
        countOp++;
    }
    int length = 0;
    while (true) {
        int traversalSteps = 0;
        do {
            currentTrainCar = currentTrainCar->next;
            traversalSteps++;
            countOp++;
        } while (!currentTrainCar->light && currentTrainCar != first);
        if (currentTrainCar == first && !currentTrainCar->light) break;
        currentTrainCar->light = false;
        countOp++;
        for (int i = 0; i < traversalSteps; i++) {
            currentTrainCar = currentTrainCar->prev;
            countOp++;
        }
        if (!currentTrainCar->light) {
            length = traversalSteps;
            break;
        }
    }
    return length;
}
int Train::getOpCount() {
    return countOp;
}
