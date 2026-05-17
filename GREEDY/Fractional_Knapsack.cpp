class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        
        if(n == 0 || capacity == 0)
        return 0.0;
        
        // build an array of ratio - val/wt
        vector<pair<double<pair<int, int>>>items;
        items.reserve(n);
        
        
        for(int i = 0; i < n ; i++)
        {
            items.push_back({double(val[i]/wt[i]), {wt[i], val[i]}});
        }
        
        // sort in descending order based on val/wt
        sort(items.begin(), items.end(),[](auto &a , auto &b){
            return a.first > b.first
        });
        
        double totalvalue = 0.0;
        
        
        for(auto &item : items)
        {
            if(capacity == 0)
            break;
            
            int weight = item.second.first;
            int value = item.second.second;
            double ratio = item.first; // weight / value
            
            if(weight <= capacity)
            {
                // take whole item
                totalvalue += value;
                capacity -= weight;
                
            }
            else{
                // take a fraction 
                //weight > capacity
                totalvalue += ratio * capacity;
                capacity = 0;
            }
        }
        
        return std::round(totalvalue * 1e6)/1e6;
        
;    }
}

// Another Way of Writing : 
// TC = O(N Log N) | SC = O(N) 

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    
    vector<pair<int,int>> a(n);
    
    // Value / Weight = Profit Per Unit Weight
    // Choosing by per unit wt gives us max profit - Greedy 
    
    for(int i = 0; i < n; i++){
        a[i] = {val[i], wt[i]};    
    }
    
    auto cmp = [&](auto p1, auto p2){
        return (1.0 * p1.first)/p1.second > (1.0 * p2.first)/p2.second;
    };
    
    sort(a.begin(), a.end(), cmp);
    
    double ans = 0.0;
    
    for(int i = 0; i < n; i++){
        int value = a[i].first;
        int weight = a[i].second;
        double profitPerUnitWt = (1.0 * value)/weight;
        
        if(weight <= capacity){
            ans += value; // profit = (whole value) can pick the whole item 
            capacity -= weight; // decrease its capcity
        }
        else{
            ans += profitPerUnitWt * capacity; // Can pick fraction of item
            break; // Cannot choose anthing further as capcity would become 0 implicity
        }
    }
    
    return ans;
    }
};
