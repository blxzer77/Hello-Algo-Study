#include "C:\Users\shuweige\OneDrive\hello-algo-main\hello-algo-main\codes\cpp\utils\common.hpp"

/* 键值对 */
struct Pair  {
    public:
        int key;
        string val;
        Pair(int key, string val) {
            this->key = key;
            this->val = val;
        }
};

/* 基于数组简易实现的哈希表 */
class ArrayHashMap {
    private:
        vector<Pair *> buckets;

    /* 构造方法 */
    public:
        ArrayHashMap() {
            // 初始化数组， 包含 100 个桶
            buckets = vector<Pair *>(100);
        }

        ~ArrayHashMap() {
            // 释放内存
            for(const auto &bucket : buckets) {
                delete bucket;
            }
            buckets.clear();
        }

        /* 哈希函数 */
        int hashFunc(int key) {
            int index = key % 100;
            return index;
        }

        /* 查询操作 */
        string get(int key) {
            int index = hashFunc(key);
            Pair *pair = buckets[index];
            if (pair == nullptr) 
                throw out_of_range("该key没有对应的值");
            return pair->val;
        }

        /* 添加操作 */
        void put(int key, string val) {
            Pair *pair = new Pair(key, val);
            int index = hashFunc(key);
            buckets[index] = pair;
        }

        /* 删除操作 */
        void remove(int key) {
            int index = hashFunc(key);
            // 释放内存并置于 nullptr
            delete buckets[index];
            buckets[index] = nullptr;
        }

        /* 获取所有键值对 */
        vector<Pair *> pairSet() {
            vector<Pair *> pairSet;
            for (Pair *pair : buckets) {
                if (pair != nullptr) {
                    pairSet.push_back(pair);
                }
            }
            return pairSet;
        }

        /* 获取所有键 */
        vector<int> keySet() {
            vector<int> keySet;
            for (Pair *pair : buckets) {
                if (pair != nullptr) {
                    keySet.push_back(pair->key);
                }
            }
            return keySet;
        }

        /* 获取所有值 */
        vector<string> valueSet() {
            vector<string> valueSet;
            for (Pair *pair : buckets) {
                if (pair != nullptr) {
                    valueSet.push_back(pair->val);
                }
            }
            return valueSet;
        }

        /* 打印哈希表 */
        void print() {
            for (Pair *kv : pairSet()) {
                cout << kv->key << " -> " << kv->val << endl;
            }
        }
};

/* Driver Code */
int main()
{
        /* 初始化哈希表 */
        ArrayHashMap map = ArrayHashMap();

        /* 添加操作 */
        // 在哈希表中添加键值对 (key, value)
        map.put(12836, "小哈");
        map.put(15937, "小啰");
        map.put(16750, "小算");
        map.put(13276, "小法");
        map.put(10583, "小鸭");
        cout << "\n添加完成后，哈希表为\nKey -> Value" << endl;
        map.print();

        /* 查询操作 */
        // 向哈希表输入键 key ，得到值 value
        string name = map.get(15937);
        cout << "\n输入学号 15937 ，查询到姓名 " << name << endl;

        /* 删除操作 */
        // 在哈希表中删除键值对 (key, value)
        map.remove(10583);
        cout << "\n删除 10583 后，哈希表为\nKey -> Value" << endl;
        map.print();

        /* 遍历哈希表 */
        cout << "\n遍历键值对 Key->Value" << endl;
        for (auto kv : map.pairSet())
        {
            cout << kv->key << " -> " << kv->val << endl;
        }

        cout << "\n单独遍历键 Key" << endl;
        for (auto key : map.keySet())
        {
            cout << key << endl;
        }

        cout << "\n单独遍历值 Value" << endl;
        for (auto val : map.valueSet())
        {
            cout << val << endl;
        }

        return 0;
}
