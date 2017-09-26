#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Names {
public:
    static string getName() {
        string names[29] = {"Abby", "Angel", "Annie", "Baby", "Bailey", "Bandit", "Bear", "Bella", "Bob", "Boo",
                            "Boots", "Bubba", "Buddy", "Buster", "Cali", "Callie", "Casper", "Charlie",
                            "Chester", "Chloe", "Cleo", "Coco", "Cookie", "Cuddles", "Daisy", "Dusty", "Felix",
                            "Fluffy", "Garfield"};
        return names[rand() % 29];
    }
};

class Animal {
private:
	string name; //имя
	int health; //здоровье
	int happiness; //счастье
	int food; //сытость
	int last_action; // время(!) последнего действия
public:
	Animal() {
		/*your code*/;
	}
	~Animal() {}

	string getName() {
		/*your code*/;
	}

	int getHealth() {
		/*your code*/;
	}

	int getHappiness() {
		/*your code*/;
	}

	int getFood() {
		/*your code*/;
	}

	void feed() {
		//изменить food
		//изменить last_action
	}

	void play() {
		//изменить happiness
		//изменить last_action
	}

	void wash() {
		//изменить health
		//изменить happiness
		//изменить last_action
	}

	void tick() {//уменьшает все показатели
		int currTime = time(NULL);
		health += /*your code*/;
		happiness += /*your code*/;
		food += /*your code*/;
		last_action = /*your code*/;
	}

	bool isAlive() {
		/*your code*/;
	}
};

class Game {
private:
	int amount;
	Animal animals[256];

	void print(int id) {
		cout << "Name: " <<
			animals[id].getName() << endl <<
			"Health: " << /*your code*/ <<
			endl << "Happiness: " <<
			/*your code*/ << endl <<
			"Food: " << /*your code*/ << endl
			<< endl;
	}

public:
	Game(int _amount) {
		/*your code*/;
	}
	~Game() {}

	void stats() {
		//печать статистики для каждого зверя
	}

	bool command(string action, int id) {
		//обработка команды - вызов для зверя из массива
	}

	bool step() {
		//уменьшает показатели для каждого зверя
		//проверка, есть ли погибшие звери

};

int main() {
	int n; //пользователь введет количество зверей; дописать код

	Game game(n);
	while (true) {
		string action;
		int id;

		//метод stats() для game - печать показателей всех зверей.
		//command(action, id) для game - ожидаем команды для конкретного зверя; 
		//можно осуществить проверку существования команды и сообщить о некорректности ввода.
		//метод step() для game - снятие очков health, happiness и food; если кто-то умер, завершить игру. 
	}
	return 0;
}

