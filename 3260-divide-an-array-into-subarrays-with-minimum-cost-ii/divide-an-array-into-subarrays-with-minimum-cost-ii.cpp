class Solution {
    typedef pair<int, int> pli;
    class Comparator{
      public:
        bool operator()(const pli& a, const pli& b){
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        const int size = nums.size();
        long long result = LLONG_MAX; 
        long long curSum = nums[0]; 
        int i = 1, j = 1; 
        --k;
        set <pli> small; 
        priority_queue<pli, vector<pli>, Comparator> pq; 

        while(i <= size - k){
            bool curDelete = false; 

            while(small.size() < k || j <= min(i + dist, size - 1)){
                int smallSize = small.size();

                

                pli cur = {INT_MAX, -1};
                
                if (j < size) cur = {nums[j], j};
                
                while (!pq.empty() && (j >= size || nums[j] >= pq.top().first)){
                    pli top = pq.top(); pq.pop();
                    if (top.second < i) continue;
                    pq.push(cur); cur = top; break;
                }

                
                pli largest = {INT_MAX , -1};
                bool needsToChange = false;
                if (smallSize == k){
                    largest = *prev(small.end());
                    if (largest.first >= cur.first) needsToChange = true;
                }

                
                if (smallSize < k) {small.insert(cur); curSum+=cur.first;}
                else if(smallSize == k && needsToChange){
                    small.erase(largest); small.insert(cur);
                    curSum -= (largest.first - cur.first);
                    if (largest.second != i) pq.push(largest);
                    else curDelete = true;
                } 
                else pq.push(cur);

                ++j;
            } 
            result = min(result, curSum);
            if (!curDelete){
                bool foundInSmall = small.erase({nums[i], i}); 
                if (foundInSmall) curSum -= nums[i];
            } ++i;
        } return result;
    }
};