  // Day 10 - Sail vs Army - Dynamic Memory
#include <iostream>
#include <string>
using namespace std;

class Enemy {
public:
    string name;
    int health;

    Enemy() {
        name = "Unknown";
        health = 0;
    }

    Enemy(string n, int h) {
        name = n;
        health = h;
    }
};

int main() {
    int dushmanKitne;
    cout << "Kitne dushman spawn karu Sail? ";
    cin >> dushmanKitne;

    Enemy* army = new Enemy[dushmanKitne];

    for(int i = 0; i < dushmanKitne; i++) {
        army[i].name = "Gunda " + to_string(i+1);
        army[i].health = 30 + (i * 20);
        cout << army[i].name << " spawn hua! HP: " << army[i].health << endl;
    } // ye for ka } hai

    cout << "\nSail: Itne saare? Chalo marte hain!" << endl;

    delete[] army;
    cout << "Memory clean. Game over." << endl;

    return 0;
} // ye main ka } hai - ye bhool gaya tha tu
