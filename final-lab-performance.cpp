#include <iostream>
using namespace std;

void processDFA(string input) {
    char state = 'A';
    bool deadEnd = false;

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        switch (state) {
            case 'A':
                if (c == 'a'){
                    state = 'B';
                }
                else if (c == 'b'){
                    state = 'C';
                }
                else{
                    deadEnd = true;
                }
                break;

            case 'B':
                if (c == 'a'){
                    state = 'D';
                }
                else if (c == 'b'){
                    state = 'E';
                }
                else{
                    deadEnd = true;
                }
                break;

            case 'C':
                if (c == 'a'){
                    state = 'F';
                }
                else if (c == 'b'){
                    state = 'G';
                }
                else{
                    deadEnd = true;
                }
                break;

            case 'D':
                if (c == 'a'){
                    state = 'D';
                }
                else if (c == 'b'){
                    state = 'H';
                }
                else{
                    deadEnd = true;
                }
                break;

            case 'E':
                if (c == 'a'){
                    state = 'F';
                }
                else if (c == 'b'){
                    state = 'I';
                }
                else{
                    deadEnd = true;
                }
                break;

            case 'F':
                if (c == 'a'){
                    state = 'F';
                }
                else if (c == 'b'){
                    state = 'J';
                }
                else{
                    deadEnd = true;
                }
                break;

            case 'G':
                if (c == 'a'){
                    state = 'F';
                }
                else if (c == 'b'){
                    state = 'G';
                }
                else{
                    deadEnd = true;
                }
                break;

            case 'H':
                if (c == 'a'){
                    state = 'F';
                }
                else if (c == 'b'){
                    state = 'G';
                }
                else{
                    deadEnd = true;
                }
                break;

            case 'I':
                if (c == 'a'){
                    state = 'F';
                }
                else if (c == 'b'){
                    state = 'I';
                }
                else{
                    deadEnd = true;
                }
                break;

            case 'J':
                if (c == 'a'){
                    state = 'F';
                }
                else if (c == 'b'){
                    state = 'K';
                }
                else{
                    deadEnd = true;
                }
                break;

            case 'K':
                if (c == 'a'){
                    state = 'F';
                }
                else if (c == 'b'){
                    state = 'K';
                }
                else{
                    deadEnd = true;
                }
                break;

            default:
                deadEnd = true;
                break;
        }

        if (deadEnd){
            break;
        }
    }

    cout << "Input: " << input << " \t-> ";
    if (!deadEnd) {
        cout << "Accepted (Final State: " << state << ")" << endl;
    } else {
        cout << "Rejected" << endl;
    }
}

int main() {
    string test1 = "a";
    string test2 = "aa";
    string test3 = "ab";
    string test4 = "c";
    string test5 = "bba";

    processDFA(test1);
    processDFA(test2);
    processDFA(test3);
    processDFA(test4);
    processDFA(test5);

    return 0;
}
