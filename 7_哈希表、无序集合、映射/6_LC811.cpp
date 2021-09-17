class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> counts;
        for (string& cpdomain : cpdomains) {
            int index = cpdomain.find(' ');
            int num = stoi(cpdomain.substr(0, index));
            string address = cpdomain.substr(index + 1);
            while (index > 0) {
                counts[address] += num;
                index = address.find('.');
                address = address.substr(index + 1);
            }
        }
        
        for (auto key_val : counts) {
            string temp = to_string(key_val.second) + " " + key_val.first;
            ans.push_back(temp);
        }
        return ans;
    }
};