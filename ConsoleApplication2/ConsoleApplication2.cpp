// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "Graph.h"
using namespace std;
int main(int argc, char* argv[]) { //Need to do command line inputs
    std::ifstream fin(argv[1]);
    if (!fin)
    {
        std::cout << "Can't open input file.";
        return -1;
    }
    std::string line;
    std::string input;
    string command;
    Graph coolGraph;
    try
    {
        while (getline(fin, line))
        {
            string itemOne, itemTwo;
            if (line.size() == 0) continue;
            stringstream iss(line);
            iss >> command;
            if (command == "NODE")
            {
                iss >> itemOne;
                iss >> itemTwo;
                coolGraph.addNode(itemOne, itemTwo);
            }
            else if (command == "EDGE")
            {
                
                iss >> itemOne;
                iss >> itemTwo;
                coolGraph.addEdge(itemOne, itemTwo);
            }
            else if (command == "MAKE_ADJ")
            {
                iss >> itemOne;
                iss >> itemTwo;
                coolGraph.makeAdjacent(itemOne, itemTwo);
            }
            else if (command == "PRINT")
            {
                cout << coolGraph.toString();
            }
            else
            {
                cout << "COMMAND NOT RECOGNIZED";
            }

        }
    }
    catch (const char * exception)
    {
        cout << exception;
    }
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
