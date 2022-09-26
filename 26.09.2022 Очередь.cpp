#include <iostream>
#include <string.h>
#include <time.h>
#include "Queue.h"
using namespace std;


void main() { 
	srand(time(0));
	
	int a = 0;
	int b = 0;
	int c = 0;

	Queue QU(10);
	for (int i = 0; i < 3; i++) {
		QU.Add(rand() % 7);
	}
	QU.Show();
	QU.FirstNum(a);
	
	QU.Extract();
	QU.Show();
	QU.FirstNum(b);

	QU.Extract();
	QU.Show();
	QU.FirstNum(c);

	if (a == b && a == c) {
		cout << "You are win!!!" << endl;
	}
	else {
		cout << "You are loose" << endl;
	}

}
