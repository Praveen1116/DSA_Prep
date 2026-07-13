// We have to check how many pairs of valid parantheses 
// valid parantheses means if an opening parantheses is there then closing parantheses w.r.t opening should be there

/* Appraoch: We can implement a stack and push opening bracket into it and whenever 
    a closing bracket is there we check it to corresponding top of the stack if closing 
    bracket is there and st.top() has opening bracket w.r.t closing then remove it from top
    at last if the stack is empty then all are valid parantheses but if stack is not empty
    then it means that something is left and then it is not valid
*/

// early return on when size of the input string is not even then it returns false
/* edge case: if nothing is pushed into the stack means no opening brackets are there then
    immediately return false;
*/

Question link: https://leetcode.com/problems/valid-parentheses/

// Code:

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        stack<char> st;

        for(char c : s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if(st.empty()) return false;

                char ch = st.top();

                if((ch == '(' && c == ')') ||
                    (ch == '{' && c == '}') ||
                    (ch == '[' && c == ']'))
                {
                    st.pop();
                }
                else return false;
            }
        }
        return st.empty();
    }
};