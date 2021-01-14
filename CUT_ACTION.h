#ifndef _CUT_ACTION_H
#define _CUT_ACTION_H

#include "Actions/Action.h"
#include "White.h"
#include "Connection_w.h"
class CUT_ACTION : public Action
{
private:
	int x, y;
public:
	CUT_ACTION(ApplicationManager* pApp);
	virtual ~CUT_ACTION(void);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif