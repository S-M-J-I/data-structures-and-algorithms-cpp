#include<bits/stdc++.h>

using namespace std;

string form_string(string str) {
    string s = "";
    for(int i = 1; i < str.length()-1; ++i) {
        s.push_back(str[i]);
    }


    return s;
}


bool isPalindrome(string str) {
    if(str.length() > 1) {
        if( str[0] == str[str.length() - 1] ) {
            string s = form_string(str);
            return isPalindrome(s);
        } 
        
        else {
            return false;
        }
    }
    

    return true;
}

int main() {
    string str;
    fflush(stdin);
    getline(cin, str);
    fflush(stdout);

    if(isPalindrome(str)) {
        cout << "Palindrome\n";
    }

    else {
        cout << "Not a Palindrome\n";
    }
}