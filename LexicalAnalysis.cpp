/*
=====================================================================

Lab1 Individual (REDO)
Lexical Analysis
Jerry Groom

=====================================================================
*/

#include "Text.h"
#include <iostream>
#include <cstring>
#include <fstream>

int main()
{

    ifstream progsamp;
    char token;

    progsamp.open("progsamp.dat");


    if (!progsamp.is_open())
    {
        cout << "Could not open Progsamp file." << endl;
        return 1; // 1 indicates error

    }
    else
    {
        progsamp >> token;
    }// Closes the if/else statement
    cout << "Here goes nothing......" << endl;
    cout << endl;
    cout << endl;
    //cout << "1: [ v ]" << endl; //This is added as a cheat to catch the V.
    /* I cant figure out why its not seeing the first token
    the program will only read the second token.
    */
    for(int i = 0; progsamp >> token; i++)
    {
        cout << i << ": " << "[ "<< token <<" ]"<< endl;
    }// closes for loop

    cout << "Success!!" << endl;
    cout << "Now we must close Progsamp.dat." << endl;
    progsamp.close(); // File needs to be closed when finished


}//Closes main function
