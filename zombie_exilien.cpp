#include "zombie_exilien.h"

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::equal_to;

// Default constructor for the Zombie class
Zombie::Zombie()
{
    this->type = 'R'; // Initialize type to 'R' (default type)
}

// Constructor for the Zombie class with a type parameter
Zombie::Zombie(char _type)
{
	this->type = _type; // Set the zombie's type to the provided type
}

// Getter method to retrieve the type of the zombie
char Zombie::getType()
{
	return this->type;
}

// Overloaded << operator for easy printing of Zombie objects
ostream& operator << (ostream& out, const Zombie& zombie)
{
    out << "[" <<zombie.type << "]"; // Format output as [Type]
    return out;
}

// Overloaded == operator to compare zombies based on type
bool Zombie::operator== (const Zombie& other) const
{
	return type == other.type;
}

// Adds a new zombie to the front of the list
void engine_action(LinkedList<Zombie>& list, const Zombie& randomZomb) {
    list.AddToFront(randomZomb);
}

// Adds a new zombie to the end of the list
void caboose_action(LinkedList<Zombie>& list, const Zombie& randomZomb) {
    list.AddToEnd(randomZomb);
}

// Inserts a new zombie at a specific position in the list
void jump_in_action(LinkedList<Zombie>& list, const Zombie& randomZomb, int position) {
    list.AddAtIndex(randomZomb, position);
}

// Removes all zombies of a specific type from the list
void everyone_out_action(LinkedList<Zombie>& list, const Zombie& randomZomb) {
    list.RemoveAllOf(randomZomb);
}

// Removes the first occurrence of a specific type of zombie from the list
void you_out_action(LinkedList<Zombie>& list, const Zombie& randomZomb) {
    list.RemoveTheFirst(randomZomb);
}

// Performs a complex action: adds a zombie to the front, end, and middle of the list
void brains_action(LinkedList<Zombie>& list, const Zombie& randomZomb) {
    list.AddToFront(randomZomb); // add to the front
    list.AddToEnd(randomZomb); // add to the end
    int middle = list.Length() / 2;
    list.AddAtIndex(randomZomb, middle); // add to the middle
}

// Adds a rainbow of zombies to the end of the list
void rainbow_action(LinkedList<Zombie>& list, const Zombie& randomZomb) {
    engine_action(list, randomZomb);
    caboose_action(list, Zombie('R'));
    caboose_action(list, Zombie('Y'));
    caboose_action(list, Zombie('G'));
    caboose_action(list, Zombie('B'));
    caboose_action(list, Zombie('C'));
    caboose_action(list, Zombie('M'));    
}

// Adds a new zombie before or after an existing zombie of the same type
void friends_action(LinkedList<Zombie>& list, const Zombie& randomZomb) {
    Node<Zombie>* node = list.Find(randomZomb);
    if (node == nullptr) {
        caboose_action(list, randomZomb);
    }
    else {
        if (rand() % 2 == 0) {
            list.AddBefore(node, randomZomb);
        }
        else {
            list.AddAfter(node, randomZomb);
        }
    }
}
