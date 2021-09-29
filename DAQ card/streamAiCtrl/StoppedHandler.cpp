#include<iostream>
#include"StoppedHandler.h"
using namespace std;

void BDAQCALL StoppedHandler::BfdAiEvent(void* sender, BfdAiEventArgs* args)
{
	cout << "Streaming AI stopped: offset = " << args->Offset << ", count = " << args->Count << endl;
}
