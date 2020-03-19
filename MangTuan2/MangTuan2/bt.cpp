#include <iostream>
#include <stdlib.h>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32")

using namespace std;

// Kiem tra ten mien
int Check(string str)
{
	int i;
	for (i = 0; i < str.length(); i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '.' || str[i] == '_');
		else
		{
			break;
		}
	}
	if (i == str.length()) return 1;
	return 0;
}

int main()
{
	string tmp;
	cout << "Nhap ten mien: ";
	cin >> tmp;

	if (Check(tmp) == 0) {

		cout << "Ten mien khong hop le !!!";
		return 0;
	}

	// Khoi tao thu vien Winsock
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	addrinfo* info;
	SOCKADDR_IN addr;

	const char* url = tmp.c_str();
	int ret = getaddrinfo(url, "http", NULL, &info);
	if (ret == 0)
	{
		memcpy(&addr, info->ai_addr, info->ai_addrlen);
		cout << "Phan giai ten mien thanh cong" << endl;
		cout << "Dia chi IP:" << inet_ntoa(addr.sin_addr) << endl;
	}
	else cout << "Phan giai ten mien khong thanh cong" << endl;

	return 0;
}