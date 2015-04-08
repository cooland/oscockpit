/***************************************************************
 * Name:      hidtestwinMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    cooland (cooland1@yandex.ru)
 * Created:   2015-03-31
 * Copyright: cooland (none)
 * License:
 **************************************************************/

#include "hidtestwinMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(hidtestwinDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(hidtestwinDialog)
const long hidtestwinDialog::ID_CHECKBOX_LED1 = wxNewId();
const long hidtestwinDialog::ID_CHECKBOX_LED2 = wxNewId();
const long hidtestwinDialog::ID_CHECKBOX_LED3 = wxNewId();
const long hidtestwinDialog::ID_CHECKBOX_LED4 = wxNewId();
const long hidtestwinDialog::ID_STATICTEXT1 = wxNewId();
const long hidtestwinDialog::ID_TEXTCTRL_STATUS = wxNewId();
const long hidtestwinDialog::ID_BUTTON_RECONNECT = wxNewId();
const long hidtestwinDialog::ID_BUTTON_STATUS = wxNewId();
const long hidtestwinDialog::ID_BUTTON1 = wxNewId();
const long hidtestwinDialog::ID_STATICLINE1 = wxNewId();
const long hidtestwinDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(hidtestwinDialog,wxDialog)
    //(*EventTable(hidtestwinDialog)
    //*)
END_EVENT_TABLE()

