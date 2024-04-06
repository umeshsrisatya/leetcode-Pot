//#Minimum Remove to Make Valid Parentheses
//#solution
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //Stack creation 
        stack<int> invalidOpen; //for storing indexes
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                invalidOpen.push(i);
                //stores only invalid open parentheses indexes
            }
            else if(s[i] == ')'){
                if(!invalidOpen.empty()){
                    // if stack has open existing parenthesis index
                    invalidOpen.pop(); //delete open '(' index because it has valid closing ')'
                }
                else{
                    // string consist of invalid closing ')' then we change original string equivalent index to '*'
                    s[i]='*';
                }
            }
        }
        // this loop to change inavlid open ')' indexes to '*' in original string s
        while(!invalidOpen.empty()){
            s[invalidOpen.top()]='*';
            invalidOpen.pop();
        }

        string result="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
