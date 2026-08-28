#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache
{
public:

    LRUCache(int capacity)
    {
        cp = capacity;
        head = NULL;
        tail = NULL;
    }

    void set(int key, int value)
    {
        // Key already exists
        if(mp.find(key) != mp.end())
        {
            Node* node = mp[key];

            node->value = value;

            // Already at head
            if(node != head)
            {
                // Remove node from current position
                if(node->prev)
                    node->prev->next = node->next;

                if(node->next)
                    node->next->prev = node->prev;

                if(node == tail)
                    tail = node->prev;

                // Put node at head
                node->prev = NULL;
                node->next = head;

                head->prev = node;
                head = node;
            }

            return;
        }

        // New key
        Node* node = new Node(key, value);

        // Empty cache
        if(head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
        }

        mp[key] = node;

        // Cache is too large
        if(mp.size() > cp)
        {
            Node* old = tail;

            tail = tail->prev;

            if(tail)
                tail->next = NULL;

            mp.erase(old->key);

            delete old;
        }
    }

    int get(int key)
    {
        // Not found
        if(mp.find(key) == mp.end())
        {
            return -1;
        }

        Node* node = mp[key];

        // Move accessed node to head
        if(node != head)
        {
            if(node->prev)
                node->prev->next = node->next;

            if(node->next)
                node->next->prev = node->prev;

            if(node == tail)
                tail = node->prev;

            node->prev = NULL;
            node->next = head;

            head->prev = node;
            head = node;
        }

        return node->value;
    }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
