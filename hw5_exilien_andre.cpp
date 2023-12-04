#include "zombie_exilien.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using std::cout;
using std::cin;
using std::srand;
using std::endl;

int main(int argc, char* argv[]) {
    // Seed the random number generator
    if (argc > 2 && string(argv[1]) == "-s") {
        int seed = atoi(argv[2]);  // Convert the third argument to an integer for seed
        srand(seed);               // Seed the random number generator with the provided seed
    }
    else {
        srand(time(0));            // Seed the random number generator with the current time
    }

    char types[7] = "RYGBCM";      // Define zombie types as characters in an array

    int rounds;                    // Declare variable to store the number of rounds
    cout << "How many rounds do you want to run? ";
    cin >> rounds;                 // Take user input for the number of rounds

    LinkedList<Zombie> congaLine;  // Declare a linked list of Zombies
    int partyOver = false;         // Flag to determine if the party is over

    // Main game loop
    for (int round = 0; round < rounds; ++round) {
        // Display the current round and the size of the conga line
        cout << "Round: " << round << endl;
        cout << "Size: " << congaLine.Length() << " :: ";
        congaLine.PrintList();
        cout << endl;

        int action = rand() % 8;     // Randomly choose an action
        int zombie = rand() % 6;     // Randomly select a zombie type

        // Switch case to handle different actions based on the random choice
        switch (action) {
        // Each case corresponds to a different action
        // and prints out the action taken and the type of zombie involved
        case 0:
            engine_action(congaLine, Zombie(types[zombie]));
            cout << "New Zombie: [" << types[zombie] << "] -- Action: [Engine!]" << endl;
            break;
        // Similar structure for other cases
        // ...
        }

        // Print the size and the current state of the conga line
        cout << "Size: " << congaLine.Length() << " ::  [<R|Y|G|B|M|C>]=";
        congaLine.PrintList();
        cout << endl;

        // Check if the conga line is empty and end the party if so
        if (congaLine.Length() == 0) {
            partyOver = true;
            cout << "The Party is Over." << endl;
            break;
        }
    }

    // Check if the party is not over and prompt the user to continue
    if (!partyOver) {
        string continueParty;
        cout << "Do you want to continue the party? (yes/no) ";
        cin >> continueParty;
        // Further logic to handle the user's decision can be implemented here
    }

    return 0; // End of the program
}
