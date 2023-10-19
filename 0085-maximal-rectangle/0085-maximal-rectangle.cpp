class Solution {
public:
 vector<int> prevSmallerIndex(vector<int> &arr) {
            stack<int> st;
            vector<int> ans(arr.size());
            st.push(-1);
            for(int i=0;i<arr.size();i++){
                int curr = arr[i];
                while((st.top()==-1?-1:arr[st.top()])>=curr){
                    st.pop();
                }
                st.top()==-1?ans[i] =-1:ans[i] = st.top();
                st.push(i);
            }
            return ans;
        }
        vector<int> nextSmallerIndex(vector<int> &arr) {
            stack<int> st;
            vector<int> ans(arr.size());
            st.push(-1);
            for(int i=arr.size()-1;i>=0;i--){
                int curr = arr[i];
                while((st.top()==-1?-1:arr[st.top()])>=curr){
                    st.pop();
                }
                st.top()==-1?ans[i] = arr.size():ans[i] = st.top();
                st.push(i);
            }
            return ans;
        }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> anseleindpre=prevSmallerIndex(heights);
        vector<int> anseleindnext=nextSmallerIndex(heights);
        int maxArea=0;
        for (int i=0;i<heights.size();i++){
            int area = heights[i]*(anseleindnext[i]-anseleindpre[i]-1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix){
        vector<vector<int>> v;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            vector<int>t;
            for(int j=0;j<m;j++){
                t.push_back(matrix[i][j] - '0');
            }
            v.push_back(t);
        }
        int area = largestRectangleArea(v[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]){
                    v[i][j] += v[i-1][j];
                }
                else{
                    v[i][j] = 0;
                }
            }
            area = max(area,largestRectangleArea(v[i]));
        }
        return area;
    }
};