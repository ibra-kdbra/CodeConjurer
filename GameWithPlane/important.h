#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
void Goxy(int x, int y)
{
	COORD xy;
	xy.X = x - 1;
	xy.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
void SetColor(int ForgC)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}
struct position
{
	COORD pos;
	COORD old_pos;
	COORD last_current_enemy;
	int line_count;//�p��ϧΦ��
	int old_line_count;//�¹ϧΦ��
	struct position* pnext;
	struct position* last_pnext;
};
struct bullet_pos
{
	COORD pos;
	int bullet_type;//1=�@���u�� 2=�G���u�� 3=�T���u��
	struct bullet_pos* pnext;
	struct bullet_pos* last_pnext;
};
struct explosion
{
	COORD pos;
	int status;
	int line_status;
	int delay_time;
	struct explosion* pnext;
};
struct star_position
{
	COORD pos[5];
	COORD old_pos[5];
	struct star_position* pnext;
};
