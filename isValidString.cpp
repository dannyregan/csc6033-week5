#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

bool isInSymbols(char c) {
  /*
    Helps to determine if a character part of the language

    Input:
    - char c: The character being analyzed

    Output:
    - bool: True if the character is in the alphabet, otherwise false
  */
  vector<char> symbols = {'(', ')', '[', ']'};

  for (int i = 0; i < symbols.size(); i++) {
    if (c == symbols[i]) {
      return true;
    }
  }

  return false;
}

bool isInLanguage(char c) {
  /*
    Determines if a character part of the language

    Input:
    - char c: The character being analyzed

    Output:
    - bool: True if the character is in the alphabet, otherwise false
  */
  return isalpha(c) || isspace(c) || isInSymbols(c);
}

bool isValid(string input) {
  /*
    Determines if the input is valid according to the CFG

    Input:
    - string input: The input being analyzed

    Output:
    - bool: True if the input is valid, otherwise false
  */
  int length = input.length();
  stack<char> read;

  for (int i = 0; i < length; i++) {
    char c = input[i];

    if (isInLanguage(c)) {
      switch(c) {
        case '[':
          read.push(c);
          break;

        case ']':
          if (read.top() == '[') {
            read.pop();
          }
          else return false;
          break;

        case '(':
          read.push(c);
          break;

        case ')':
          if (read.top() == '(') {
            read.pop();
          }
          else return false;
          break;
      }
    }
    else return false;
  }
  return read.empty();
}

int main() {
  string input;
  cout << "Input a string. You can include letters, spaces, '()', and '[]': ";
  getline(cin, input);

  isValid(input) ? cout << "String is ACCEPTED" << endl : cout << "String is DENIED" << endl;
  
  return 0;
}