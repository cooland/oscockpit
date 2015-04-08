#include "CDevice_Radio.h"

//(*InternalHeaders(CDevice_Radio)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(CDevice_Radio)
//*)

BEGIN_EVENT_TABLE(CDevice_Radio,wxDialog)
	//(*EventTable(CDevice_Radio)
	//*)
END_EVENT_TABLE()

CDevice_Radio::CDevice_Radio(wxWindow* parent)
{
	//(*Initialize(CDevice_Radio)
	wxXmlResource::Get()->LoadObject(this,parent,_T("CDevice_Radio"),_T("wxDialog"));
	Panel1 = (wxPanel*)FindWindow(XRCID("ID_PANEL1"));
	//*)
}

CDevice_Radio::~CDevice_Radio()
{
	//(*Destroy(CDevice_Radio)
	//*)
}

