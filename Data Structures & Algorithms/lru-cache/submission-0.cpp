class Node{
public:
  int key;
  int value;
  Node* prev;
  Node* next;

  Node(int k,int v){
    key=k;
    value=v;
    prev=NULL;
    next=NULL;
  }
};

class LRUCache {

private:
    unordered_map<int,Node*> m;
    int cap;
    Node* left;
    Node* right;

    void insertNode(Node* node){
      Node* prevNode = right->prev;
      prevNode->next = node;
      node->prev = prevNode;
      node->next = right;
      right->prev = node;
    }

    void deleteNode(Node* node){
      Node* prevNode = node->prev;
      Node* nextNode = node->next;
      prevNode->next=nextNode;
      nextNode->prev=prevNode;
    }

public:

    LRUCache(int capacity) {
        cap=capacity;
        left=new Node(0,0);
        right=new Node(0,0);
        left->next=right;
        right->prev=left;
    }
    
    int get(int key) {
      if(m.find(key)!=m.end()){
        Node* node = m[key];
        deleteNode(node);
        insertNode(node);
        return node->value;
      }

      return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
          Node* node = m[key];
          deleteNode(node);
        }

        Node* element = new Node(key,value);
        insertNode(element);
        m[key]=element;

        if(m.size()>cap){
          Node* node = left->next;
          deleteNode(node);
          m.erase(node->key);
        }

        

      
    
    }
};
