#include <iostream>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

using std::cout;
using std::endl;
using std::cin;

int main(void) {

	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);

	if (wsOk != 0) {
		std::cerr << "Cant init winsock! Quitting!" << endl;
		return;
	}

	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET) {
		std::cerr << "CAN'T CREATE A SOSCKET! QUITTING!" << endl;
		return;
	}

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000); //port 54000
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	listen(listening, SOMAXCONN);

	sockaddr_in client;
	int clientSize = sizeof(client);

	SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	char host[NI_MAXHOST];        // Client's remote name
	char service[NI_MAXHOST];     // Service the client is connect on

	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXHOST);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
		cout << host << " connected on port " << service << endl;
	}
	else {
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << host << " connected on port " << ntohs(client.sin_port) << endl;
	}

	closesocket(listening);

	char buf[4096];

	while (true){
		ZeroMemory(buf, 4096);
		
		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		if (bytesReceived == SOCKET_ERROR) {
			std::cerr << "Error in recv(). Quitting" << endl;
			break;
		}

		if (bytesReceived == 0) {
			cout << "client disconnected " << endl;
			break;
		}

		

	}


	return 0;
}