#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

bool isInSymbols(char c) {
  vector<char> symbols = {'(', ')', '[', ']'};

  for (int i = 0; i < symbols.size(); i++) {
    if (c == symbols[i]) {
      return true;
    }
  }

  return false;
}

bool isInLanguage(char c) {
  return isalpha(c) || isspace(c) || isInSymbols(c);
}

bool isValid(string input) {
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
  cout << "Input a string. You can include '()' and '[]': ";
  getline(cin, input);
  isValid(input) ? cout << "String is ACCEPTED" << endl : cout << "String is DENIED" << endl;
  return 0;
}