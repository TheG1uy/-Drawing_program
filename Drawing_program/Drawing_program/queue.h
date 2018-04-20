
template <class T>

class TQueue {
	int first, last, maxsize, size;
	T* arr;

public:

	TQueue(int _maxsize = 200) {
		maxsize = _maxsize;
		arr = new T[maxsize];
		first = 1;
		last = 0;
		size = 0;
	}

	~TQueue() {
		delete[] arr;
	}

	TQueue(const TQueue& tq) {
		size = tq.size;
		maxsize = tq.maxsize;
		first = tq.first;
		last = tq.last;
		arr = new T[maxsize];
		for (int i = 0; i < maxsize; i++) {
			arr[i] = tq.arr[i];
		}
	}

	TQueue& operator=(const TQueue& tq) {
		if (this != &tq) {
			if(maxsize != tq.maxsize) {
				delete[] arr;
				maxsize = tq.maxsize;
				arr = new T[maxsize];
			}
				size = tq.size;
				for (int i = 0; i < maxsize; i++) {
					arr[i] = tq.arr[i];
				}
			}
		return *this;
		}

	bool isempty() {
		return (size == 0);
	}

	bool isfull() {
		return (size == maxsize);
	}

	void push(T elem) {
		if (isfull()) 
			throw -1;
		if (last == maxsize - 1)
			last = 0;
		else
			last++;
		size++;
		arr[last] = elem;
	}

	T pop() {
		if(isempty())
			throw -1;
		T tmp = arr[first];
		if (first == maxsize -1)
			first = 0;
		else 
			first++;
		size--;
		return tmp;
	}

	T getFirstElem() {
		return ring[first];
	}

	T getLastElem() {
		return ring[last];
	}

	int getFirst() {
		return first;
	}

	int getSize() {
		return size;
	}

	int getMaxsize() {
		return maxsize;
	}


	};

