#include "Connection_w.h"

Connection_w::Connection_w(const GraphicsInfo& r_GfxInfo) :Component(r_GfxInfo)

{
}
void Connection_w::setSourcePin(OutputPin* pSrcPin)
{
}

OutputPin* Connection_w::getSourcePin()
{
	return 0;
}


void Connection_w::setDestPin(InputPin* pDstPin)
{
}

InputPin* Connection_w::getDestPin()
{
	return 0;
}


void Connection_w::Operate()
{
}

void Connection_w::Draw(Output* pOut)
{
	pOut->DrawConnection_w(m_GfxInfo);
}

int Connection_w::GetOutPinStatus()	
{
	return 0;
}


int Connection_w::GetInputPinStatus(int n)	
{
	return 0;
}

void Connection_w::setInputPinStatus(int n, STATUS s)
{
}
