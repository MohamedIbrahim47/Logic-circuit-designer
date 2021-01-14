#include "NAND2.h"

NAND2::NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool h) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;

	Is_h = h;
}


void NAND2::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH) {
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		m_OutputPin.setStatus(HIGH);
	}

}


void NAND2::Draw(Output* pOut)
{
	pOut->DrawNAND2(m_GfxInfo, Is_h);
}

int NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
