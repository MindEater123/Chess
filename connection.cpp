#include "Pipe.h"
#include "board.h"
#include "Communication.h"
#include <iostream>
#include <thread>

using namespace std;
void main()
{
	srand(time_t(NULL));

	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	system("start chessGraphics.exe");
	while (!isConnect)
	{
		//cout << "cant connect to graphics" << endl;
		//cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		//cin >> ans;

		if ("0"   == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(1000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024] = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1";
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	Board board("rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1");
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	communication com;
	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		com.setPlacec(msgFromGraphics);
		
		// YOUR CODE
		strcpy_s(msgToGraphics, "0"); // msgToGraphics should contain the result of the operation
		board.setMyPlace(com.lastpoint());
		msgToGraphics[0] = board.canMove(com.newpoint())+48;
		if (msgToGraphics[0] == '0' || msgToGraphics[0] == '1' || msgToGraphics[0] == '8')
		{
			if (msgToGraphics[0] == '8')
			{
				p.sendMessageToGraphics("0");
				msgFromGraphics = p.getMessageFromGraphics();
				p.sendMessageToGraphics("8");

			}
			board.setMove(com.newpoint());
		}
		/******* JUST FOR EREZ DEBUGGING ******/
		/******* JUST FOR EREZ DEBUGGING ******/


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   
		
		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}