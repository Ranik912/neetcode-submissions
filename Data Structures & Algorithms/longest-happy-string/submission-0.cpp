class Solution {
public:
    typedef pair<int, char> T;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<T> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string res = "";
        while(!pq.empty()){
            auto currF = pq.top().first;
            char currC = pq.top().second;
            pq.pop();
            if(res.length() >= 2 && res[res.length() - 1] == currC && res[res.length() - 2] == currC){
                if(pq.empty()) break;
                auto sBestF = pq.top().first;
                char sBestC = pq.top().second;
                pq.pop();
                res.push_back(sBestC);
                sBestF--;
                if(sBestF > 0) pq.push({sBestF, sBestC});
            }
            else{
                res.push_back(currC);
                currF--;
            }
            if (currF > 0) pq.push({currF, currC});
        }
        return res;
    }
};