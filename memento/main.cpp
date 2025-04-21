#include <iostream>
#include "memento.hpp"
using namespace std;

int main(){
    shared_ptr<Player> player = make_shared<Player>("dustball");
    shared_ptr<Caretaker> caretaker = make_shared<Caretaker>();
    cout<<player->toString()<<endl;


    shared_ptr<Memento> memento = player->createMemento();
    caretaker->addMemento(memento);
    player->levelUp();
    cout<<player->toString()<<endl;


    memento = player->createMemento();
    caretaker->addMemento(memento);
    player->levelUp();
    cout<<player->toString()<<endl;


    memento = player->createMemento();
    caretaker->addMemento(memento);
    player->levelUp();
    cout<<player->toString()<<endl;


    memento = caretaker->getMementoByIndex(0);
    player->setMemento(memento);
    cout<<player->toString()<<endl;

    return 0;
}

// Name: dustball, State: Healthy Power: 100.000000, Experience: 0.000000, Level: 0, Attack: 10.000000, Defense: 10.000000
// Name: dustball, State: Healthy Power: 110.000000, Experience: 0.000000, Level: 1, Attack: 20.000000, Defense: 20.000000
// Name: dustball, State: Healthy Power: 120.000000, Experience: 0.000000, Level: 2, Attack: 30.000000, Defense: 30.000000
// Name: dustball, State: Healthy Power: 130.000000, Experience: 0.000000, Level: 3, Attack: 40.000000, Defense: 40.000000
// Name: dustball, State: Healthy Power: 100.000000, Experience: 0.000000, Level: 0, Attack: 10.000000, Defense: 10.000000