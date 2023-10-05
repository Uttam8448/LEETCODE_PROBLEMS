/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //unordered_map<Node* ,Node*>mp;  //old node--->new node mapping
        if(!head) return 0;

        Node* it = head;
        while(it){
            Node*cloneNode=new Node(it->val);
            cloneNode->next=it->next;
            it->next=cloneNode;
            it=it->next->next;
        }
        
        //Step2: Assign random ll of "A" with the helper
        it=head;
        while(it){
            Node*clonedNode=it->next;
            if(!it->random){
                clonedNode->random=NULL;
            }
            else{
                clonedNode->random=it->random->next;
            }
            it=it->next->next;
        }
        it=head;
        Node* cloneHead = it->next;
        while(it){
            Node*clonedNode=it->next;
            it->next=it->next->next;
            if(clonedNode->next){
                clonedNode->next=clonedNode->next->next;
            }
            it=it->next;
        }
        return cloneHead;

    }
};