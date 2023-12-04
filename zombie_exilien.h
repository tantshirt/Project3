#pragma once

#include <string>
#include "linkedlist_exilien.hpp"

using std::string;
using std::ostream;

class Zombie
{
private:
	char type;	

public:
	Zombie();
	Zombie(char type);

	char getType();
	bool operator== (const Zombie& other) const;
	friend ostream& operator << (ostream& out, const Zombie& zombie);	
};

void engine_action(LinkedList<Zombie>& list, const Zombie& randomZomb);
void caboose_action(LinkedList<Zombie>& list, const Zombie& randomZomb);
void jump_in_action(LinkedList<Zombie>& list, const Zombie& randomZomb, int position);
void everyone_out_action(LinkedList<Zombie>& list, const Zombie& randomZomb);
void you_out_action(LinkedList<Zombie>& list, const Zombie& randomZomb);
void brains_action(LinkedList<Zombie>& list, const Zombie& randomZomb);
void rainbow_action(LinkedList<Zombie>& list, const Zombie& randomZomb);
void friends_action(LinkedList<Zombie>& list, const Zombie& randomZomb);
