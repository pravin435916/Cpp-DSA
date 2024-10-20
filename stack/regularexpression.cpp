
// Input: expression = "!(&(f,t))"
// Output: true
// Explanation: 
// First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
// Then, evaluate !(f) --> NOT false --> true. We return true.
class Solution {
private:
    char solveOp(char op,vector<char>& values) {
        if (op == '!') 
            return values[0] == 't' ? 'f' : 't';

        if (op == '&') 
            return any_of(values.begin(), values.end(), [](char ch) { return ch == 'f'; }) ? 'f' : 't';

        if (op == '|') 
            return any_of(values.begin(), values.end(), [](char ch) { return ch == 't'; }) ? 't' : 'f';

        return 't';  // Unreachable
    }

public:
    bool parseBoolExpr(string& expression) {
        stack<char> stack;
        int n = expression.length();
        
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            if (c == ',') continue;

            if (c == ')') {
                vector<char> values;
                // Gather all values inside the parentheses
                while (stack.top() != '(') {
                    values.push_back(stack.top());
                    stack.pop();
                }
                stack.pop();  // Remove '('
                char op = stack.top();  // Get the operator
                stack.pop();  // Remove the operator
                stack.push(solveOp(op, values));  // Push the result back
            } else {
                stack.push(c);  // Push the character onto the stack
            }
        }
        return (stack.top() == 't') ? true : false;
    }
};