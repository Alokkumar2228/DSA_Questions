#include<iostream>
using namespace std;

class Gun{
public:
    int ammo;
    int damage;
    int scope;
};

class Player{
private:
    int health;
    int age;
    int score;
    bool alive;
    Gun gun;

public:
    void setHealth(int health){ this->health = health; }
    void setAge(int age){ this->age = age; }
    void setScore(int score){ this->score = score; }
    void setisALive(bool alive){ this->alive = alive; }

    void setGun(Gun gun){ this->gun = gun; }

    int getHealth(){ return health; }
    int getAge(){ return age; }
    int getScore(){ return score; }
    bool getisALive(){ return alive; }
    Gun getGun(){ return gun; }
};

// function to add the scores of two players
int AddScore(Player p1 , Player p2){
    return p1.getScore() + p2.getScore();
}

int main(){
    // Creating Gun objects
    Gun akm;
    akm.ammo   = 30;
    akm.damage = 300;
    akm.scope  = 2;

    Gun awm;
    awm.ammo   = 7;
    awm.damage = 1000;
    awm.scope  = 8;

    // Creating Player p1
    Player p1;
    p1.setAge(10);
    p1.setHealth(100);
    p1.setisALive(false);
    p1.setScore(500);
    p1.setGun(akm);

    // Creating Player p2
    Player p2;
    p2.setAge(20);
    p2.setHealth(200);
    p2.setisALive(true);
    p2.setScore(600);
    p2.setGun(awm);

    // Getting gun of player 1
    Gun g1 = p1.getGun();
    cout << g1.ammo   << endl;
    cout << g1.damage << endl;
    cout << g1.scope  << endl;

    // Dynamically creating a new player
    Player *p3 = new Player;
    p3->setAge(30);
    p3->setHealth(150);
    p3->setisALive(true);
    p3->setScore(700);
    p3->setGun(akm);

    // Adding scores of p1 and p2
    int total = AddScore(p1, p2);
    cout << "Total Score of p1 and p2 = " << total << endl;

    // Delete the dynamically created object
    delete p3;

    return 0;
}
