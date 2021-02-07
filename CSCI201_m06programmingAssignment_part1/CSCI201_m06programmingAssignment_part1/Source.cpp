//////////////////////////////////////////////
//  Caitlin J. Corbin                       //
//  M06 Programming Assignment Part 1        //
//  "NFL Football Team Program              //
//////////////////////////////////////////////


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player                                    // Parent class : Player
{
protected:                                      // Accessor 
    int playerID;                               // Variables
    string name;
public:
    Player(int playerID, string name);          // Constructor initializer 
                                                // Methods
    string getName();
    int getPlayerID();

    virtual string getPlayerPosition() = 0;     // Abstract methods
    virtual void play() = 0;
    virtual string toString();

};

Player::Player(int playerID, string name) : playerID(playerID), name(name)      // Player constructor
{};

string Player::getName(){       // Getters
    return name;
};

int Player::getPlayerID() {
    return playerID;
};

string Player::toString() {
    return "ID : " + to_string(playerID) + " Name : " + name;
};

class Offense : public Player   // Offense child class
{
protected:                      // Accessor + variables
    string position;
public:
    Offense(int playerID, string name, string position);    // Constructor initializer

    string getPlayerPosition(); // Methods
    void play();
    string toString();
};

Offense::Offense(int playerID, string name, string position) : Player(playerID, name), position(position)   // Constructor
{};


string Offense::getPlayerPosition() {   // Getters
    return position;
};

void Offense::play() { 
    cout << "Offense play position : " << position << endl;
};

string Offense::toString() {
    string var = Player::toString() + " Position : " + position + " Description : Offense";
    return var;
};

class Defense : public Player   // Ladder classes will repeat like the former
{
private:
    string position;
public:
    Defense(int playerID, string name, string position);

    string getPlayerPosition();
    void play();
    string toString();
};

Defense::Defense(int playerID, string name, string position) : Player(playerID, name), position(position)
{};

string Defense::getPlayerPosition() {
    return position;
};

void Defense::play() {
    cout << "Defense play position : " << position << endl;
};

string Defense::toString() {
    string var = Player::toString() + " Position : " + position + " Description : Defense";
    return var;
};

class SpecialTeams : public Player
{
private:
    string position;

public:
    SpecialTeams(int playerID, string name, string position);

    string getPlayerPosition();
    void play();
    string toString();
};

SpecialTeams::SpecialTeams(int playerID, string name, string position) : Player(playerID, name), position(position)
{};

string SpecialTeams::getPlayerPosition() {
    return position;
};

void SpecialTeams::play() {
    cout << "Special Teams play position : " << position << endl;
};

string SpecialTeams::toString() {
    string var = Player::toString() + " Position : " + position + " Description : Special Teams";
    return var;
};

void printMenu() {
    cout << "#####################################";
	cout << endl;
	cout << "1 - Add Offense Player" << endl;
	cout << "2 - Add Defense Player" << endl;
	cout << "3 - Add Special Teams Player" << endl;
	cout << "4 - Quit" << endl;
	cout << "Choice ( 1 - 4 ) : " << endl;
    cout << "#####################################" << endl;
};

int main()
{
    vector<Player*> players;    // Player data container 

    int choice, playerID;
    string name, position;


    do{     // Loop that allows user to add multiple players
        printMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Player id : ";
            cin >> playerID;
            cout << "Name: ";
            cin.ignore(100, '\n'); // ignore the ‘\n’ left by cin
            getline(cin, name);
            cout << "Offense position (QuarterBack / Wide Receiver / Tight End / Running Back / Offensive Lineman) : ";
            getline(cin, position);
            players.push_back(new Offense(playerID, name, position));
            break;
        case 2:
            cout << "Player id : ";
            cin >> playerID;
            cin.ignore(100, '\n');
            cout << "Name: ";
            getline(cin, name);
            cout << "Defense position (Defensive Lineman / Linebacker / Defensive Back) : ";
            getline(cin, position);
            players.push_back(new Defense(playerID, name, position));
            break;

        case 3:
            cout << "Player ID : ";
            cin >> playerID;
            cin.ignore(100, '\n');
            cout << "Name: ";
            getline(cin, name);
            cout << "Special Teams position (Kicker / Holder / Punter / Returner) : ";
            getline(cin, position);
            players.push_back(new SpecialTeams(playerID, name, position));
            break;
        case 4: continue;
        default: cout << "Invalid choice";

        }
    } while (choice != 4);

    cout << "Number of players : " << players.size() << endl;   // Prints player info to user
    if (players.size() > 0) {
        cout << "Info : " << endl;
        for (int i = 0; i < players.size(); i++) {
            cout << players[i]->toString() << endl;
        };
    };

    system("pause>0");
};