//
//Розробити програмний продукт для реалізації операцій додавання та
//віднімання РЛ чисел.

#include <iostream> 
#include <Windows.h> 
#include <cstdlib> 
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


void dod(vector<int>& a)
{
	sort(a.begin(), a.end(), greater<int>());
	//додаємо однакові елементи в масиві
	for (int i = a.size() - 1; i > 0; i--) {

		if (a[i] == a[i - 1]) {
			a[i - 1] = a[i] + 1;

			a.erase(a.begin() + i);
		}
		sort(a.begin(), a.end(), greater<int>());
	}

}//обєднання*

void mi(vector<int>& a, vector<int>b)
{    //замість а передавати більший масив


	while (!b.empty()) { //цикл доки b не буде пустою 
	
       	for (int i{};i < b.size();i++)
		{
	
			for (int j{};j < a.size();j++)
			{

				if (b[i] == a[j])
				{
					b.erase(b.begin() + i);
					a.erase(a.begin() + j);
					i--;
					break;
				}

			}

		}
		//цикл який видаляє однакові елемент в двох масивах
		

		int iter;
		if(!b.empty())
		for (int i = a.size() - 1;i >= 0;i--)
		{
			if (a[i] > b[b.size() - 1]) {
				iter = i;

				break;
			}
		}
		//шукаємо елемент в масиві а, більший за останій елемент масиву b
		
		bool k = false;
		if (!b.empty())
		for (int i = a[iter] - 1;i >= b[b.size() - 1];i--)
		{

			if (k == false)
			{
				k = true;
				a[iter] = i;
			}
			else a.push_back(i);
		}
		
		//розділяємо більше значення на менші,що б видалити його і з масиву b
		if (!b.empty())
		b.pop_back();
		sort(a.begin(), a.end(), greater<int>());//сортуємо отриманий масив
	}

	

	//виведення а/b для превірки


}


void sum(vector<int>& a, vector<int>b)
{

	bool bil = false, men = false;
	for (int i{};i < a.size();i++)
	{
		for (int i{};i < b.size();i++)
		{
			if (a[i] > b[i])
			{
				bil = true;
				break;
			}

			if (a[i] < b[i])
			{
				men = true;
				break;
			}

		}
		if (bil == true or men == true) break;
	}

	if (bil == false and men == false) cout << "Числа рівні" << endl;
	else if (bil == true)
	{
		
		cout << "Перше число більше" << endl;
	}
	else if (men == true)
	{
	
		cout << "Друге число більше" << endl;
	}

	cout << endl;
	auto iter = a.cbegin();
	a.insert(a.end(), b.begin(), b.end());
	cout << "Об'єднання:" << endl<<"0."+to_string(a.size())+". ";
	for (int i{};i < a.size();i++)
		cout << a[i] <<".";
	cout<<endl<<endl;

	sort(a.begin(), a.end(), greater<int>());
	cout << "Сортування:" << endl << "0." + to_string(a.size()) + ". ";
	for (int i{};i < a.size();i++)
		cout << a[i] << ".";
	cout << endl << endl;

	dod(a);//додавання однакових елементів[2]

	cout << "Зведення подібних:" << endl << "0." + to_string(a.size()) + ". ";
	for (int i{};i < a.size();i++)
		cout << a[i] << ".";
	cout << endl << endl;
	/*for (int i{};i < a.size();i++)
		cout << a[i] << endl;*/
}


void mod_num(string a, string b, char zn, string &c)
{

	int n = a.size() - 1;
	vector<int> m;
	for (int i = n - 1, j = n;i >= 0;i--) {
		//конвертування стрінг у вектор, перебирається стрічка,відстань між крапками конвертується в ціле число[1] 
		if (a[i] == '.' or a[i] == ' ' or i == 0)
		{
			string h;
			if (i != 0) {
				h = a.substr(i + 1, j - i - 1);
				j = i;
			}
			else
			{
				h = a.substr(0, j);
			}
			m.push_back(stoi(h));

		}
	}

	int k = b.size() - 1;
	vector<int> l;

	for (int i = k - 1, j = k;i >= 0;i--)
		//[1]
		if (b[i] == '.' or i == 0)
		{
			string c;
			if (i != 0) {
				c = b.substr(i + 1, j - i);

				j = i;
			}

			else
				c = b.substr(0, j);
			l.push_back(stoi(c));

		}


	dod(m); //[2]
	dod(l); //[2]


	if (zn == 'D' or zn == 'd')
	{
		sum(m, l);
		c = "0." + to_string(m.size()) + ". ";
		for (int i{}; i < m.size();i++) {
			c += to_string(m[i]) + ".";
		}
	}
    if (zn == 'M' or zn == 'm')
	{
		bool bil = false, men = false;
		for (int i{};i < m.size();i++)
		{	for (int i{};i < l.size();i++)
			{
				if (m[i] > l[i])
				{
					bil = true;
					break;
				}

				if (m[i] < l[i])
				{
					men = true;
					break;
				}

			}
		if (bil == true or men == true) break;
	}
		if(bil==false and men==false) c="Числа рівні і результат рівний 0";
		else if (bil ==true)
		{
			mi(m, l);
			c = "0." + to_string(m.size()) + ". ";
			for (int i{}; i < m.size();i++) {
				c += to_string(m[i]) + ".";
			}
			cout << "Перше число більше:" << endl;
		}
		else if (men==true)
		{
			mi(l, m);
			c = "1." + to_string(l.size()) + ". ";
			for (int i{}; i < l.size();i++) {
				c += to_string(l[i]) + ".";
		
			}
			cout << "Друге число більше:"<<endl;
		}
	};

	
	

	//for (int i{};i < m.size();i++)
	//	cout << m[i];

	/*sum(m, l);*/
	/*mi(m,l);*/
}

int main()
{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		char di='D';

		string result;
									
		string First;
		cout << "Введіть перше число,де знак числа,кількість 1,та самі позиції у форматі 0.1. 4.:"<<endl;
		
		getline(cin, First);
		cout << endl;

		string Second ;
		cout << "Введіть друге число,де знак числа,кількість 1,та самі позиції у форматі 0.1. 4.:" << endl;
	
		getline(cin, Second);
		cout << endl;

		cout << "Виберіть дію: D-додавання,M-віднімання: ";
		cin >> di;
		cout << endl;
		cout << "========================================"<<endl;
		cout << endl;
		int fr = First.find_first_of(" ");
		First = First.erase(0, fr+1);

		int sec = Second.find_last_of(" ");
		Second = Second.erase(0, sec+1);

		if ((di == 'D' or di == 'd') or (di == 'M' or di == 'm'))
		{
			mod_num(First, Second, di, result);
			cout << "========================================" <<
				endl << "Результат: " << result << endl
				<< "========================================" << endl;
		}
}