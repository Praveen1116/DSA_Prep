/* Given a queue q[] of even size. Your task is to rearrange the queue by interleaving its first half with the second half.

Interleaving is the process of mixing two sequences by alternating their elements while preserving their relative order.
In other words, Interleaving means place the first element from the first half and then first element from the 2nd half and again second element from the first half and then second element from the 2nd half and so on....

Examples:

Input: q[] = [2, 4, 3, 1]
Output: [2, 3, 4, 1]
Explanation: We place the first element of the first half 2 and after that 
place the first element of second half 3 and after that repeat
the same process one more time so the resulting queue will be [2, 3, 4, 1]
Input: q[] = [3, 5]
Output: [3, 5]
Explanation: We place the first element of the first half 3 and first element
of the second half 5 so the resulting queue is [3, 5]


Steps:
1 - Make a stack of half of the size of the queue
2 - Move the first half of the queue to the stack
3 - Take all the elements from the stack and enqueue into queue
4 - Move the first half of the queue to the rear of the queue
5 - Again push the first half of the queue to the stack
6 - Now interleave: means take one element from the stack push it into the queue and then take the front of the queue
    push it into the rear of the queue

*/

// Code:

class Solution {
public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        stack<int> st;

        // Step 1: Push first half into stack
        for(int i = 0; i < n / 2; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Push stack elements back to queue
        while(!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Step 3: Move first half to rear
        for(int i = 0; i < n / 2; i++) {
            q.push(q.front());
            q.pop();
        }

        // Step 4: Again push first half into stack
        for(int i = 0; i < n / 2; i++) {
            st.push(q.front());
            q.pop();
        }

        // Step 5: Interleave
        while(!st.empty()) {
            q.push(st.top());
            st.pop();

            q.push(q.front());
            q.pop();
        }
    }
};


/* Another approach is to take two queues */

// Code:

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size();
        
        queue<int> q1;
        queue<int> q2;
        
        for(int i=0; i<n/2; i++)
        {
            q1.push(q.front());
            q.pop();
        }
        
        while(!q.empty())
        {
            q2.push(q.front());
            q.pop();
        }
        
        while(!q1.empty() && !q2.empty())
        {
            q.push(q1.front());
            q1.pop();
            
            q.push(q2.front());
            q2.pop();
        }
    }
};