#include <iostream>
using namespace std;

class Cricketer {

private:
    class Player {
    public:
        string name;
        int age;
        int matches;
        int avg;
    };

public:
    Player player;

    void setData(string name, int age, int matches, int avg) {
        player.name = name;
        player.age = age;
        player.matches = matches;
        player.avg = avg;
    }

    void getData() {
        cout << player.name << endl;
        cout << player.age << endl;
        cout << player.matches << endl;
        cout << player.avg << endl;
    }
};

int main() {
    Cricketer player[3];

    for (int i = 0; i < 3; i++) {
        string name;
        int age;
        int matches;
        int avg;

        cin >> name >> age >> matches >> avg;
        player[i].setData(name, age, matches, avg);
    }

    for (int i = 0; i < 3; i++) {
        player[i].getData();
        cout << "-------------------" << endl;
    }

    return 0;
}
