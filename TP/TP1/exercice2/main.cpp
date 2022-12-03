#include <iostream>
#include <string>
using namespace std;

bool estVoyelle(const char & c){
    switch (c) {
        case 'a': case 'A':
        case 'e': case 'E':
        case 'i': case 'I':
        case 'o': case 'O':
        case 'u': case 'U':
        case 'y': case 'Y':
            return true;
        break;
    default:
        return false;
    }
}

int nbVoyelle(const string & s){
    int count = 0;
    for (char i : s)
        if(estVoyelle(i)) count++;
    return count;
}

bool palindrome(const string & s){
    if(s.size() <= 1) return true;
    return ((s.front() == s.back())) && palindrome(s.substr(1,s.size() - 2));
}

char decaler(int c, int x){
    return  (26 + c + x) % 26;
}

void chiffrage(string & s, signed int x){
    for (char & c : s) {
        if(('a' <= c) && (c <= 'z')){
            c = 'a' + decaler(c - 'a', x);
        }
        if(('A' <= c) && (c <= 'Z')){
            c = 'A' + decaler(c - 'A', x);
        }
    }
}

unsigned int chaine2entier(string const &s){
    if(s == "") return 0;
    else return chaine2entier(s.substr(0, s.size()-1))*10 + s.back() - '0';
}

int main()
{
    string str = "kayak";
    chiffrage(str,3);
    cout << str;
    return 0;
}
