#ifndef _mDELETE_ACTION_H
#define _mDELETE_ACTION_H

#include "Actions/Action.h"
#include "White.h"
#include "Connection_w.h"
class mDELETE_ACTION : public Action
{
public:
	mDELETE_ACTION(ApplicationManager* pApp);
	virtual ~mDELETE_ACTION(void);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif