/***************************************************************
 * Name:      hidtestwinMain.h
 * Purpose:   Defines Application Frame
 * Author:    cooland (cooland1@yandex.ru)
 * Created:   2015-03-31
 * Copyright: cooland (none)
 * License:
 **************************************************************/

#ifndef HIDTESTWINMAIN_H
#define HIDTESTWINMAIN_H

//(*Headers(hidtestwinDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#include "HIDContext.h"


class hidtestwinDialog: public wxDialog
{
    public:

        hidtestwinDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~hidtestwinDialog();
    protected:
        void  Init();
        bool  USBConnect();

    private:

        HIDContext *hid;
        hid_device *handle;
        //(*Handlers(hidtestwinDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void Onb_ReconnectClick(wxCommandEvent& event);
        void OnLED1Click(wxCommandEvent& event);
        void OnLED2Click(wxCommandEvent& event);
        void OnLED3Click(wxCommandEvent& event);
        void OnLED4Click(wxCommandEvent& event);
        void Onb_StatusClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(hidtestwinDialog)
        static const long ID_CHECKBOX_LED1;
        static const long ID_CHECKBOX_LED2;
        static const long ID_CHECKBOX_LED3;
        static const long ID_CHECKBOX_LED4;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL_STATUS;
        static const long ID_BUTTON_RECONNECT;
        static const long ID_BUTTON_STATUS;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(hidtestwinDialog)
        wxTextCtrl* statusText;
        wxCheckBox* LED4;
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button2;
        wxCheckBox* LED1;
        wxStaticLine* StaticLine1;
        wxCheckBox* LED3;
        wxBoxSizer* BoxSizer1;
        wxCheckBox* LED2;
        wxButton* b_Status;
        wxFlexGridSizer* FlexGridSizer1;
        wxButton* b_Reconnect;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // HIDTESTWINMAIN_H
