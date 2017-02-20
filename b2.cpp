#include <iostream>
using namespace std;

int schet (int P, int t, int I){
	//S - сумма конечная, P - первоначальная сумма 
	// K - количество дней в году, t - количество дней
	//I - процентная ставка
	int K = 365, S;
	S = P + ((P*I*t)/(K*100));
	return S;
}

int main()
{
	int srok;
	long int SumVklad, sum;
	
	cout << "Введите сумму вклада(>=10000) и срок(<=365):\n";
    
    for (;;){
		cin >> SumVklad;
		if (SumVklad >= 10000) break;
		else cout << "Введите корректную сумму вклада..\n";
	}
	
    for (;;){
		cin >> srok;
		if ((srok <= 365) && (srok>=0)) break;
		else cout << "Введите корректное число срока вклада..\n";
	}
	
	if (srok >= 0 && 30 <= srok) sum = schet(SumVklad, srok, -10);
	if (srok >= 31 && 120 <= srok){
		if (SumVklad < 100000) sum = schet(SumVklad, srok, 2);
		else sum = schet(SumVklad, srok, 3);
	}
	if (srok >= 121 && 240 <= srok){
		if (SumVklad < 100000) sum = schet(SumVklad, srok, 6);
		else sum = schet(SumVklad, srok, 8);
	}
	if (srok >= 241 && 365 <= srok){
		if (SumVklad < 100000) sum = schet(SumVklad, srok, 12);
		else sum = schet(SumVklad, srok, 15);
	}
		
		
	cout << "\n\n\nОтвет: \n\n" << sum;
	
	
    return 0;
}
