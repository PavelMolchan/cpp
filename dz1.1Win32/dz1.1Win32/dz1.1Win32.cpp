#include <windows.h>
#include <tchar.h>
#include <stdlib.h>

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{

	wchar_t str1[] = TEXT("����");
	wchar_t str2[] = TEXT("���");
	wchar_t str3[] = TEXT("�� ����");
	MessageBox(
		0,
		str1,
		TEXT("�������� 1"),
		MB_OK | MB_ICONINFORMATION
		);
	MessageBox(
		0,
		str2,
		TEXT("�������� 2"),
		MB_OK | MB_ICONINFORMATION
		);
	int n = (wcslen(str1) + wcslen(str2) + wcslen(str3)) / 3;
	wchar_t str4[10];
	_itow(n, str4, 10);
	wchar_t	str5[60] = TEXT("������� ���������� �������� �� �������� ");
	wcscat(str5, str4);
	MessageBox(
		0,
		str3,
		str5,
		MB_OK | MB_ICONINFORMATION
		);
	return 0;
}