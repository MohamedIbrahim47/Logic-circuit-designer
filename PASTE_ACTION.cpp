#include "PASTE_ACTION.h"
#include "ApplicationManager.h"
#include "Components/AND2.h"

PASTE_ACTION::PASTE_ACTION(ApplicationManager* pApp) :Action(pApp)
{
	abort = 0;
}

PASTE_ACTION::~PASTE_ACTION(void)
{

}

void PASTE_ACTION::ReadActionParameters()
{
	/////////////////Read Actionparameters//////////////////////////////////
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Click where you want to paste");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	////////////////////////////////////////////////////////////////////////

	//////////////////
	if (y < 185 || y > 675) {
		abort = 1;
		pOut->PrintMsg("Action aborted, you can only paste in the drawing area");
	}
	//////////////////
}

void PASTE_ACTION::Execute()
{
	ReadActionParameters();

	if (abort != 0) {
		return;
	}


	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	GraphicsInfo GInfo;
	
	Component* copied = pManager->GetCopied();

	//////////////////////////
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	/// //////////////////////

	if (copied == NULL) {
		pOut->PrintMsg("You havent copied any components yet!");
	}
	else
	{
		GInfo.x1 = x - Len / 2;
		GInfo.x2 = x + Len / 2;
		GInfo.y1 = y - Wdth / 2;
		GInfo.y2 = y + Wdth / 2;
		if (dynamic_cast<AND2*>(copied) != NULL)
		{
			AND2* pA;
			if (copied->Getis_selected() == false)
				pA = new AND2(GInfo, AND2_FANOUT, false);
			else
				pA = new AND2(GInfo, AND2_FANOUT, true);
			pA->Setis_selected(copied->Getis_selected());
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<OR2*>(copied) != NULL)
		{
			OR2* pA;
			if (copied->Getis_selected() == false)
				pA = new OR2(GInfo, AND2_FANOUT, false);
			else
				pA = new OR2(GInfo, AND2_FANOUT, true);
			pA->Setis_selected(copied->Getis_selected());
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<NAND2*>(copied) != NULL)
		{
			NAND2* pA;
			if (copied->Getis_selected() == false)
				pA = new NAND2(GInfo, AND2_FANOUT, false);
			else
				pA = new NAND2(GInfo, AND2_FANOUT, true);
			pA->Setis_selected(copied->Getis_selected());
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<NOR2*>(copied) != NULL)
		{
			NOR2* pA;
			if (copied->Getis_selected() == false)
				pA = new NOR2(GInfo, AND2_FANOUT, false);
			else
				pA = new NOR2(GInfo, AND2_FANOUT, true);
			pA->Setis_selected(copied->Getis_selected());
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<XOR2*>(copied) != NULL)
		{
			XOR2* pA;
			if (copied->Getis_selected() == false)
				pA = new XOR2(GInfo, AND2_FANOUT, false);
			else
				pA = new XOR2(GInfo, AND2_FANOUT, true);
			pA->Setis_selected(copied->Getis_selected());
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<XNOR2*>(copied) != NULL)
		{
			XNOR2* pA;
			if (copied->Getis_selected() == false)
				pA = new XNOR2(GInfo, AND2_FANOUT, false);
			else
				pA = new XNOR2(GInfo, AND2_FANOUT, true);
			pA->Setis_selected(copied->Getis_selected());
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<AND3*>(copied) != NULL)
		{
			AND3* pA;
			if (copied->Getis_selected() == false)
				pA = new AND3(GInfo, AND2_FANOUT, false);
			else
				pA = new AND3(GInfo, AND2_FANOUT, true);
			pA->Setis_selected(copied->Getis_selected());
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<NOR3*>(copied) != NULL)
		{
			NOR3* pA;
			if (copied->Getis_selected() == false)
				pA = new NOR3(GInfo, AND2_FANOUT, false);
			else
				pA = new NOR3(GInfo, AND2_FANOUT, true);
			pA->Setis_selected(copied->Getis_selected());
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<XOR3*>(copied) != NULL)
		{
			XOR3* pA;
			if (copied->Getis_selected() == false)
				pA = new XOR3(GInfo, AND2_FANOUT, false);
			else
				pA = new XOR3(GInfo, AND2_FANOUT, true);
			pA->Setis_selected(copied->Getis_selected());
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<BUFFER*>(copied) != NULL)
		{
			BUFFER* pA;
			if (copied->Getis_selected() == false)
				pA = new BUFFER(GInfo, AND2_FANOUT, false);
			else
				pA = new BUFFER(GInfo, AND2_FANOUT, true);
			pA->Setis_selected(copied->Getis_selected());
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<NOT*>(copied) != NULL)
		{
			NOT* pA;
			if (copied->Getis_selected() == false)
				pA = new NOT(GInfo, AND2_FANOUT, false);
			else
				pA = new NOT(GInfo, AND2_FANOUT, true);
			pA->Setis_selected(copied->Getis_selected());
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<LED*>(copied) != NULL)
		{
			LED* pA;
			if (copied->Getis_selected() == false)
				pA = new LED(GInfo, AND2_FANOUT, false);
			else
				pA = new LED(GInfo, AND2_FANOUT, true);
			pA->Setis_selected(copied->Getis_selected());
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<SWITCH*>(copied) != NULL)
		{
		SWITCH* pA;
		if (copied->Getis_selected() == false)
			pA = new SWITCH(GInfo, AND2_FANOUT, false);
		else
			pA = new SWITCH(GInfo, AND2_FANOUT, true);
		pA->Setis_selected(copied->Getis_selected());
		pManager->AddComponent(pA);
		}
	}
}

void PASTE_ACTION::Undo()
{}

void PASTE_ACTION::Redo()
{}

