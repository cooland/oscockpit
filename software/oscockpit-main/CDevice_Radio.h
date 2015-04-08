#ifndef CDEVICE_RADIO_H
#define CDEVICE_RADIO_H

//(*Headers(CDevice_Radio)
#include <wx/panel.h>
#include <wx/dialog.h>
//*)

class CDevice_Radio: public wxDialog
{
	public:

		CDevice_Radio(wxWindow* parent);
		virtual ~CDevice_Radio();

		//(*Declarations(CDevice_Radio)
		wxPanel* Panel1;
		//*)

	protected:

		//(*Identifiers(CDevice_Radio)
		//*)

	private:

		//(*Handlers(CDevice_Radio)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
