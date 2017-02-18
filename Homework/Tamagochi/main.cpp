#include <iostream>
#include <string>

using namespace std;

class Names {
public:
    static string getName()
    {
        string names[29] = { "Abby", "Angel", "Annie", "Baby", "Bailey", "Bandit", "Bear", "Bella", "Bob", "Boo", "Boots", "Bubba", "Buddy", "Buster", "Cali", "Callie", "Casper", "Charlie",
                              "Chester", "Chloe", "Cleo", "Coco", "Cookie", "Cuddles", "Daisy", "Dusty", "Felix", "Fluffy", "Garfield" };
        return names[rand()%29];
    }
};

class Tamagochi {
private:
    int health;
    int happiness;
    int food;
    int last_play, last_feed, last_wash;
    string name;
public:
    Tamagochi()
    {
        name = Names::getName();
        health = 100 + rand()%150;
        happiness = 100 + rand()%150;
        food = 100 + rand()%150;
        last_play = time(NULL);
        last_feed = time(NULL);
        last_wash = time(NULL);
    }
    const string &getName() const {
        return name;
    }
    bool isAlive()
    {
        if (health<=0)
            return false;
        if (food<=0)
            return false;
        if (happiness<=0)
            return false;
        return true;
    }
    int getHealth() const {
        return health;
    }

    void wash() {
        health += 150;
        last_wash = time(NULL);
    }

    int getHappiness() const {
        return happiness;
    }

    void play() {
        happiness += 150;
        last_play = time(NULL);
    }

    int getFood() const {
        return food;
    }

    void feed() {
        food += 150;
        last_feed = time(NULL);
    }

    void tick()
    {
        int ntime = time(NULL);
        health += last_wash - ntime;
        food += last_feed - ntime;
        happiness += last_play - ntime;

        last_play = ntime;
        last_feed = ntime;
        last_wash = ntime;
    }

};

class Game {
private:
    int n;
    Tamagochi animals[255];

    void print(int id)
    {
        cout<<" "<<animals[id].getName()<<" ("<<id<<"):"<<endl;
        cout<<"        Health: "<<animals[id].getHealth()<<endl;
        cout<<"        Happiness: "<<animals[id].getHappiness()<<endl;
        cout<<"        Food: "<<animals[id].getFood()<<endl<<endl;
    }
public:
    Game(int _n)
    {

        if (n>255)
            n = 255;
        n = _n;
    }
    void printStats()
    {
        for (int i = 0; i<n; i++)
        {
            print(i);
        }
    }
    int step()
    {
        for (int i = 0; i<n; i++)
        {
            animals[i].tick();
            if (!animals[i].isAlive())
                return i;
        }
        return -1;
    }
    bool action(int id, string& a)
    {
        if (id<0 || id>n-1)
            return false;
        if (a == "feed")
        {
            animals[id].feed();
            return true;
        }
        if (a == "play")
        {
            animals[id].play();
            return true;
        }
        if (a == "wash")
        {
            animals[id].wash();
            return true;
        }
        return false;
    }


};

int main() {
    int n;

    cout<<"Welcome to Tamagochi 0.1!"<<endl;
    cout<<"Enter number of animals: ";
    cin>>n;

    Game game(n);

    string command;
    int id;

    while (true)
    {
        game.printStats();

        cout<<"enter command: ";
        cin>>command;
        if (command == "exit") break;

        cin>>id;
        while (!game.action(id, command))
        {
            cout<<"invalid command!"<<endl<<"enter command: ";
        }

        int result = game.step();
        if (result != -1)
        {
            cout<<"Tamagochi "<<result<<" is dead :("<<endl;
            cout<<"Game over!"<<endl;
            break;
        }
    }

    cout<<"Goodbye!";
    return 0;
}