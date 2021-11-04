#include<bits/stdc++.h>
#define BASE 5
#define ll long long int

using namespace std;

/**
 * *    Work with 5 chars only 
 * *        a - 1 ; b - 2 ; c - 3 ; d - 4 ; e - 5 ;
*/

int code(char ch) {
    if(ch == 'a') return 1;
    else if (ch == 'b') return 2;
    else if (ch == 'c') return 3;
    else if (ch == 'd') return 4;
    else if (ch == 'e') return 5;
}

ll hash_string(string str) {
    ll value = 0;

    for(int i = str.length() - 1, j = 0; i >= 0, j < str.length(); i--, j++) {
        value += (code(str[j]) * BASE) % 13;
    }

    return value;
}

bool recheck(string pattern1, string pattern2) {
    return pattern1 == pattern2;
}


ll rabin_karp(string text, string pattern) {

    ll pattern_value = hash_string(pattern);
    ll current_pattern_value = 0;


    cout << pattern_value << "\n";

    for(int i = 0; i <= (text.length() - pattern.length()); i++) {
        current_pattern_value = hash_string( text.substr(i, pattern.length()) );
        if(pattern_value == current_pattern_value) {
            if(recheck( text.substr(i, pattern.length()) , pattern )) {
                cout << text.substr(i, pattern.length()) << "\n";
                return i;
            }
        }
    }
}


int main() {
    string text, pattern;

    fflush(stdin); 
    getline(cin, text); 
    fflush(stdout);
    
    fflush(stdin); 
    getline(cin, pattern); 
    fflush(stdout);

    cout << rabin_karp(text, pattern);
}