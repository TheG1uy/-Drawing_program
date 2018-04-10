#pragma once
template<class T>
class TStack{
private:
	int size,MaxSize;
	T *mas;
public :
	TStack(int _MaxSize=100){
		if (_MaxSize < 0) throw _MaxSize;
		size=0;
		MaxSize=_MaxSize;
		mas=new T[MaxSize];
	}
	~TStack(){delete [] mas;}
	TStack(const TStack &st){
	   size=st.size;
	   MaxSize=st.MaxSize;
	   mas=new T[MaxSize];
	   for(int i=0;i<size;i++)
		   mas[i]=st.mas[i];
	}
	bool isEmpty(){return size==0;}
	bool isFull(){return size==MaxSize;}
	void push(const T a){
		if (isFull()) throw a;
		 mas[size]=a;
		 size++;
	}
	T top(){ 
		if (isEmpty()) throw size;
		return mas[size-1];
	}
	void clear(){size=0;}
	T pop(){
		if (isEmpty()) throw size;
		size--;
		return mas[size];
	}

};