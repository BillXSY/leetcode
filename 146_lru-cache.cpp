//
// Created by 71401 on 2021/7/20.
//

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#include <vector>
#include <unordered_map>

struct DLinkedNode {
    int key, value;
    DLinkedNode *prev, *next;

    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}

    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int curr_size;
    int capacity;

protected:
    void addToHead(DLinkedNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }

    void checkSize() {
        if (this->curr_size > this->capacity) {
            DLinkedNode *victim = tail->prev;
            cache.erase(victim->key);
            removeNode(victim);
            delete victim;
            this->curr_size--;
        }
    }

public:
    LRUCache(int capacity) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
        this->curr_size = 0;
        this->capacity = capacity;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        // if already exists in the cache
        if (cache.count(key)) {
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
            // not exist
        else {
            DLinkedNode *newNode = new DLinkedNode(key, value);
            cache[key] = newNode;
            addToHead(newNode);
            curr_size++;
            checkSize();
        }
    }
};