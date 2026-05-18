#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

string keywords[] = {
    "int","float","double","char","void",
    "long","short","signed","unsigned",
    "bool","string","class","struct",
    "return","if","else","while","for","switch","case"
};
int sizeOfKeywords = sizeof(keywords)/sizeof(keywords[0]);

bool isKeyword(const string& input) {
    for(int i=0;i<sizeOfKeywords;i++){
        if(input==keywords[i]) return true;
    }
    return false;
}
bool isNumeric(const string& input) {
    if(input.empty()) return false;
    for(char c:input) if(!isdigit(c)) return false;
    return true;
}
bool isBooleanConstant(const string& input) {
    return (input=="true"||input=="false");
}
bool isStringConstant(const string& input) {
    return (input.size()>=2 && input.front()=='"' && input.back()=='"');
}
bool isCharConstant(const string& input) {
    return (input.size()==3 && input.front()=='\'' && input.back()=='\'');
}
bool isOperator(const string& input) {
    string ops[]={"+","-","*","/","%","=","==","!=","<",">","<=",">="};
    int sz=sizeof(ops)/sizeof(ops[0]);
    for(int i=0;i<sz;i++) if(input==ops[i]) return true;
    return false;
}
bool isPunctuation(const string& input) {
    string punct[]={"(",")","{","}","[","]",";",",","<<",">>"};
    int sz=sizeof(punct)/sizeof(punct[0]);
    for(int i=0;i<sz;i++) if(input==punct[i]) return true;
    return false;
}
bool isIdentifier(const string& input) {
    if(isKeyword(input)||isBooleanConstant(input)) return false;
    if(!(isalpha(input[0])||input[0]=='_')) return false;
    for(int i=1;i<input.size();i++){
        if(!(isalnum(input[i])||input[i]=='_')) return false;
    }
    return true;
}

vector<string> tokenize(const string& line) {
    vector<string> tokens;
    string current;
    for(size_t i=0;i<line.size();i++){
        char c=line[i];
        if(c=='"'){
            string str="\"";
            i++;
            while(i<line.size() && line[i]!='"'){
                str+=line[i];
                i++;
            }
            if(i<line.size()) str+="\"";
            tokens.push_back(str);
        }
        else if(c=='\''){
            string str="\'";
            i++;
            if(i<line.size()) str+=line[i];
            if(i+1<line.size() && line[i+1]=='\''){
                str+="\'";
                i++;
            }
            tokens.push_back(str);
        }
        else if(c=='<'||c=='>'){
            if(i+1<line.size() && line[i+1]==c){
                string op; op+=c; op+=c;
                tokens.push_back(op);
                i++;
            } else {
                string op; op+=c;
                tokens.push_back(op);
            }
        }
        else if(ispunct(c) && c!='_' && c!='#'){
            string op; op+=c;
            tokens.push_back(op);
        }
        else if(!isspace(c)){
            string word;
            while(i<line.size() && !isspace(line[i]) && !ispunct(line[i])){
                word+=line[i];
                i++;
            }
            i--;
            tokens.push_back(word);
        }
    }
    return tokens;
}

int main(){
    ifstream file("input.txt");
    if(!file){
        cout<<"Error opening file!"<<endl;
        return 1;
    }
    string line;
    while(getline(file,line)){
        vector<string> tokens=tokenize(line);
        for(string token:tokens){
            if(isStringConstant(token)) cout<<token<<" is string constant"<<endl;
            else if(isCharConstant(token)) cout<<token<<" is character constant"<<endl;
            else if(isBooleanConstant(token)) cout<<token<<" is boolean constant"<<endl;
            else if(isKeyword(token)) cout<<token<<" is keyword"<<endl;
            else if(isNumeric(token)) cout<<token<<" is numeric constant"<<endl;
            else if(isOperator(token)) cout<<token<<" is operator"<<endl;
            else if(isPunctuation(token)) cout<<token<<" is punctuation"<<endl;
            else if(isIdentifier(token)) cout<<token<<" is identifier"<<endl;
            else cout<<token<<" is unknown"<<endl;
        }
    }
    file.close();
    return 0;
}
