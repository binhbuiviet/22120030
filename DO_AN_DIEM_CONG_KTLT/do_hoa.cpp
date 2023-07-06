#include "do_hoa.h"

void goto_XY(int x, int y) //Hàm này dùng để đặt vị trí con trỏ in ra màn hình
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); //Đây là hàm có sẵn trong thư viện windows.h
}

void ve_hop(int x, int y, int w, int h)
{
	if (h <= 1 || w <= 1)
		return;
	for (int i = x; i <= x + w; i++)
	{
		goto_XY(i, y);
		cout << char(151);
		goto_XY(i, y + h);
		cout << char(151);
	}
	for (int i = y; i <= y + h; i++)
	{
		goto_XY(x, i);
		cout << char(124);
		goto_XY(x + w, i);
		cout << char(124);
	}
}

void Xoa_dong(int y)
{
	goto_XY(0, y);
	printf("%c[2K", 27);
}