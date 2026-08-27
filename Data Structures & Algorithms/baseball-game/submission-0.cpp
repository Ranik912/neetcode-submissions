class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans = 0;
        stack<int> st;
        for(auto op : operations) {
            if(op == "C") st.pop();
            else if(op == "D"){
                int x = st.top();
                st.push(2 * x);
            }
            else if(op == "+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);
                st.push(first + second);
            }
            else st.push(stoi(op));
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};


















