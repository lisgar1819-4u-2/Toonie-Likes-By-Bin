/**************************************************************
"Cooney Likes" Program

Student Name: Bin (Quoc Dat Phung)           Ms. Lindsay Cullum
Grade       : 11                            ICS4U
                                            Due  :  March 18, 2019

OBJECTIVE:
     A Game where the user asks the character Cooney what he likes,
     which creates a simple dialogue.

     In case I need to go back and fix it. I would let myself know
     that Cooney likes "moon", "butter", "summer", "ball", and "school"

****************************************************************/

#include <iostream>
using namespace std;
#include "apstring.h"
#include "apstring.cpp"
#include "string.h"
#include <cctype>
#include <ctype.h>

//Global Variable
int size = 5;   //An array of five words

//Function Prototype
bool CooneyLikes (apstring word, apstring str);

int main () {
    //Declaring Strings (str is defined things that Toonie likes) (word is inputed)
    apstring str[size] = {"moon", "butter", "summer", "ball", "school"}, word;
    apstring nextWord = "y";

    //Declaring number variables.
    //"notSame" implements if it sees that the inputed word does not match our defined words
    //"Counter" implements if the user guessed what Toonie likes correctly many times in a row.
    int notSame = 0;
    int counter = 0;

    //Asks user to input a keyword
    cout << "Welcome to the Cooney Game!" << endl;


    //The game will keep asking if the user wants to ask another question (variable is "nextWord)
    //If answer is no, then end the game.
    while (nextWord == "y") { //if yes, then continue

        cout << endl << "Do you want to type in your word(y/n)? ";
        cin >> nextWord;
        //if the answer is no, then break out of the while loop
        //and the game ends.
        if (nextWord != "y") {
            break;
        }

        cout << endl << "Type in your word: ";
        cin >> word;
        // for loop that checks if the inputted word matches with each of our defined terms
        for (int i = 0; i < size; i++) {
            // if true is returned from our function when the inputted word matches our defined word
            if (CooneyLikes(word,str[i])) {
                cout << "YES! Cooney likes " << word << "." <<endl;
                //counter implements because user guessed correctly (acts as points)
                counter++;
                // break because if the inputted word matches,
                // then there's no need to check with other words.
                break;
            // if it does not match our first defined word, then check with the other defined words.
            } else {
                //not same implements to see how many of our defined words do not match the inputted word
                notSame++;
                //if all five our our defined words do not match the user's word,
                // then the user guessed incorrectly.
                if (notSame == size) {
                    cout << "NO! Cooney does not like " << word << "." <<endl;
                    counter = 0;
                }
            }
        }
        //reset
        notSame = 0;

        //When the player wins, which...
        //happens when the user guesses the correct words
        //5 times in a row.
        if (counter == 5) {
            cout << endl << "YOU GUESSED 5 TIMES CORRECTLY. YOU WIN" << endl;
            break;
        }
    }

    return 0;
}

bool CooneyLikes (apstring word, apstring str) {
    //If the word matches our defined term, then return true. If not, return false.
    if (word == str) {
        return true;
    } else {
        return false;
    }
}
