/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

      if(node==NULL)
      return NULL;
     
     unordered_map<Node*,Node*> oldToNew;
     queue<Node*> q;
     q.push(node);
     oldToNew[node]=new Node(node->val);

     while(!q.empty()){
      Node* front = q.front();
      q.pop();

      for(auto &ngbr:front->neighbors){
        if(oldToNew.find(ngbr) == oldToNew.end()){
          oldToNew[ngbr]=new Node(ngbr->val);
          q.push(ngbr);
        }
        oldToNew[front]->neighbors.push_back(oldToNew[ngbr]);
      }


     }

     return oldToNew[node];
        
    }

};
