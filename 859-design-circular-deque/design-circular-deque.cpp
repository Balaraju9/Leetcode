class MyCircularDeque {
public:
    vector<int> v1;
    int k;
    MyCircularDeque(int k1) { k = k1; }

    bool insertFront(int value) {
        if (v1.size() < k) {
            v1.insert(v1.begin(), value);

            return true;
        }
        return false;
    }

    bool insertLast(int value) {
        if (v1.size() < k) {
            v1.push_back(value);
            return true;
        }
        return false;
    }

    bool deleteFront() {
        if (v1.size() >= 1) {
            v1.erase(v1.begin());
            return true;
        } else {
            return false;
        }
    }

    bool deleteLast() {
        if (v1.size() >= 1) {
           v1.pop_back();
            return true;
        } else {
            return false;
        }
    }

    int getFront() {
        if (v1.size() >= 1) {
            return v1[0];
        } else {
            return -1;
        }
    }

    int getRear() {
        if (v1.size() >= 1) {
           
            return v1[v1.size() - 1];
        } else {
            return -1;
        }
    }

    bool isEmpty() {
        if (v1.size() == 0) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (k == v1.size()) {
           
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */