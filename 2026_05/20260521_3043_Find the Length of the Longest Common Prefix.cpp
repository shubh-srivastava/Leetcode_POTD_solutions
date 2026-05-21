// 21st May 2026

// 1st approach brute force using set 
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2){
        set<int>st;

        for(int i=0;i<arr1.size();i++){
            int num = arr1[i];
            while(num > 0){
                st.insert(num);
                num = num/10;
            }
        }                    

        int maxlen = 0;
        for(int i=0;i<arr2.size();i++){
            int num = arr2[i];
            while(num > 0){
                if(st.find(num) != st.end()){
                    maxlen = max(maxlen,(int)log10(num) + 1);
                    break;
                }
                else{
                    num = num/10;
                }
            }
        }    
        return maxlen;
    }
};

// 2nd approach using Trie data structure
struct TrieNode{
    char digit;
    TrieNode* children[10];
};

class Solution {
public:
    TrieNode* getNode(){
        TrieNode* node = new TrieNode();
        for(int i=0;i<10;i++){
            node->children[i] = nullptr;
        }
        return node;
    }
    void insert(int num,TrieNode* root){
        TrieNode* crawl = root;
        string numstr = to_string(num);

        for(char ch : numstr){
            int idx = ch - '0';
            if(!crawl->children[idx]){
                crawl->children[idx] = getNode();
            } 
            crawl = crawl->children[idx];
        }
    }
    int search(int num,TrieNode* root){
        TrieNode* crawl = root;
        string numstr = to_string(num);
        int len = 0;

        for(char ch : numstr){
            int idx = ch-'0';
            if(crawl->children[idx]){
                len++;
                crawl = crawl->children[idx];
            }
            else{
                break;
            }
        }
        return len;
    } 
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = getNode();

        for(int num : arr1){
            insert(num,root); 
        }
        int result = 0;
        for(int num : arr2){
            result = max(result,search(num,root));
        }
        return result;
    }
};