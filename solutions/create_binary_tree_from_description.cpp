/*https://leetcode.com/problems/create-binary-tree-from-descriptions/*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , pair<TreeNode *, bool> > treeMap;
        for(auto & i : descriptions){
            if(treeMap.find(i[0])!=treeMap.end()){
                TreeNode * node ;
                if(treeMap.find(i[1])!=treeMap.end()){
                node = treeMap[i[1]].first;
            }
            else{
                node = new TreeNode(i[1]);
            }
                TreeNode * parent = treeMap[i[0]].first;
                if(i[2]){
                    parent->left = node;
                }
                else{
                    parent->right = node;
                }
                treeMap[i[0]].first=parent;
                treeMap[i[1]] = {node,false};
                continue;
            }
            TreeNode * parent =new TreeNode(i[0]);
            TreeNode * node ;
            if(treeMap.find(i[1])!=treeMap.end()){
                node = treeMap[i[1]].first;
            }
            else{
                node = new TreeNode(i[1]);
            }
            if(i[2]){
                    parent->left = node;
                }
                else{
                    parent->right = node;
                }
            treeMap[i[1]] = {node,false};
            treeMap[i[0]] = {parent,true};
            
            
        }
        for(auto & i : treeMap){
            if(i.second.second){return i.second.first;}
        }
        return nullptr;
    }
};
