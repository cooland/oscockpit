/***************************************************************
 * Name:      hidtestwinApp.cpp
 * Purpose:   Code for Application Class
 * Author:    cooland (cooland1@yandex.ru)
 * Created:   2015-03-31
 * Copyright: cooland (none)
 * License:
 **************************************************************/

#include "hidtestwinApp.h"

//(*AppHeaders
#include "hidtestwinMain.h"
#include <wx/xrc/xmlres.h>
#include <wx/image.h>
//*)

IMPLEMENT_APP(hidtestwinApp);

bool hidtestwinApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    wxXmlResource::Get()->InitAllHandlers();
    wxsOK = wxsOK && wxXmlResource::Get()->Load(_T("Device_Radio.xrc"));
    if ( wxsOK )
    {
    	hidtestwinDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
