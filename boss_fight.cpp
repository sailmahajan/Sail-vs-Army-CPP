#include <iostream>
using namespace std;

class Sail {
public:
    string name;
    int health;
    int attackPower;
    
    Sail() {
        name = "Sail";
        health = 150;      
        attackPower = 50;  
        cout << "Sail maidan mein aa gaya! HP: " << health << " ATK: " << attackPower << endl;
    }
    
    void attack() {
        cout << name << " ne " << attackPower << " damage mara!" << endl;
    }
    
    ~Sail() {
        cout << "Sail: Mission complete. Memory clean." << endl;
    }
};

class DarkLord {
public:
    string name;
    int health;
    int attackPower;
    
    DarkLord() {
        name = "DarkLord";
        health = 200;
        attackPower = 30;
        cout << "DarkLord aa gaya! HP: " << health << endl;
    }
    
    void attack() {
        cout << name << " ne " << attackPower << " damage mara!" << endl;
    }
    
    ~DarkLord() {
        cout << "DarkLord: Nooooo... main haar gaya... SAIL OP HAI!" << endl;
    }
};

int main() {
    cout << "=== FINAL BOSS FIGHT TO THE DEATH ===" << endl;
    
    Sail* hero = new Sail();        
    DarkLord* boss = new DarkLord(); 
    
    cout << "\n--- FIGHT START ---" << endl;
    
    int round = 1;
    while(hero->health > 0 && boss->health > 0) {
        cout << "\n--- Round " << round << " ---" << endl;
        
        hero->attack();
        boss->health -= hero->attackPower;
        cout << "Boss HP: " << boss->health << endl;
        
        if(boss->health <= 0) {
            cout << "DarkLord dharti pe gir gaya!" << endl;
            break; 
        }
        
        boss->attack();
        hero->health -= boss->attackPower;
        cout << "Sail HP: " << hero->health << endl;
        
        round++;
    }
    
    cout << "\n--- FIGHT END ---" << endl;
    
    if(hero->health > 0 && boss->health <= 0) {
        cout << "SAIL WINS! DarkLord is defeated!" << endl;
        cout << "FLAWLESS VICTORY! SAIL OP!" << endl;
    } else {
        cout << "Sail haar gaya... Game Over" << endl;
    }
    
    delete hero;
    delete boss;
    
    return 0;
}
