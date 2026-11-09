struct DoublyListNode {
    DoublyListNode *prev;
    DoublyListNode *next;
    string url_;

    DoublyListNode() {
        url_ = "";
        prev = nullptr;
        next = nullptr;
    }

    DoublyListNode(string url) : url_(url) {
        prev = nullptr;
        next = nullptr;
    }
};

class BrowserHistory {
private:
    DoublyListNode *head;
    DoublyListNode *tail;
    DoublyListNode *curr;
public:
    BrowserHistory(string homepage) {
        head = new DoublyListNode();
        tail = new DoublyListNode();
        head->next = tail;
        tail->prev = head;

        DoublyListNode *node = new DoublyListNode(homepage);
        node->prev = head;
        node->next = tail;
        head->next = node;
        tail->prev = node;

        curr = node;
    }
    
    void visit(string url) {
        DoublyListNode *p = curr->next;
        while (p != tail) {
            DoublyListNode *tmp = p;
            p = tmp->next;
            delete tmp;
        }

        DoublyListNode *node = new DoublyListNode(url);
        node->prev = curr;
        node->next = tail;
        tail->prev = node;
        curr->next = node;

        curr = node;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (curr->prev == head) {
                break;
            }
            curr = curr->prev;
        }
        return curr->url_;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (curr->next == tail) break;
            curr = curr->next;
        }
        return curr->url_;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */