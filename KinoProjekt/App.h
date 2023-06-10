#pragma once
#include <wx/wx.h>
#include "DatabaseManager.h"

class App :public wxApp
{
public:
	bool OnInit();
	int OnExit();
};

extern DatabaseManager* dbManager;