#include <iostream>
#include "Map.h"

using namespace std;

int main() {
    TERRAIN** test = new TERRAIN*[3];
    for (unsigned i = 0; i < 3; i++) {
        test[i] = new TERRAIN[2];
    }
    for (unsigned i = 0; i < 3; i++) {
        for (unsigned j = 0; j < 2; j++) {
            test[i][j] = PLAIN;
        }
    }
    Map* map = new Map(test, 3, 2);
    cout << map->getHeight() << " " << map->getWidth() << " " << endl;

    delete map;
}