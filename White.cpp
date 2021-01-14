#include "White.h"

White::White(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;

}


void White::Operate()
{
}


void White::Draw(Output* pOut)
{
	pOut->DrawWhite(m_GfxInfo);
}

int White::GetOutPinStatus()
{
	return 0;
}

int White::GetInputPinStatus(int n)
{
	return 0;
}

void White::setInputPinStatus(int n, STATUS s)
{
}
