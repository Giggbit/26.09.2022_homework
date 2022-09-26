#pragma once
#include <iostream>
using namespace std;

class Queue {
	int* Wait; // Очередь
	int MaxQueueLength; // Максимальный размер очереди
	int QueueLength; // Текущий размер очереди

public:
	Queue(int m);
	~Queue();

	void Add(int c); // Добавление элемента
	void Extract(); // Извлечение элемента
	void Clear(); // Очистка очереди
	bool IsEmpty(); // Проверка существования элементов в очереди
	bool IsFull(); // Проверка на переполнение очереди
	int GetCount(); // Количество элементов в очереди
	void Show();
	//void CheckChance();
	void FirstNum(int& obj) {
		const int n = Wait[1];
		obj = n;
	}
};

void Queue::Show() {
	cout << "\n --------------------\n";
	for (int i = 0; i < QueueLength; i++) {
		cout << "  " << Wait[i] << "\t";
	}
	cout << "\n --------------------\n";
}

Queue::~Queue() {
	delete[]Wait;
}

Queue::Queue(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}

void Queue::Clear()
{
	// Эффективная "очистка" очереди 
	QueueLength = 0;
}

bool Queue::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}

bool Queue::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

int Queue::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;
}

void Queue::Add(int c)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if (!IsFull())
		Wait[QueueLength++] = c;
}

//void Queue::Extract()
//{
//	// Если в очереди есть элементы, то возвращаем тот, 
//	// который вошел первым и сдвигаем очередь	
//	if (!IsEmpty()) {
//		int min = 0, max = 2;
//		int random = rand() % (max - min + 1) + min;
//
//
//		//запомнить
//		int temp = Wait[0];
//
//		//сдвинуть все элементы
//		for (int i = 2; i < QueueLength; i++) {
//			cout << "  rand = " << random << "  ";
//			cout << "  QueueLength = " << QueueLength << endl;
//			
//			Wait[i - random] = Wait[i];
//		}
//		if (random == 2 /*|| random == 1*/) {
//			Wait[QueueLength - 1] = temp;
//		}
//		else if (random == 1) {
//			Wait[QueueLength - 1] = temp;
//		}
//		else if (random == 0) {
//			for (int i = 0; i < random; i++) {
//				Wait[QueueLength - 1] = temp;
//			}
//		}
//	}
//
//}


void Queue::Extract() {
	// Если в очереди есть элементы, то возвращаем тот, который вошел первым и сдвигаем очередь	
	if (!IsEmpty()) {
		int min = 0, max = 1;
		int random = rand() % (max - min + 1) + min;
		int temp = Wait[0];
		
		for (int j = 0; j < random; j++) {
			for (int i = 1; i < QueueLength; i++) {
				Wait[i - random] = Wait[i];
			}
			int a = 1;
			Wait[QueueLength - a] = temp;
			a++;
		}
	}
}

//void Queue::FirstNum(Queue obj) {
//	const int n = Wait[1];
//	cout << " n = " << n;
//
//	
//}





//void Queue::Extract() {
//	// Если в очереди есть элементы, то возвращаем тот, который вошел первым и сдвигаем очередь	
//	if (!IsEmpty()) {
//		int min = 0, max = 2;
//		int random = rand() % (max - min + 1) + min;
//
//		int temp = Wait[0];
//
//		if (random == 0) {
//			cout << "  random = " << random;
//		}
//		for (int j = 0; j < random; j++) {
//			for (int i = 2; i < QueueLength; i++) {
//				cout << "  random = " << random << "  ";
//				Wait[i - random] = Wait[i];
//			}
//			int a = 1;
//			Wait[QueueLength - a] = temp;
//			a++;
//		}
//
//	}
//
//}
