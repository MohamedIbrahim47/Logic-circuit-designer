#include <iostream>
#include "AddCONNECTION.h"
#include "ApplicationManager.h"
#include "Components/AND2.h"
#include "OR2.h"
#include "Components/Connection.h"
#include "NAND2.h"
#include "NOR2.h"
#include "XNOR2.h"
#include "XOR2.h"
#include "AND3.h"
#include "NOR3.h"
#include "XOR3.h"
#include "SWITCH.h"
#include "LED.h"

AddCONNECTION::AddCONNECTION(ApplicationManager* pApp) :Action(pApp)
{
}

AddCONNECTION::~AddCONNECTION(void)
{
}

void AddCONNECTION::ReadActionParameters()
{
	//i had to use ReadActionParameters implementation inside execute function
}

void AddCONNECTION::Execute()
{
	int dist = 0;
	int source = 0;
	//ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Connection line: Click on the source gate");

	//added///

	Component** List = pManager->GetList();
	GraphicsInfo GInfo;
	GInfo.x1 = 0;
	GInfo.x2 = 0;
	GInfo.y1 = 0;
	GInfo.y2 = 0;

	OutputPin* pSrcPin = new OutputPin(5);					//and fanout 5(reference)
	InputPin* pDstPin = new InputPin();						//creates *inputpin

	Component* SrcCmpnt = NULL;
	Component* DstCmpnt = NULL;
	

	pIn->GetPointClicked(x, y);

	if (*List != NULL) {						// *list != null to prevent errors when user try to add connection when there is no connections
		for (int i = 0; i < pManager->GetCompCount(); i++) {		//200 for maximum 
			if (x > List[i]->getGraphicsInfo().x1 && x < List[i]->getGraphicsInfo().x2) {
				if (y > List[i]->getGraphicsInfo().y1 && y < List[i]->getGraphicsInfo().y2) {
					if (List[i]->Getis_deleted() == false)
					{
						if (dynamic_cast<White*>(List[i]) == NULL) {
							if (dynamic_cast<Connection*>(List[i]) == NULL) {
								source = 1;
								if (dynamic_cast<AND2*>(List[i]) != NULL) {
									SrcCmpnt = List[i];
									x1 = List[i]->getGraphicsInfo().x2;				//x of source pin @ the end
									y1 = List[i]->getGraphicsInfo().y1 + 25;			//25 is UI.AND2_Height(reference of gates)/2
									pOut->PrintMsg("you have clicked on AND2 gate, click on distination gate");
									break;
								}
								else if (dynamic_cast<OR2*>(List[i]) != NULL)
								{
									SrcCmpnt = List[i];
									x1 = List[i]->getGraphicsInfo().x2;
									y1 = List[i]->getGraphicsInfo().y1 + 25;
									pOut->PrintMsg("you have clicked on OR2 gate, click on distination gate");
									break;
								}
								else if (dynamic_cast<NAND2*>(List[i]) != NULL)
								{
									SrcCmpnt = List[i];
									x1 = List[i]->getGraphicsInfo().x2;
									y1 = List[i]->getGraphicsInfo().y1 + 25;
									pOut->PrintMsg("you have clicked on NAND2 gate, click on distination gate");
									break;
								}
								else if (dynamic_cast<NOR2*>(List[i]) != NULL)
								{
									SrcCmpnt = List[i];
									x1 = List[i]->getGraphicsInfo().x2;
									y1 = List[i]->getGraphicsInfo().y1 + 25;
									pOut->PrintMsg("you have clicked on NOR2 gate, click on distination gate");
									break;
								}
								else if (dynamic_cast<XOR2*>(List[i]) != NULL)
								{
									SrcCmpnt = List[i];
									x1 = List[i]->getGraphicsInfo().x2;
									y1 = List[i]->getGraphicsInfo().y1 + 25;
									pOut->PrintMsg("you have clicked on XOR2 gate, click on distination gate");
									break;
								}
								else if (dynamic_cast<XNOR2*>(List[i]) != NULL)
								{
									SrcCmpnt = List[i];
									x1 = List[i]->getGraphicsInfo().x2;
									y1 = List[i]->getGraphicsInfo().y1 + 25;
									pOut->PrintMsg("you have clicked on XNOR2 gate, click on distination gate");
									break;
								}
								else if (dynamic_cast<AND3*>(List[i]) != NULL)
								{
									SrcCmpnt = List[i];
									x1 = List[i]->getGraphicsInfo().x2;
									y1 = List[i]->getGraphicsInfo().y1 + 25;
									pOut->PrintMsg("you have clicked on AND3 gate, click on distination gate");
									break;
								}
								else if (dynamic_cast<NOR3*>(List[i]) != NULL)
								{
									SrcCmpnt = List[i];
									x1 = List[i]->getGraphicsInfo().x2;
									y1 = List[i]->getGraphicsInfo().y1 + 25;
									pOut->PrintMsg("you have clicked on NOR3 gate, click on distination gate");
									break;
								}
								else if (dynamic_cast<XOR3*>(List[i]) != NULL)
								{
									SrcCmpnt = List[i];
									x1 = List[i]->getGraphicsInfo().x2;
									y1 = List[i]->getGraphicsInfo().y1 + 25;
									pOut->PrintMsg("you have clicked on XOR3 gate, click on distination gate");
									break;
								}
								else if (dynamic_cast<SWITCH*>(List[i]) != NULL)
								{
									SrcCmpnt = List[i];
									x1 = List[i]->getGraphicsInfo().x2;
									y1 = List[i]->getGraphicsInfo().y1 + 25;
									pOut->PrintMsg("you have clicked on SWITCH, click on distination gate");
									break;
								}
								else if (dynamic_cast<LED*>(List[i]) != NULL)
								{
									SrcCmpnt = List[i];
									source = 0;
									pOut->PrintMsg("you cant connect from led, click on distination gate");
									break;
								}
								else if (dynamic_cast<NOT*>(List[i]) != NULL)
								{
									SrcCmpnt = List[i];
									x1 = List[i]->getGraphicsInfo().x2;
									y1 = List[i]->getGraphicsInfo().y1 + 25;
									pOut->PrintMsg("you have clicked on NOT gate, click on distination gate");
									break;
								}
								else if (dynamic_cast<BUFFER*>(List[i]) != NULL)
								{
									SrcCmpnt = List[i];
									x1 = List[i]->getGraphicsInfo().x2;
									y1 = List[i]->getGraphicsInfo().y1 + 25;
									pOut->PrintMsg("you have clicked on BUFFER gate, click on distination gate");
									break;
								}
							}
						}
					}
				}
			}
		}
	}

	int move = 1;
	if (source == 0) {
		pOut->PrintMsg("you haven't clicked on a source, action aborted click to continue");
		move = 0;		//abort
		dist = 1;
	}
	//destination


	if (move == 1) {
		pIn->GetPointClicked(x, y);
		if (*List != NULL) {						// *list != null to prevent errors when user try to add connection when there is no connections
			for (int i = 0; i < pManager->GetCompCount(); i++) {		//200 for maximum 
				if (x > List[i]->getGraphicsInfo().x1 && x < List[i]->getGraphicsInfo().x2) {
					if (y > List[i]->getGraphicsInfo().y1 && y < List[i]->getGraphicsInfo().y2) {
						if (List[i]->Getis_deleted() == false)
						{
							if (dynamic_cast<White*>(List[i]) == NULL) {
								if (dynamic_cast<Connection*>(List[i]) == NULL) {
									dist = 1;
									if (dynamic_cast<AND2*>(List[i]) != NULL) {
										//pDstPin->setComponent(List[i]);					//sets the component of this input pin
										DstCmpnt = List[i];
										pOut->PrintMsg("you have clicked on AND2 gate, click to Execute");
										x2 = List[i]->getGraphicsInfo().x1;
										if (List[i]->gethas() == 0) {
											y2 = List[i]->getGraphicsInfo().y1 + 12.5;
											List[i]->sethas(1);
											break;
										}
										if (List[i]->gethas() == 1) {
											y2 = List[i]->getGraphicsInfo().y1 + 37.5;
											List[i]->sethas(2);
										}
										else
											dist = 0;
										break;
									}
									else if (dynamic_cast<OR2*>(List[i]) != NULL)
									{
										//pDstPin->setComponent(List[i]);
										DstCmpnt = List[i];
										pOut->PrintMsg("you have clicked on OR2 gate, click to Execute");
										x2 = List[i]->getGraphicsInfo().x1;
										if (List[i]->gethas() == 0) {
											y2 = List[i]->getGraphicsInfo().y1 + 14;
											List[i]->sethas(1);
											break;
										}
										if (List[i]->gethas() == 1) {
											y2 = List[i]->getGraphicsInfo().y1 + 36;
											List[i]->sethas(2);
										}
										else
											dist = 0;
										break;
									}
									else if (dynamic_cast<NAND2*>(List[i]) != NULL)
									{
										//pDstPin->setComponent(List[i]);
										DstCmpnt = List[i];
										pOut->PrintMsg("you have clicked on NAN2 gate, click to Execute");
										x2 = List[i]->getGraphicsInfo().x1;
										if (List[i]->gethas() == 0) {
											y2 = List[i]->getGraphicsInfo().y1 + 14;
											List[i]->sethas(1);
											break;
										}
										if (List[i]->gethas() == 1) {
											y2 = List[i]->getGraphicsInfo().y1 + 36;
											List[i]->sethas(2);
										}
										else
											dist = 0;
										break;
									}
									else if (dynamic_cast<NOR2*>(List[i]) != NULL)
									{
										//pDstPin->setComponent(List[i]);
										DstCmpnt = List[i];
										pOut->PrintMsg("you have clicked on NOR2 gate, click to Execute");
										x2 = List[i]->getGraphicsInfo().x1;
										if (List[i]->gethas() == 0) {
											y2 = List[i]->getGraphicsInfo().y1 + 18;
											List[i]->sethas(1);
											break;
										}
										if (List[i]->gethas() == 1) {
											y2 = List[i]->getGraphicsInfo().y1 + 37;
											List[i]->sethas(2);
										}
										else
											dist = 0;
										break;
									}
									else if (dynamic_cast<XOR2*>(List[i]) != NULL)
									{
										//pDstPin->setComponent(List[i]);
										DstCmpnt = List[i];
										pOut->PrintMsg("you have clicked on XOR2 gate, click to Execute");
										x2 = List[i]->getGraphicsInfo().x1;
										if (List[i]->gethas() == 0) {
											y2 = List[i]->getGraphicsInfo().y1 + 14;
											List[i]->sethas(1);
											break;
										}
										if (List[i]->gethas() == 1) {
											y2 = List[i]->getGraphicsInfo().y1 + 37;
											List[i]->sethas(2);
										}
										else
											dist = 0;
										break;
									}
									else if (dynamic_cast<XNOR2*>(List[i]) != NULL)
									{
										//pDstPin->setComponent(List[i]);
										DstCmpnt = List[i];
										pOut->PrintMsg("you have clicked on XNOR2 gate, click to Execute");
										x2 = List[i]->getGraphicsInfo().x1;
										if (List[i]->gethas() == 0) {
											y2 = List[i]->getGraphicsInfo().y1 + 14;
											List[i]->sethas(1);
											break;
										}
										if (List[i]->gethas() == 1) {
											y2 = List[i]->getGraphicsInfo().y1 + 37;
											List[i]->sethas(2);
										}
										else
											dist = 0;
										break;
									}
									else if (dynamic_cast<AND3*>(List[i]) != NULL)
									{
										//pDstPin->setComponent(List[i]);
										DstCmpnt = List[i];
										pOut->PrintMsg("you have clicked on AND3 gate, click to Execute");
										x2 = List[i]->getGraphicsInfo().x1;
										if (List[i]->gethas() == 0) {
											y2 = List[i]->getGraphicsInfo().y1 + 14;
											List[i]->sethas(1);
											break;
										}
										if (List[i]->gethas() == 1) {
											y2 = List[i]->getGraphicsInfo().y1 + 25;
											List[i]->sethas(2);
											break;
										}
										if (List[i]->gethas() == 2) {
											y2 = List[i]->getGraphicsInfo().y1 + 37;
											List[i]->sethas(3);
										}
										else
											dist = 0;
										break;
									}
									else if (dynamic_cast<NOR3*>(List[i]) != NULL)
									{
										//pDstPin->setComponent(List[i]);
										DstCmpnt = List[i];
										pOut->PrintMsg("you have clicked on NOR3 gate, click to Execute");
										x2 = List[i]->getGraphicsInfo().x1;
										if (List[i]->gethas() == 0) {
											y2 = List[i]->getGraphicsInfo().y1 + 14;
											List[i]->sethas(1);
											break;
										}
										if (List[i]->gethas() == 1) {
											y2 = List[i]->getGraphicsInfo().y1 + 25;
											List[i]->sethas(2);
											break;
										}
										if (List[i]->gethas() == 2) {
											y2 = List[i]->getGraphicsInfo().y1 + 37;
											List[i]->sethas(3);
										}
										else
											dist = 0;
										break;
									}
									else if (dynamic_cast<XOR3*>(List[i]) != NULL)
									{
										//pDstPin->setComponent(List[i]);
										DstCmpnt = List[i];
										pOut->PrintMsg("you have clicked on XOR3 gate, click to Execute");
										x2 = List[i]->getGraphicsInfo().x1;
										if (List[i]->gethas() == 0) {
											y2 = List[i]->getGraphicsInfo().y1 + 14;
											List[i]->sethas(1);
											break;
										}
										if (List[i]->gethas() == 1) {
											y2 = List[i]->getGraphicsInfo().y1 + 25;
											List[i]->sethas(2);
											break;
										}
										if (List[i]->gethas() == 2) {
											y2 = List[i]->getGraphicsInfo().y1 + 37;
											List[i]->sethas(3);
										}
										else
											dist = 0;
										break;
									}
									else if (dynamic_cast<NOT*>(List[i]) != NULL)
									{
										//pDstPin->setComponent(List[i]);
										DstCmpnt = List[i];
										pOut->PrintMsg("you have clicked on NOT gate, click to Execute");
										x2 = List[i]->getGraphicsInfo().x1;
										if (List[i]->gethas() == 0) {
											y2 = List[i]->getGraphicsInfo().y1 + 24;
											List[i]->sethas(1);
										}
										else
											dist = 0;
										break;
									}
									else if (dynamic_cast<BUFFER*>(List[i]) != NULL)
									{
										//pDstPin->setComponent(List[i]);
										DstCmpnt = List[i];
										pOut->PrintMsg("you have clicked on BUFFER gate, click to Execute");
										x2 = List[i]->getGraphicsInfo().x1;
										if (List[i]->gethas() == 0) {
											y2 = List[i]->getGraphicsInfo().y1 + 24;
											List[i]->sethas(1);
										}
										else
											dist = 0;
										break;
									}
									else if (dynamic_cast<LED*>(List[i]) != NULL)
									{
										//pDstPin->setComponent(List[i]);
										DstCmpnt = List[i];
										pOut->PrintMsg("you have clicked on LED, click to Execute");
										x2 = List[i]->getGraphicsInfo().x1;
										if (List[i]->gethas() == 0) {
											y2 = List[i]->getGraphicsInfo().y1 + 24;
											List[i]->sethas(1);
										}
										else
											dist = 0;
										break;
									}
									else if (dynamic_cast<SWITCH*>(List[i]) != NULL)
									{
										//pDstPin->setComponent(List[i]);
										DstCmpnt = List[i];
										pOut->PrintMsg("you have clicked on SWITCH, click to Execute");
										x2 = List[i]->getGraphicsInfo().x1;
										if (List[i]->gethas() == 0) {
											y2 = List[i]->getGraphicsInfo().y1 + 27;
											List[i]->sethas(1);
										}
										else
											dist = 0;
										break;
									}
								}
							}
						}
					}
				}
			}
		}
	}


	if(dist == 0)
		pOut->PrintMsg("action aborted click to continue");

	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();




	GInfo.x1 = x1;
	GInfo.x2 = x2;
	GInfo.y1 = y1;
	GInfo.y2 = y2;


	if (source == 1 && dist == 1) {
		Connection* pA = new Connection(GInfo, pSrcPin, pDstPin);	//Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin);
		pA->SetDistComp(DstCmpnt);
		pA->SetSourceComp(SrcCmpnt);

		//pSrcPin->ConnectTo(pA);											//Connects the ouput pin the the passed connection if the fan out permits
		pManager->AddComponent(pA);
		pManager->AddConnection(pA);
	}
}

void AddCONNECTION::Undo()
{}

void AddCONNECTION::Redo()
{}

