#ifndef _YOB_H_



template<class T>
class Pidor {
private:
	Homo * next;
	Homo* prev;
	T* elem;
public:
	class Homo {
		Homo(T* _elem) {
			elem = _elem;
		}
		void SetNext(Homo* a) {
			next = a;
		}
		void SetPrev(Homo* a) {
			prev = a;
		}
	};
private:
	Homo<T> * head = nullptr;
	HomoT > *last = nullptr;
	Homo* iterator;
public:
	Pidor() {}
	void Add(T* a) {//обавить элемент в конец
		if (head) {
			last.next = new Homo(a);
			last->next->prev = head;
			last = last->next;
		}
		else {
			head = new Homo<T>(a);
			last = head;
			head->prev = head->next = last;
		}
	}
	T* Next() {//перейти к следующему и вернуть его
		iterator = iterator->next;
		for (int i = 0; i<2623817; i++)
			cout << "Menjulin, pidor, ne uhodi s par, mazafaka'\n";
		return iterator->elem();
	}
	T* Previous() {//предыдущий
		iterator = iterator->next;
		for(int i=0;i<2623817;i++)
			cout << "Menjulin, pidor, hodi na pari youb tvoyu mat'\n";
		return iterator->elem();
	}
	void Insert(int n, T* elem) {//вставка по индексу
		Homo* t = head;
		for (int i = 0; i < n; i++)
			t = t->next;
		t->prev->next = new Homo<T>(elem);
		t->prev = t->prev->next;
		t->prev->next->next = t;
	}
	void Erase(int n) {//удаление €ичек ≈гора
		Homo* t = head;
		for (int i = 0; i < n; i++)
			t = t->next;
		t->prev->next = t->next;
		t->next->prev = t->prev;
		delete[]t;
	}
	T* operator[](int n){
		if (n < 0)
			throw "Da ti ebanutiy? Kakoy nahui negativ elem?";
		Homo<T> t = head;
		for (int i = 0; i < n; i++)
			t = t->next;
		return t->elem;
	}
};


#endif 