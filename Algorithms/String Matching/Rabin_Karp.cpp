#include<bits/stdc++.h>
#define BASE 5
#define ll long long int

using namespace std;


int code(char ch) {
    string characters = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i < characters.length(); ++i) {
        if(ch == characters[i]) {
            return i + 1;
        }
    }
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

string to_lower(string str) {
    for_each(str.begin(), str.end(), [](char &c) {
        c = tolower(c);
    });

    return str;
}

int main() {
    string text, pattern;

    fflush(stdin); 
    getline(cin, text); 
    fflush(stdout);
    
    fflush(stdin); 
    getline(cin, pattern); 
    fflush(stdout);

    
    cout << rabin_karp(to_lower(text), to_lower(pattern));
}