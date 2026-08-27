class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto t : tokens){
            if(t == "+"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first + second);
            }
            else if(t == "-"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first - second);
            }
            else if(t == "*"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first * second);
            }
            else if(t == "/"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(first / second);
            }
            else{
                int x = stoi(t);
                st.push(x);
            }
        }
        return st.top();
    }
};
