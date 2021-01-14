#include "NOT.h"

NOT::NOT(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool h ) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	Is_h = h;
}


void NOT::Operate()
{
	if (m_InputPins[0].getStatus() == LOW) {
		m_OutputPin.setStatus(HIGH);
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}
}


void NOT::Draw(Output* pOut)
{
	pOut->DrawNOT(m_GfxInfo, Is_h);
}

int NOT::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int NOT::GetInputPinStatus(int n)
{
	return m_InputPins[n-1].getStatus();
}

void NOT::setInputPinStatus(int n,STATUS s)
{
	m_InputPins[0].setStatus(s);
}
