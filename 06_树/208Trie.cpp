#include <string>
#include <unordered_map>
#include "memory.h"
using namespace std;

/*
208. 实现 Trie (前缀树)
https://leetcode-cn.com/problems/implement-trie-prefix-tree/

Trie内部实现有两种：字符集数组法，字符集映射法
*/


/*
字符集数组法：每个结点保存一个长度固定的数组（26个字母长度）
末尾计数>0，即路径上的是单词；末尾为空/末尾计数=0，说明路径是前缀
insert,search,startsWith都是先查找，只是最后要的东西不一样
所以可以写一个公用的函数，根据开关，控制流程，避免代码的ctrl+c/ctrl+v
*/

struct Node {
    int count;
    Node* child[26];
    Node() {
        count = 0;
        memset(child, 0, sizeof(child));
    }
};

class Trie {
   public:
    Trie() {
        // 类似于保护结点
        this->root = new Node();
    }

    void insert(string word) {
        find(word, true, false);
    }

    bool search(string word) {
        return find(word, false, false);
    }

    bool startsWith(string prefix) {
        return find(prefix, false, true);
    }

   private:
    Node* root;

    bool find(const string& word, bool isInsert, bool isPrefix) {
        Node* curr = this->root;
        for (char ch : word) {
            // Trie树找不下去了
            if (curr->child[ch - 'a'] == nullptr) {
                if (isInsert) {
                    Node* node = new Node();
                    curr->child[ch - 'a'] = node;
                } else {
                    return false;
                }
            }
            curr = curr->child[ch - 'a'];
        }
        // word在Trie树中走完了
        if (isInsert) {
            curr->count++;
            return true;
        } else if (isPrefix) {
            return true;
        } else {
            return curr->count > 0;
        }
    }
};


/*
字符集映射法：每个结点上的字符集数组改为一个映射
*/

struct Node {
    int count;
    unordered_map<char, Node*> child;
    Node() : count(0) {}
};

class Trie {
   public:
    Trie() {
        // 类似于保护结点
        this->root = new Node();
    }

    void insert(string word) {
        find(word, true, false);
    }

    bool search(string word) {
        return find(word, false, false);
    }

    bool startsWith(string prefix) {
        return find(prefix, false, true);
    }

   private:
    Node* root;

    bool find(const string& word, bool isInsert, bool isPrefix) {
        Node* curr = this->root;
        for (char ch : word) {
            // Trie树找不下去了
            if (curr->child.find(ch) == curr->child.end()) {
                if (isInsert) {
                    Node* node = new Node();
                    curr->child[ch] = node;
                } else {
                    return false;
                }
            }
            curr = curr->child[ch];
        }
        // word在Trie树中走完了
        if (isInsert) {
            curr->count++;
            return true;
        } else if (isPrefix) {
            return true;
        } else {
            return curr->count > 0;
        }
    }
};