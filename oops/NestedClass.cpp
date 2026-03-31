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

int main(){
    Gun akm;
    akm.ammo = 30;
    akm.damage = 300;
    akm.scope = 2;

    Player p1;
    p1.setAge(10);
    p1.setHealth(100);
    p1.setisALive(false);
    p1.setScore(500);
    p1.setGun(akm);

    Gun g1 = p1.getGun();

    cout<<g1.ammo<<endl;
    cout<<g1.damage<<endl;
    cout<<g1.scope<<endl;



    return 0;
}
