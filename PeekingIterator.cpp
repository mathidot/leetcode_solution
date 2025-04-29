#include "util.h"

class Iterator {
	struct Data;
    Data* data;
 public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);

	// Returns the next element in the iteration.
	int next();

	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
	// 标记是否还有下一个元素
	bool hasNextFlag;
	// 缓存下一个元素
	int nextElem;
	// 迭代器
	Iterator* iter;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		iter = new Iterator(nums);
		// 把迭代器的下一个元素提前拿出来并缓存起来
		int next = iter->next();
		nextElem = next;
		hasNextFlag = true;
	}
	
	int peek() {
		return nextElem;
	}
	
	int next() {
		int res = nextElem;
		// 更新 nextElem
		if (iter->hasNext()) {
			nextElem = iter->next();
		} else {
			hasNextFlag = false;
		}
		return res;
	}
	
	bool hasNext() const {
		return hasNextFlag;
	}
};