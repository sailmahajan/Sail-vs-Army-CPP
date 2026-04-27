# Sail-vs-Army-CPP
C++ Console Game | OOP Concepts | Array of Objects 

#include <iostream>
#include <string>
using namespace std;

class Fighter {
public:
    string name;
    int hp;
    int damage;
    
    Fighter(string n, int h, int d) {
        name = n;
        hp = h;
        damage = d;
    }
    
    void attack(Fighter &enemy) {
        cout << name << " ne " << enemy.name << " ko " << damage << " damage mara!" << endl;
        enemy.hp -= damage;
        if(enemy.hp < 0) enemy.hp = 0;
    }
    
    bool isAlive() { return hp > 0; }
    void showHP() { cout << name << " HP: " << hp << endl; }
};

int main() {
    // Sail vs 3 Enemies ka Array
    Fighter sail("Sail", 150, 35);
    Fighter enemies[3] = {
        Fighter("Prem", 50, 15),
        Fighter("Purvesh", 80, 20), 
        Fighter("Jayesh", 120, 25)
    };
    
    cout << "=== SAIL vs ENEMY ARMY ===" << endl;
    int round = 1;
    
    while(sail.isAlive()) {
        cout << "\n--- Round " << round << " ---" << endl;
        sail.showHP();
        
        // Sab enemies ko dikhao
        for(int i = 0; i < 3; i++) {
            if(enemies[i].isAlive()) {
                enemies[i].showHP();
            }
        }
        
        // Sail sabse pehle zinda enemy ko marega
        for(int i = 0; i < 3; i++) {
            if(enemies[i].isAlive()) {
                cout << "\nSail ki baari:" << endl;
                sail.attack(enemies[i]);
                break; // Ek round mein ek hi attack
            }
        }
        
        // Check karo koi enemy zinda hai ya nahi
        bool koiZindaHai = false;
        for(int i = 0; i < 3; i++) {
            if(enemies[i].isAlive()) {
                koiZindaHai = true;
                cout << "\n" << enemies[i].name << " ki baari:" << endl;
                enemies[i].attack(sail);
            }
        }
        
        if(!koiZindaHai) {
            cout << "\n🎉 SAIL NE SABKO HARA DIYA! ARMY DEFEATED!" << endl;
            break;
        }
        
        if(!sail.isAlive()) {
            cout << "\n💀 SAIL HAAR GAYA... GAME OVER!" << endl;
            break;
        }
        
        round++;
    }
    
    cout << "\nTotal Rounds: " << round << endl;
    return 0;
}
