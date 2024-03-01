#include <iostream>
#include <stack>
#include <string>

using namespace std; // Added to use the std namespace

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert postfix expression to infix expression
string postfixToInfix(const string& postfix) {
    stack<string> s;

    for (char c : postfix) {
        if (!isOperator(c)) {
            // If the character is an operand, push it onto the stack as a string
            s.push(string(1, c));
        } else {
            // If the character is an operator, pop two operands from the stack
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();

            // Combine the operands and operator to form an infix expression
            string infix = "(" + operand1 + " " + c + " " + operand2 + ")";

            // Push the resulting infix expression back onto the stack
            s.push(infix);
        }
    }

    // The final result will be at the top of the stack
    return s.top();
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    string infixExpression = postfixToInfix(postfixExpression);

    cout << "Infix expression: " << infixExpression << endl;

    return 0;
}
