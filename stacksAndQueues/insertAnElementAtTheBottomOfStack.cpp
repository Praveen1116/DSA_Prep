// The problem is asking for the insertion of an element at the bottom of the stack
/* But there is only one pointer in the stack i.e. top and it follows LIFO, 
    so insertionat bottom becomes difficult */

/* Approach: For this problem we should think that if it is a stack then we can 
    remove from the top only then why don't we store the top element in any variable
    and then remove the top element of the stack and as we have to do this again and again
    then why don't we use recursive approach. In the recursive approach we store the top 
    element in any variable and then pop/remove it, so on every call it stores the top
    and remove the top (example: 1, 2, 3, 4, 5 and insert = 6, here the top is 5 we 
    store it in temp and then remove it so now the input is 1, 2, 3, 4 and now we store 
    the 4 and remove it and so on when we reach the base case i.e. when the stack is empty
    then push the value that was intended to be inserted i.e. 6 so it comes at the bottom 
    and then push the temp into the stack so it becomes 6, 1 then recursive call push the 
    temp into the stack so it becomes 6, 1, 2 and so on.
    ) 
    Another appraoch is to take another stack push all the element from the first stack 
    to the second stack and when stack1 is empty push the value and then while stack2 is 
    not empty push all the elements from the stack2 to stack1
    */

Question link: https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1

// Code:

class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        if(st.empty())
        {
             st.push(x);
             return st;
        }
        
        int temp = st.top();
        st.pop();
        
        st = insertAtBottom(st, x);
        st.push(temp);
        
        return st;
    }
};