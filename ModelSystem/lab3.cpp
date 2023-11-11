//
////
////Завдання 1
////Перевести номер залікової книжки / студентського квитка у двійкову систему
////числення та подати його у вигляді розрядно - логарифмічного числа.
////Завдання 2
////Перевести номер залікової книжки / студентського квитка у шістнадцяткову
////систему числення.
////Завдання 3
////Записати свій день(D) і місяць(М) народження(додатне та від’ємне подання D
////	та М) у двійковій системі числення(8 бітів) та у вигляді РЛ - коду.
////	Завдання 4
////	Обчислити значення : A = 1 / (D + M) і B = (D + M) / (D * M) та записати їх у
////	двійковій системі числення та у вигляді РЛ - коду.
////	Завдання 5
////	Знайти А(дробова частина) + В(дробова частина) та А(дробова частина) - В
////	(дробова частина).Результати записати в шістнадцятковій системі числення,
////	двійковій системі та РЛ - коді.
////	Завдання 6
////
////	Реалізувати переведення будь - якого дробового числа в десятковій формі у РЛ -
////	код.
//
//#include <iostream> 
//#include <Windows.h> 
//#include <cstdlib> 
//#include <string>
//#include <algorithm>
//
//
//using namespace std;
//
//
//
//void intbin(string a, string& d)
//{
//	string c;
//	int b = stoi(a);
//	while (b > 0)
//	{
//		if (b % 2 == 0)
//			c = "0" + c;
//
//		else
//		{
//			c = "1" + c;
//			b--;
//		}
//		b = b / 2;
//	}
//	d = c;
//
//}
//
//void uintbin(string a, string& d)
//{
//	if (a.size() == 1)
//		a += "000";
//	else if (a.size() == 2)
//		a += "00";
//	else if (a.size() == 3)
//		a += "0";
//	string c;
//	
//	int b = stoi(a);
//	for (int i{};i < 10;i++)
//	{
//		b *= 2;
//	
//		if (b >= 10000)
//		{
//		
//			c += "1";
//			b -= 10000;
//		}
//		else
//		{
//			c += "0";
//		}
//	}
//	d = c;
//}
//
//void binary(string a, string& b)
//{
//
//	string fpart, secpart;
//	int c = a.find('.');
//	if (c == string::npos)
//		intbin(a, b);
//	else
//	{
//		for (int i{};i < c;i++)
//			fpart += a[i];
//		intbin(fpart, fpart);
//
//		if (fpart.empty())fpart = "0";
//
//		for (int i = c + 1;i <a.size();i++)
//			secpart += a[i];
//		if(secpart.size()>4)
//		secpart = secpart.substr(0, 4);
//		uintbin(secpart, secpart);
//
//		b = fpart + '.' + secpart;
//
//	}
//}
//
//
//void intRL(string a, string& d)
//{
//	string c;
//	for (int i{};i < a.size();i++) {
//		if (a[i] == '1') c += to_string(a.size() - i - 1) + ".";
//
//	}
//	d = c;
//}
//
//void uintRL(string a, string& d)
//{
//	string c;
//	for (int i{};i < a.size();i++)
//		if (a[i] == '1')c += "-" + to_string(i + 1) + ".";
//
//	d = c;
//}
//
//void RL(string a, string& b)
//{
//
//	string fpart, secpart;
//	int c = a.find('.');
//	if (c == string::npos)
//		intRL(a, b);
//	else
//	{
//		for (int i{};i < c;i++)
//			fpart += a[i];
//		intRL(fpart, fpart);
//		for (int i = c + 1;i < a.size();i++)
//			secpart += a[i];
//		uintRL(secpart, secpart);
//
//		b = fpart + secpart;
//
//	}
//}
//
//
//void UintSixt(string a, string& d)
//{
//
//	string c;
//	if (a.size() == 1)
//		a += "00";
//	else if (a.size() == 2)
//		a += "0";
//	int b = stoi(a.substr(0,3));
//
//
//	for (int i{};i < 10;i++)
//	{
//		b *= 16;
//		if (b >= 1000)
//		{
//			
//			if (b / 1000 > 0 and b / 1000 < 10)
//			{
//				
//				c += to_string(b / 1000);
//			}
//			else
//			{
//			
//				c += char(b / 1000 + 55) + d;
//			}
//			b -= b / 1000 * 1000;
//		
//		}
//		else
//			c += "0";
//
//	}
//	d = c.substr(0, 10);
//}
//
//void IntSixt(string a, string& d)
//{
//	string c;
//	int dec = stoi(a);
//	while (dec > 0) {
//		int digit = dec % 16;
//		if (digit < 10)
//			c = to_string(digit) + c;
//		else
//			c = char(digit + 55) + c;
//		dec /= 16;
//	}
//	if (c.empty())
//		c = "0";
//	d = c;
//}
//
//void toSixt(string a, string& b)
//{
//
//	string fpart, secpart;
//	int c = a.find('.');
//	if (c == string::npos)
//	{
//		IntSixt(a, b);
//		return;
//	}
//	else
//	{
//		for (int i{};i < c;i++)
//			fpart += a[i];
//		IntSixt(fpart, fpart);
//
//		for (int i = c + 1;i < a.size();i++)
//			secpart += a[i];
//		UintSixt(secpart, secpart);
//		b = fpart + "." + secpart;
//
//	}
//}
//
//
//int main()
//{
//	while (true)
//	{
//		string inputStr;
//
//		string binval;
//
//		string Rl;
//
//		string SiXteenth;
//
//		int NumT;
//
//		cout << "----------------------------------------------" << endl << "Input number of Task(1 - 6) :";
//		cin >> NumT;
//		if (NumT < 1 or NumT>6)
//		{
//			cout << endl << "Invalid value" << endl << endl;
//		}
//
//		switch (NumT)
//		{
//		case 1:
//		{
//			cout << endl << "Input number in format 120: ";
//			cin.ignore();
//			getline(cin, inputStr);
//			binary(inputStr, binval);
//			RL(binval, Rl);
//			cout <<endl<< "Binary value:" << binval << endl;
//			cout << "RL value:" << Rl << endl << endl;
//			break;
//		}
//
//		case 2:
//		{
//			cout << endl << "Input number in format 120: ";
//			cin.ignore();
//			getline(cin, inputStr);
//			toSixt(inputStr, SiXteenth);
//
//			cout << endl << "Hexadecimal value:" << SiXteenth << endl << endl;
//			break;
//		}
//
//		case 3:
//		{
//			cout << endl << "Input day and month in format: 16 14: ";
//			cin.ignore();
//			getline(cin, inputStr);
//
//			string day, month, dayr, monthr;
//			day = inputStr.substr(0, 2);
//			month = inputStr.substr(3, 2);
//
//			binary(day, day);
//			binary(month, month);
//
//			RL(day, dayr);
//			RL(month, monthr);
//			cout << endl << "Positive representation binary and RL:" << endl << "Binary: Day:0. " << day + " Month:0. " + month << endl << endl << "RL: Day:0. " << dayr + " Month:0. " + monthr << endl << endl;
//			cout << "Negative representation binary and RL:" << endl << "Binary: Day:1. " << day + " Month:1. " + month << endl << endl << "RL: Day:1. " << dayr + " Month:1. " + monthr << endl << endl;
//			break;
//		}
//
//		case 4:
//		{
//			cout <<endl<< "Input day and month in format: 16 14: ";
//			cin.ignore();
//			getline(cin, inputStr);
//
//			string day, month, dayr, monthr, a, b;
//			double A, B;
//			for (int i{}, c = 0;i < inputStr.size();i++)
//			{
//				if (inputStr[i] == ' ') {
//					c = 1;
//					continue;
//				}
//				if (c == 0)
//					day += inputStr[i];
//				if (c == 1)
//					month += inputStr[i];
//			}
//
//			A = 1 / (stod(day) + stod(month));
//			B = (stod(day) + stod(month)) / (stod(day) * stod(month));
//
//			cout << endl << "A:" << A << "  B:" << B << endl;
//
//			a = to_string(A);
//			b = to_string(B);
//
//			binary(a, day);
//			binary(b, month);
//
//			RL(day, dayr);
//			RL(month, monthr);
//			cout << endl << "Representation binary and RL:" << endl << "Binary: A:" << day + " B:" + month << endl << endl << "RL: A:" << dayr + " B:" + monthr << endl<<endl;
//			break;
//		}
//
//		case 5:
//		{
//			cout <<endl<< "Input day and month in format: 16 14: ";
//			cin.ignore();
//			getline(cin, inputStr);
//
//			string day, month, dayr, monthr, dayS, monthS, a, b;
//			double A, B;
//			for (int i{}, c = 0;i < inputStr.size();i++)
//			{
//				if (inputStr[i] == ' ') {
//					c = 1;
//					continue;
//				}
//				if (c == 0)
//					day += inputStr[i];
//				if (c == 1)
//					month += inputStr[i];
//			}
//
//			A = 1 / (stod(day) + stod(month));
//			B = (stod(day) + stod(month)) / (stod(day) * stod(month));
//
//			cout << endl << "A:" << A << "  B:" << B << endl;
//
//			a = to_string(A + B);
//			b = to_string(A - B);
//
//			cout << endl << "A+B:" << a << "  A-B:" << b << endl;
//
//			toSixt(a, dayS);
//			toSixt(b, monthS);
//
//			binary(a, day);
//			binary(b, month);
//
//			RL(day, dayr);
//			RL(month, monthr);
//			cout << endl << "Hexadecimal value :" << endl << "A+B:" << dayS << "       A-B:" << monthS << endl << endl;
//			cout << endl << "Representation binary and RL:" << endl << "Binary: A+B:" << day + "       A-B:" + month << endl << endl << "RL: A+B:" << dayr + "     A-B:" + monthr << endl<<endl;
//			break;
//		}
//
//		case 6:
//		{
//			cout << "Input number in format 10.231: ";
//			cin.ignore();
//			getline(cin, inputStr);
//		    
//			binary(inputStr, binval);
//			RL(binval, Rl);
//			cout << endl << "Binary value:" << binval << endl;
//			cout << endl << "RL value:" << Rl << endl<<endl;
//			break;
//		}
//	
//		}
//	}
//}