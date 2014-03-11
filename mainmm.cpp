#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

/**
@brief для слияния
*/
#define maxn 100

int zebra[maxn];

/**
@brief для слияния
*/

void merge(int l, int r) {
	/**
	@brief функция слияния
	*/
    if (r == l)
        return;
    if (r - l == 1) { 
        if (zebra[r] < zebra[l])
            swap(zebra[r], zebra[l]);
        return;
    }
    int m = (r + l) / 2;
    merge(l, m);
    merge(m + 1, r);
    int buf[maxn];
    int xl = l;
    int xr = m + 1;
    int cur = 0;
    while (r - l + 1 != cur) {
        if (xl > m)
            buf[cur++] = zebra[xr++];
        else if (xr > r)
            buf[cur++] = zebra[xl++];
        else if (zebra[xl] > zebra[xr])
            buf[cur++] = zebra[xr++];
        else buf[cur++] = zebra[xl++];

    }
    for (int i = 0; i < cur; i++)
        zebra[i + l] = buf[i];
}

int main()
{
	int zna4enie = 0;
	cout << "Vvedite operaziu: 1-puzirk, 2-sli9nie" << endl;
	cin >> zna4enie;
	if (zna4enie == 1){
	/**
	@brief Проверка на опперацию
    @brief Пузырьковая сортировка
	*/
	 const int n = 5;
	 int a[n];
	 for (int i = 0; i < n; ++i) 
		 /**
		 @brief создаем массив элементов
		 */
	 {
		int k = rand()%100-1;
	    a[i] = k;
	   cout << a[i] << endl;
	 }
	 /** 
	 @brief сама сортировка
	 */
	  for (int i = n - 1; i >= 1; --i)
	   for (int j = 0; j < i; ++j)
	    {
	   if (a[j] > a[j + 1])
	   {
	     int foo = a[j];
	     a[j] = a[j + 1];
	     a[j + 1] = foo;
	   }
	  }
   	 cout << endl;
	 for (int i = 0; i < n; ++i) 
     /** 
	 @brief вывод
	 */
	 cout << a[i] << endl;
	} 
	/**
	@brief Конец сортировки пузырьком
	*/

	if (zna4enie == 2)
	/**
	@brief Проверка на опперацию
	@brief слияние
	*/
	{
		int n;
		cout << "Vvedite kol-vo";
		cin >> n;

    for (int i = 0; i < n; i++)
       zebra[i]= rand()%100-1;

    merge(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << zebra[i] << "   ";

    getch();
    return 0;
	}
	/**
	@brief конец слияния
	*/
}