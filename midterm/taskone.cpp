#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void checkNumericOrNot(string input){
    bool isNumeric = true;
    for(char c : input){
        if(!isdigit(c)){
            isNumeric = false;
            break;
        }
    }
    if(isNumeric){
        cout<<"Numeric constant"<<endl;
    }
    else{
        cout<<"Not numeric constant"<<endl;
    }
}

void checkOperatorOrNot(string input){
    string operators = "+-*/%=";
    bool isOperator = false;
    for(char c : input){
        if(operators.find(c) != string::npos){
            cout<<"Operator found: "<<c<<endl;
            isOperator = true;
        }
    }

    if(!isOperator){
        cout<<"No operator is found"<<endl;
    }
}

void checkCommentOrNot(string input){
    if(input.substr(0,2) == "//"){
        cout<<"Single line comment"<<endl;
    }
    else if(input.substr(0,2) == "/*" && input.substr(input.size()-2) == "*/"){
        cout<<"Multi line comment"<<endl;
    }
    else{
        cout<<"Not a comment"<<endl;
    }
}

void checkIdentifierOrNot(string input, string keywords[], int sizeOfKeywords){
    bool isKeyword = false;
    for(int i = 0; i<sizeOfKeywords; i++){
        if(input == keywords[i]){
            isKeyword = true;
            break;
        }
    }
    if (isKeyword) {
        cout << "Not a valid identifier" << endl;
        return;
    }

    bool isIdentifier = true;
    if(!(isalpha(input[0]) || input[0] == '_')){
        isIdentifier = false;
    }
    else{
        for(int i = 1; i < input.size(); i++){
            if(!(isalnum(input[i]) || input[i] == '_')){
                isIdentifier = false;
                break;
            }
        }
    }

    if(isIdentifier){
        cout<<"Valid identifier"<<endl;
    }
    else{
        cout<<"Not a valid identifier"<<endl;
    }
}

int main()
{
    //For checking NUMERIC CONSTANT
    /*string input;
    cout<<"Enter input: ";
    cin>>input;
    checkNumericOrNot(input);*/

    //For checking OPERATOR
    /*string input;
    cout<<"Enter input: ";
    cin>>input;
    checkOperatorOrNot(input);*/

    //For checking COMMENT
    /*string input;
    cout<<"Enter input: ";
    getline(cin, input);
    checkCommentOrNot(input);*/

    //For checking IDENTIFIER
    string keywords[] = {
        "int", "float", "double", "char", "void",
        "long", "short", "signed", "unsigned",
        "bool", "string", "class", "struct",
        "return", "if", "else", "while", "for", "switch", "case"
    };

    int sizOfKeywords = sizeof(keywords)/sizeof(keywords[0]);

    string input;
    cout<<"Enter input: ";
    cin>>input;
    checkIdentifierOrNot(input, keywords, sizOfKeywords);

    return 0;
}
