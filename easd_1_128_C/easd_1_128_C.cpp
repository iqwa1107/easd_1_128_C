// NO 1 : dalam algoritma sangat pentng untuk di gunakan di karenakan untuk memcahkan sebuah masalah dalam bebeapa masalah seperti mengurutkan data mencari niilai tertentu pada data
// No 2 : array adalah struktur data yang terdiri dari kumpulan element yang sama jenisnya 
//        linked list adlah terdiri data yang terhubung
// NO 3 : Faktor Faktor yang memperngaruhi efesiensi suatu pemorgaman adalah seberapa rumit algoritma yang di butuhkan dan waktu pengerjaan nya
// No 4 : bubble sort
// No 5 : quadratic selection sort,insertion sort,
//      : loglinier quick sort


#include <iostream>
using namespace std;

int ikk[46];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
	while (true)
	{
		cout << "masukan panjang element array: ";
		cin >> n;

		if (n <= 46)
			break;
		else
			cout << "\nMaksimum panjang array adalah 46" << endl;


	}

	cout << "\n ------------------" << endl;
	cout << "\nEnter array Element" << endl;
	cout << "\n ------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> ikk[i];
	}
}

void swep(int x, int y)
{
	int temp;

	temp = ikk[x];
	ikk[x] = ikk[y];
	ikk[y] = temp;

}

void q_short(int low, int high)
{
	int pivot, i, k;
	if (low > high)
		return;                          // Langkah algoritma No. 1


	// partition the list to parts;
	// one containing elemnts less that or equal to pivot
	// outher containing elements greather the pivot 

	pivot = ikk[low];                    // langkah algoritma no 2

	i = low + 1;                         // langkah algoritma no 3
	k = high;                            // langkah algoritma no 4

	while (i <= k)
	{
		// search for an el element less then or equal to pivot
		while ((ikk[i] <= pivot) && (i <= high))           //langkah algoritma no 5
		{
			i++;                                            //langkah algoritma no 6
			cmp_count++;
		}
		cmp_count++;                                        //langkah algoritma no 8


		// search for an el element less then or equal to pivot
		while ((ikk[k] > pivot) && (k >= low))           //langkah algoritma no 7
		{
			k--;                                            //langkah algoritma no 8
			cmp_count++;
		}
		cmp_count++;

		// if the greater element is on the left the elemnt 
		cmp_count++;
		if (i < k)           //langkah algoritma no 9
		{
			//swap the ekemnt at index 1 whit the element at index j
			swap(i, k);
			mov_count++;

		}

	}
	//j now contain the indx of the last elemnt in the sorted list 
	if (low < k)               //Langkah Algoritma No 11
	{
		//move the pivot to its correct position in the list
		swap(low, k);
		mov_count++;
	}
	//short the list on the left of pivot using quik short 
	q_short(low, k - 1);       //Langkah Algoritma No 12

	//short the list on the left of pivot using quik short 
	q_short(k + 1, high);       //Langkah Algoritma No 13


}
void display() {
	cout << "\n===========================" << endl;
	cout << "Sorted Array" << endl;
	cout << "\n===========================" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ikk[i] << " ";
	}

	cout << "\n\nNumber of comprasion: " << cmp_count << endl;
	cout << "Number of data movemnt: " << mov_count << endl;
}

int main()
{
	input();
	q_short(0, n - 1);
	display();
	system("pause");

	return 0;

}