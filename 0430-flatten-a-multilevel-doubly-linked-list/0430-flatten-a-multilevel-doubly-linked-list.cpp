class Solution {
public:

    Node* solve(Node* head) {
        if(head == NULL)
            return NULL;

        Node* it = head;
        Node* tail = it;

        while(it != NULL) {

            if(it->child != NULL) {

                Node* childtail = solve(it->child);

                Node* temp = it->next;

                // connect current node to child
                it->next = it->child;
                it->child->prev = it;

                // connect child list to next node
                childtail->next = temp;

                if(temp != NULL)
                    temp->prev = childtail;

                // remove child pointer
                it->child = NULL;
            }

            tail = it;
            it = it->next;
        }

        return tail;
    }

    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};