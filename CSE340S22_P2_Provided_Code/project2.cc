
/*
 * Copyright (C) Mohsen Zohrevandi, 2017
 *               Rida Bazzi 2019
 * Do not share this file with anyone
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "lexer.h"
#include <map>

using namespace std;
LexicalAnalyzer lexer;
Token token;

// struct for rule storing left-hand and right-hand side
struct GrammarRule {
    string LHS;
    vector<string> RHS;
};

struct GrammarRule rule;
// store all rules into vector
vector<map<string, vector<string>>> grammarRuleList;

// exits the program
void syntax_error() {
    cout << "SYNTAX ERROR!!!\n" << endl;
    exit(0);
}
Token expect(TokenType expected)
{
    Token t = lexer.GetToken();
    if (t.token_type != expected)
    {
        syntax_error();
    }
    return t;
}
void startReading();

// expect function to check if returned token from GetToken() matches expected
// calls syntax error to exit program otherwise
// read grammar
void ReadGrammar()
{
    startReading();
    expect(END_OF_FILE);
}
// Task 1
void printTerminalsAndNoneTerminals()
{
    cout << "1\n";
}

// Task 2
void RemoveUselessSymbols()
{
    cout << "2\n";
}

// Task 3
void CalculateFirstSets()
{
    cout << "3\n";
}

// Task 4
void CalculateFollowSets()
{
    cout << "4\n";
}

// Task 5
void CheckIfGrammarHasPredictiveParser()
{
    cout << "5\n";
}

void startReading() {
    token = lexer.GetToken();

    // while not at the end of file, then keep parsing through all rules
    while(token.token_type != END_OF_FILE) {
        if(token.token_type == ID) {
            rule.LHS = token.lexeme;
            expect(ARROW);
            token = lexer.GetToken();

            if(token.token_type == ARROW) {
                token = lexer.GetToken();

                while(token.token_type == ID) {
                    rule.RHS.push_back(token.lexeme);
                    token = lexer.GetToken();
                }
            }
            else {
                cout << "SYNTAX ERROR!!!\n" << endl;
                exit(0);
            }

        }
        else if(token.token_type == STAR) {
            startReading();
        }
        else if(token.token_type == HASH) {
            break;
        }
        else {
            cout << "SYNTAX ERROR!!!\n" << endl;
            exit(0);
        }
    }
}

int main (int argc, char* argv[])
{
    int task;

    if (argc < 2)
    {
        cout << "Error: missing argument\n";
        return 1;
    }

    /*
       Note that by convention argv[0] is the name of your executable,
       and the first argument to your program is stored in argv[1]
     */

    task = atoi(argv[1]);
    
    ReadGrammar();  // Reads the input grammar from standard input
                    // and represent it internally in data structures
                    // ad described in project 2 presentation file

    switch (task) {
        case 1: printTerminalsAndNoneTerminals();
            break;

        case 2: RemoveUselessSymbols();
            break;

        case 3: CalculateFirstSets();
            break;

        case 4: CalculateFollowSets();
            break;

        case 5: CheckIfGrammarHasPredictiveParser();
            break;

        default:
            cout << "Error: unrecognized task number " << task << "\n";
            break;
    }
    return 0;
}
