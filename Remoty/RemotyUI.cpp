//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: RemotyUI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "RemotyUI.h"

// Declare the bitmap loading function
extern void wxCrafterjtvK2XInitBitmapResources();

static bool bBitmapLoaded = false;

RemotyWorkspaceViewBase::RemotyWorkspaceViewBase(wxWindow* parent, wxWindowID id, const wxPoint& pos,
                                                 const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterjtvK2XInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer3 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer3);

    SetName(wxT("RemotyWorkspaceViewBase"));
    SetSize(wxDLG_UNIT(this, wxSize(500, 300)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
}

RemotyWorkspaceViewBase::~RemotyWorkspaceViewBase() {}

RemotySwitchToWorkspaceDlgBase::RemotySwitchToWorkspaceDlgBase(wxWindow* parent, wxWindowID id, const wxString& title,
                                                               const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterjtvK2XInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer7 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer7);

    wxFlexGridSizer* flexGridSizer15 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer15->SetFlexibleDirection(wxBOTH);
    flexGridSizer15->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer15->AddGrowableCol(1);

    boxSizer7->Add(flexGridSizer15, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText77 =
        new wxStaticText(this, wxID_ANY, _("Workspace type:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer15->Add(m_staticText77, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxArrayString m_choiceWorkspaceTypeArr;
    m_choiceWorkspaceTypeArr.Add(_("Local"));
    m_choiceWorkspaceTypeArr.Add(_("Remote"));
    m_choiceWorkspaceType =
        new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceWorkspaceTypeArr, 0);
    m_choiceWorkspaceType->SetSelection(0);

    flexGridSizer15->Add(m_choiceWorkspaceType, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    flexGridSizer15->Add(0, 0, 1, wxALL, WXC_FROM_DIP(5));

    m_staticText75 =
        new wxStaticText(this, wxID_ANY, _("Path:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer15->Add(m_staticText75, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxArrayString m_comboBoxPathArr;
    m_comboBoxPath = new wxComboBox(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(250, -1)),
                                    m_comboBoxPathArr, 0);
    m_comboBoxPath->SetFocus();
#if wxVERSION_NUMBER >= 3000
    m_comboBoxPath->SetHint(wxT(""));
#endif

    flexGridSizer15->Add(m_comboBoxPath, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_button29 = new wxButton(this, wxID_ANY, _("Browse..."), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer15->Add(m_button29, 0, wxALL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_staticText81 =
        new wxStaticText(this, wxID_ANY, _("Account:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer15->Add(m_staticText81, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    wxArrayString m_choiceAccountArr;
    m_choiceAccount =
        new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), m_choiceAccountArr, 0);

    flexGridSizer15->Add(m_choiceAccount, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_stdBtnSizer9 = new wxStdDialogButtonSizer();

    boxSizer7->Add(m_stdBtnSizer9, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(10));

    m_button11 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button11->SetDefault();
    m_stdBtnSizer9->AddButton(m_button11);

    m_button13 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer9->AddButton(m_button13);
    m_stdBtnSizer9->Realize();

    SetName(wxT("RemotySwitchToWorkspaceDlgBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_choiceWorkspaceType->Connect(wxEVT_COMMAND_CHOICE_SELECTED,
                                   wxCommandEventHandler(RemotySwitchToWorkspaceDlgBase::OnChoiceWorkspaceType), NULL,
                                   this);
    m_comboBoxPath->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED,
                            wxCommandEventHandler(RemotySwitchToWorkspaceDlgBase::OnPathChanged), NULL, this);
    m_button29->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RemotySwitchToWorkspaceDlgBase::OnBrowse),
                        NULL, this);
    m_staticText81->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(RemotySwitchToWorkspaceDlgBase::OnRemoteUI), NULL,
                            this);
    m_choiceAccount->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(RemotySwitchToWorkspaceDlgBase::OnRemoteUI), NULL,
                             this);
    m_button11->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(RemotySwitchToWorkspaceDlgBase::OnOKUI), NULL, this);
}

RemotySwitchToWorkspaceDlgBase::~RemotySwitchToWorkspaceDlgBase()
{
    m_choiceWorkspaceType->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED,
                                      wxCommandEventHandler(RemotySwitchToWorkspaceDlgBase::OnChoiceWorkspaceType),
                                      NULL, this);
    m_comboBoxPath->Disconnect(wxEVT_COMMAND_COMBOBOX_SELECTED,
                               wxCommandEventHandler(RemotySwitchToWorkspaceDlgBase::OnPathChanged), NULL, this);
    m_button29->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                           wxCommandEventHandler(RemotySwitchToWorkspaceDlgBase::OnBrowse), NULL, this);
    m_staticText81->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(RemotySwitchToWorkspaceDlgBase::OnRemoteUI),
                               NULL, this);
    m_choiceAccount->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(RemotySwitchToWorkspaceDlgBase::OnRemoteUI),
                                NULL, this);
    m_button11->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(RemotySwitchToWorkspaceDlgBase::OnOKUI), NULL, this);
}

RemotyNewWorkspaceDlgBase::RemotyNewWorkspaceDlgBase(wxWindow* parent, wxWindowID id, const wxString& title,
                                                     const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterjtvK2XInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer35 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer35);

    wxFlexGridSizer* flexGridSizer43 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer43->SetFlexibleDirection(wxBOTH);
    flexGridSizer43->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer43->AddGrowableCol(1);

    boxSizer35->Add(flexGridSizer43, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText45 =
        new wxStaticText(this, wxID_ANY, _("Path:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer43->Add(m_staticText45, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlPath = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(250, -1)), 0);
    m_textCtrlPath->SetFocus();
#if wxVERSION_NUMBER >= 3000
    m_textCtrlPath->SetHint(wxT(""));
#endif

    flexGridSizer43->Add(m_textCtrlPath, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_button49 = new wxButton(this, wxID_ANY, _("Browse..."), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer43->Add(m_button49, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText59 =
        new wxStaticText(this, wxID_ANY, _("Workspace name:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer43->Add(m_staticText59, 0, wxALL | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlName = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_textCtrlName->SetHint(wxT(""));
#endif

    flexGridSizer43->Add(m_textCtrlName, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_stdBtnSizer37 = new wxStdDialogButtonSizer();

    boxSizer35->Add(m_stdBtnSizer37, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(10));

    m_button39 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer37->AddButton(m_button39);

    m_button41 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button41->SetDefault();
    m_stdBtnSizer37->AddButton(m_button41);
    m_stdBtnSizer37->Realize();

    SetName(wxT("RemotyNewWorkspaceDlgBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_button49->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RemotyNewWorkspaceDlgBase::OnBrowse), NULL,
                        this);
    m_button41->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(RemotyNewWorkspaceDlgBase::OnOKUI), NULL, this);
}

RemotyNewWorkspaceDlgBase::~RemotyNewWorkspaceDlgBase()
{
    m_button49->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(RemotyNewWorkspaceDlgBase::OnBrowse),
                           NULL, this);
    m_button41->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(RemotyNewWorkspaceDlgBase::OnOKUI), NULL, this);
}
