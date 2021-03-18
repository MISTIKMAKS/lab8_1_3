#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int CountB(char* s)
{
	int b = 0,
		pos = 0;
	char* t;
	while (t = strchr(s + pos, 'B'))
	{
		pos = t - s + 1;
		b++;
	}
	return b;
}
int CountA(char* s)
{
	int a = 0,
		pos = 0;
	char* t;
	while (t = strchr(s + pos, 'A'))
	{
		pos = t - s + 1;
		a++;
	}
	return a;
}
int CountS(char* s)
{
	int es = 0,
		pos = 0;
	char* t;
	while (t = strchr(s + pos, 'S'))
	{
		pos = t - s + 1;
		es++;
	}
	return es;
}
int CountI(char* s)
{
	int i = 0,
		pos = 0;
	char* t;
	while (t = strchr(s + pos, 'I'))
	{
		pos = t - s + 1;
		i++;
	}
	return i;
}
int CountC(char* s)
{
	int c = 0,
		pos = 0;
	char* t;
	while (t = strchr(s + pos, 'C'))
	{
		pos = t - s + 1;
		c++;
	}
	return c;
}
char* Change(char* s)
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	while (p = strchr(s + pos1, 'B'))
	{
		if (s[p - s + 1] == 'A')
		{
			if (s[p - s + 2] == 'S')
			{
				if (s[p - s + 3] == 'I')
				{
					if (s[p - s + 4] == 'C')
					{
						pos2 = p - s + 5;
						strncat(t, s + pos1, pos2 - pos1 - 5);
						strcat(t, "Delphi");
						pos1 = pos2;
					}
					else {
						break;
					}
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}
		else {
			break;
		}
	}

	strcat(t, s + pos1);
	strcpy(s, t);
	return t;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << CountB(str) << " B " << CountA(str) << " A " << CountS(str) << " S " << CountI(str) << " I " << CountC(str) << " C " << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}