hidtestwinDialog::hidtestwinDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(hidtestwinDialog)
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, id, _("USB LEDS Example"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("LEDS"));
    FlexGridSizer1 = new wxFlexGridSizer(4, 4, 0, 0);
    LED1 = new wxCheckBox(this, ID_CHECKBOX_LED1, _("LED1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_LED1"));
    LED1->SetValue(false);
    FlexGridSizer1->Add(LED1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LED2 = new wxCheckBox(this, ID_CHECKBOX_LED2, _("LED2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_LED2"));
    LED2->SetValue(false);
    FlexGridSizer1->Add(LED2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LED3 = new wxCheckBox(this, ID_CHECKBOX_LED3, _("LED3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_LED3"));
    LED3->SetValue(false);
    FlexGridSizer1->Add(LED3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LED4 = new wxCheckBox(this, ID_CHECKBOX_LED4, _("LED4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_LED4"));
    LED4->SetValue(false);
    FlexGridSizer1->Add(LED4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Status"), wxDefaultPosition, wxSize(36,11), 0, _T("ID_STATICTEXT1"));
    StaticBoxSizer1->Add(StaticText1, 1, wxALL|wxEXPAND|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    statusText = new wxTextCtrl(this, ID_TEXTCTRL_STATUS, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_STATUS"));
    statusText->SetMaxLength(50);
    statusText->Disable();
    StaticBoxSizer1->Add(statusText, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    b_Reconnect = new wxButton(this, ID_BUTTON_RECONNECT, _("Reconnect"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RECONNECT"));
    BoxSizer2->Add(b_Reconnect, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    b_Status = new wxButton(this, ID_BUTTON_STATUS, _("Read Status"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_STATUS"));
    BoxSizer2->Add(b_Status, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("About"), wxDefaultPosition, wxSize(84,20), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(84,1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button2 = new wxButton(this, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxSize(75,24), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 4);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_CHECKBOX_LED1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&hidtestwinDialog::OnLED1Click);
    Connect(ID_CHECKBOX_LED2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&hidtestwinDialog::OnLED2Click);
    Connect(ID_CHECKBOX_LED3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&hidtestwinDialog::OnLED3Click);
    Connect(ID_CHECKBOX_LED4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&hidtestwinDialog::OnLED4Click);
    Connect(ID_BUTTON_RECONNECT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&hidtestwinDialog::Onb_ReconnectClick);
    Connect(ID_BUTTON_STATUS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&hidtestwinDialog::Onb_StatusClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&hidtestwinDialog::OnAbout);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&hidtestwinDialog::OnQuit);
    //*)
    hid= new HIDContext();
    Init();
}

hidtestwinDialog::~hidtestwinDialog()
{
    //(*Destroy(hidtestwinDialog)
    //*)
}

void hidtestwinDialog::OnQuit(wxCommandEvent& event)
{
    if (handle!=NULL){
        hid_close(handle);
        hid_exit();
    }
    Close();
}

void hidtestwinDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

bool hidtestwinDialog::USBConnect(){

    if (!handle){
        handle=hid_open(0x27d9,0x16c0,L"9088a05a-bc89-4c60-9c2a-4d80e86a385d");
        if (!handle){
            statusText->SetValue("Unable to open device 0x27d9 0x16c0");
            return false;
        }
        hid_set_nonblocking(handle,true);
        statusText->SetValue("Device connected");
    }
    return true;
}

void hidtestwinDialog::Init()
{
    if (!hid_init()==0){
        statusText->SetValue("Error init USB");
        return ;
    }

    USBConnect();
}

void hidtestwinDialog::Onb_ReconnectClick(wxCommandEvent& event)
{
    if (handle!=NULL){
        hid_close(handle);
    }
    USBConnect();
}

void hidtestwinDialog::OnLED1Click(wxCommandEvent& event)
{
    unsigned char buf[65];
    int res;

    if (handle!=NULL){
        if (LED1->IsChecked()){
            buf[0]=0x0;
            buf[1]=0x80;
        }else{
            buf[0]=0x0;
            buf[1]=0x81;
        }
        res=hid_write(handle,buf,65);
        if (res<0){
            wxString tmp="Unable to write()";
            tmp.append(hid_error(handle));
            statusText->SetValue(tmp);
        }
    }else{
        statusText->SetValue("Not connected");
    }
}

void hidtestwinDialog::OnLED2Click(wxCommandEvent& event)
{
     unsigned char buf[65];
    int res;

    if (handle!=NULL){
        if (LED2->IsChecked()){
            buf[0]=0x0;
            buf[1]=0x82;
        }else{
            buf[0]=0x0;
            buf[1]=0x83;
        }
        res=hid_write(handle,buf,65);
        if (res<0){
            wxString tmp="Unable to write()";
            tmp.append(hid_error(handle));
            statusText->SetValue(tmp);
        }
    }else{
        statusText->SetValue("Not connected");
    }
}

void hidtestwinDialog::OnLED3Click(wxCommandEvent& event)
{
     unsigned char buf[65];
    int res;

    if (handle!=NULL){
        if (LED3->IsChecked()){
            buf[0]=0x0;
            buf[1]=0x84;
        }else{
            buf[0]=0x0;
            buf[1]=0x85;
        }
        res=hid_write(handle,buf,65);
        if (res<0){
            wxString tmp="Unable to write()";
            tmp.append(hid_error(handle));
            statusText->SetValue(tmp);
        }
    }else{
        statusText->SetValue("Not connected");
    }
}

void hidtestwinDialog::OnLED4Click(wxCommandEvent& event)
{
     unsigned char buf[65];
    int res;

    if (handle!=NULL){
        if (LED4->IsChecked()){
            buf[0]=0x0;
            buf[1]=0x86;
        }else{
            buf[0]=0x0;
            buf[1]=0x87;
        }
        res=hid_write(handle,buf,65);
        if (res<0){
            wxString tmp="Unable to write()";
            tmp.append(hid_error(handle));
            statusText->SetValue(tmp);
        }
    }else{
        statusText->SetValue("Not connected");
    }
}

void hidtestwinDialog::Onb_StatusClick(wxCommandEvent& event)
{
    if (handle==NULL){
        statusText->SetValue("Not connected");
        return;
    }

    //request
    unsigned char buf[65];
    int res;
    buf[0]=0x0;
    buf[1]=0x90;
    res=hid_write(handle,buf,65);
    if (res<0){
        statusText->SetValue("Error requesting status from USB");
        return;
    }
    //read response for non-blocking
    res=0;
    while(res==0){
        res=hid_read(handle, buf, sizeof(buf));
        if (res==0){
            statusText->SetValue("Waiting ...");
        }
        if (res<0){
            statusText->SetValue("Unable to read");
        }
        Sleep(500);//sleep 500ms
    }
    wxString tmp="Data: ";

    for (int i=0;i<res;i++){

        tmp.Append(wxString::Format(wxT("%02hx"),buf[i]));
    }
    statusText->SetValue(tmp);
}
