#include <iostream>
#include <string>
using namespace std;

template <typename E>
class MyArrayList {
public:
     MyArrayList(int capacity) {// 容量小于10一律扩充为10
         mSize = 0;
        initCapacity = (capacity < DEFAULT_CAPACITY) ? DEFAULT_CAPACITY : capacity;
        data = new E[initCapacity];
    }

     MyArrayList() {

    }

public:
    /**
     * 1、获取数组中的元素数量
     * @return
     */
     int size() {
        return mSize;
    }

    /**
     * 2、判断数组是否为空
     * @return
     */
     bool isEmpty() {
         return mSize == 0;
     }

    /**
     * 3、判断数组是否包含某个元素
     * @param element
     * @return
     */
     bool contains(E element){
        // 调用第 9 点的函数，判断该元素的索引是否为 -1
        // 如果等于 -1 ，表示数组不包含该元素
        // 如果不等于 -1 ，表示有正确的索引，数组包含该元素
        return indexOf(element) != ELEMENT_NOT_FOUND;
    }

    /**
     * 4、添加元素到数组最末端
     */
     void add(E element) {
        // 借助第 5 点来实现
        add(mSize, element);
    }

    /**
     * 5、添加元素到索引 index 位置（增）
     * @param index
     * @param element
     */
     void add(int index, E element) {
        // 检查下标越界
        rangeCheckForAdd(index);

        // 确保容量够大
        ensureCapacity(mSize + 1);
        //     ↓
        // 0 1 2 3 4 5 6 7 8 9 (索引index)
        // 1 2 3 4 5 6 x x x x (原数组)
        // 在 index = 2处，插入 9 ，元素全部后移
        // 1 2 9 3 4 5 6 x x x (add 后数组)
        // 【从后往前】, 将每个元素往后移一位, 然后再赋值
        for (int i = mSize - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }

        data[index] = element;

        mSize++;
    }

    /**
     * 6、删除索引 index 位置的元素（删）
     * @param index
     * @return 删除的元素
     */
     E remove(int index) {
        rangeCheck(index);
        E ret = data[index];
        for (int i = index + 1; i < mSize; i++) {
            data[i - 1] = data[i];
        }
        mSize--;
        // 删除元素后, 将最后一位设置为 null
        data[size] = NULL;
        return ret;
    }

    /**
     * 7、获取索引 index 位置的元素（查）
     * @param index
     * @return 原来的元素ֵ
     */
     E get(int index) {
        rangeCheck(index);
        return data[index];
    }

    /**
     * 8、设置索引 index 位置的元素（改）
     * @param index
     * @param element
     * @return 原来的元素ֵ
     */
     E set(int index, E element) {
        rangeCheck(index);
        E ret = data[index];
        data[index] = element;
        return ret;
    }

     /**
   * 9、查看某个元素所在的位置
   * @param element
   * @return
   */
     int indexOf(E element) {
         for (int i = 0; i < mSize; i++) {
             if (data[i] == element) return i;
         }
         return ELEMENT_NOT_FOUND;
     }

    /**
     * 10、删除所有元素
     */
    void clear() {
        // 使用泛型数组后要注意内存管理(将元素置null)
        for (int i = 0; i < mSize; i++) {
            data[i] = NULL;
        }
        mSize = 0;
    }

    string toString() {
        string str = "size=" + to_string(mSize) + ", [";
        for (int i = 0; i < mSize; i++) {
            if (0 != i) str += ", ";
            str += std::to_string(data[i]);
        }
        str += "]";
        return str;
    }

private:
     /*
    * 扩容操作
    */
     void ensureCapacity(int capacity) {
         if (initCapacity >= capacity) return;
         // 新容量为旧容量的 2 倍
         int newCapacity = initCapacity * 2; // 1.5
         E* newElements = new E[newCapacity];
         for (int i = 0; i < mSize; i++) {
             newElements[i] = data[i];
         }
         data = newElements;
         initCapacity = newCapacity;
     }

     // 下标越界抛出的异常
     void outOfBounds(int index) {
         if (index < 0 || index >= mSize) {
             throw out_of_range("Index out of bounds");
         }
     }

     // 检查下标越界(不可访问或删除size位置)
     void rangeCheck(int index) {
         if (index < 0 || index >= mSize) {
             outOfBounds(index);
         }
     }
     // 检查add()的下标越界(可以在size位置添加元素)
     void rangeCheckForAdd(int index) {
         if (index < 0 || index > mSize) {
             outOfBounds(index);
         }
     }

private:
    // 元素的数量
    int mSize;
    int initCapacity;

    static const int ELEMENT_NOT_FOUND = -1;

    // 所有的元素
    E* data = NULL;

    // 初始容量
    static const int DEFAULT_CAPACITY = 10;
};

int main() {
    MyArrayList<int> list(10); // 创建一个初始容量为 10 的整型数组
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(8);
    list.add(9);
    list.add(10);
    cout << list.toString() << endl;
	return 0;
}