#include<iostream>
#include"OverrunHandler.h"
using namespace std;
void BDAQCALL OverrunHandler::BfdAiEvent(void* sender, BfdAiEventArgs* args)
{
	cout << "Streaming AI Overrun: count = " << args->Count << ",\t offset = " << args->Offset << endl;
}
