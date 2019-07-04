// Socket_TCP_C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include<Windows.h>
using namespace std;

#pragma comment(lib,"ws2_32.lib")


int main()
{
	SOCKET sockSer;
	sockSer = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSer, addrCli;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(5050);
	addrSer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	bind(sockSer, (SOCKADDR*)& addrSer, sizeof(SOCKADDR));

	listen(sockSer, 5);

	SOCKET sockConn;
	int len = sizeof(SOCKADDR);

	cout << "Server Wait Client Connect......" << endl;
	sockConn = accept(sockSer, (SOCKADDR*)& addrCli, &len);
		if (sockConn == INVALID_SOCKET)
		{
			cout << "Server Accept Client Connect Fail!" << endl;
		}
		else
		{
			cout << "Server Accept Client Connect Fail!" << endl;
		}

		char sendbuf[256];
		char recvbuf[256];
		while (1)
		{
			cout << "Ser:>";
			cin >> sendbuf;
			if (strcmp(sendbuf, "quit") == 0)
			{
				break;
			}
			send(sockConn, sendbuf, strlen(sendbuf) + 1,0);
			recv(sockConn, recvbuf, 256, 0);
			cout << "CLi:>" << recvbuf << endl;
		}
		closesocket(sockSer);
}
