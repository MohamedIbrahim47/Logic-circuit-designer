#include "BUFFER.h"

BUFFER::BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool h) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	Is_h = h;
}


void BUFFER::Operate()
{
	if (m_InputPins[0].getStatus() == LOW) {
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		m_OutputPin.setStatus(HIGH);
	}
}


void BUFFER::Draw(Output* pOut)
{
	pOut->DrawBUFFER(m_GfxInfo, Is_h);
}

int BUFFER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int BUFFER::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void BUFFER::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
