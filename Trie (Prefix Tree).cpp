struct Node{
    bool isEnd;
    Node* next[26];
    Node(){
        isEnd=false;
        for(int i=0;i<26;++i) next[i]=nullptr;
    }
};
class Trie {
public:
    Node* head;
    Trie() {
        head=new Node();
    }
    
    void insert(string word) {
        Node* temp=head;
        for(char x:word){
            if(!temp->next[x-'a']) temp->next[x-'a']=new Node();
            temp=temp->next[x-'a'];
        }
        temp->isEnd=true;
    }
    
    bool search(string word) {
        Node* temp=head;
        for(char x:word){
            if(!temp->next[x-'a']) return false;
            temp=temp->next[x-'a'];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string word) {
        Node* temp=head;
        for(char x:word){
            if(!temp->next[x-'a']) return false;
            temp=temp->next[x-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
