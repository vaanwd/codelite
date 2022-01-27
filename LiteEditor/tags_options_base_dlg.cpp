//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: tags_options_base_dlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "tags_options_base_dlg.h"

#include "tags_options_data.h"

// Declare the bitmap loading function
extern void wxC6B32InitBitmapResources();

static bool bBitmapLoaded = false;

TagsOptionsBaseDlg::TagsOptionsBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
                                       const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC6B32InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer100 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer100);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    boxSizer100->Add(mainSizer, 1, wxALL | wxEXPAND, WXC_FROM_DIP(0));

    wxStaticBoxSizer* staticBoxSizer133 =
        new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Options")), wxVERTICAL);

    mainSizer->Add(staticBoxSizer133, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer12 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer12->SetFlexibleDirection(wxBOTH);
    flexGridSizer12->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer12->AddGrowableCol(1);

    staticBoxSizer133->Add(flexGridSizer12, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText14 = new wxStaticText(this, wxID_ANY, _("Number of items to display in the completion box:"),
                                      wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer12->Add(m_staticText14, 0, wxLEFT | wxRIGHT | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL,
                         WXC_FROM_DIP(5));

    m_spinCtrlNumberOfCCItems =
        new wxTextCtrl(this, wxID_ANY, wxT("50"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
#if wxVERSION_NUMBER >= 3000
    m_spinCtrlNumberOfCCItems->SetHint(wxT(""));
#endif

    flexGridSizer12->Add(m_spinCtrlNumberOfCCItems, 0, wxALL | wxEXPAND | wxALIGN_LEFT, WXC_FROM_DIP(5));

    wxFlexGridSizer* flexGridSizer127 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer127->SetFlexibleDirection(wxBOTH);
    flexGridSizer127->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

    staticBoxSizer133->Add(flexGridSizer127, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_checkDisplayTypeInfo = new wxCheckBox(this, wxID_ANY, _("Display type info tooltips"), wxDefaultPosition,
                                            wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkDisplayTypeInfo->SetValue(false);
    m_checkDisplayTypeInfo->SetToolTip(_("Display information about the hovered text"));

    flexGridSizer127->Add(m_checkDisplayTypeInfo, 0, wxALL | wxALIGN_LEFT, WXC_FROM_DIP(5));

    m_checkDisplayFunctionTip = new wxCheckBox(this, wxID_ANY, _("Display function calltip"), wxDefaultPosition,
                                               wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkDisplayFunctionTip->SetValue(false);
    m_checkDisplayFunctionTip->SetToolTip(_("Display function argument list after typing an open brace '('"));

    flexGridSizer127->Add(m_checkDisplayFunctionTip, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBoxBackspaceTriggers = new wxCheckBox(this, wxID_ANY, _("BACKSPACE triggers code completion"),
                                                 wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBoxBackspaceTriggers->SetValue(false);
    m_checkBoxBackspaceTriggers->SetToolTip(
        _("Deleting character will cause CodeLite to re-trigger the code completion"));

    flexGridSizer127->Add(m_checkBoxBackspaceTriggers, 0, wxALL, WXC_FROM_DIP(5));

    m_checkBoxGenCompileCommandsJSON = new wxCheckBox(this, wxID_ANY, _("Generate compile_commands.json file"),
                                                      wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkBoxGenCompileCommandsJSON->SetValue(false);

    flexGridSizer127->Add(m_checkBoxGenCompileCommandsJSON, 0, wxALL, WXC_FROM_DIP(5));

    wxStaticBoxSizer* sbSizer7 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("Triggering")), wxVERTICAL);

    mainSizer->Add(sbSizer7, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxFlexGridSizer* fgSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
    fgSizer4->SetFlexibleDirection(wxBOTH);
    fgSizer4->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    fgSizer4->AddGrowableCol(1);

    sbSizer7->Add(fgSizer4, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticTextMinWordLen = new wxStaticText(this, wxID_ANY, _("Minimum chars to type:"), wxDefaultPosition,
                                              wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_staticTextMinWordLen->SetToolTip(
        _("The minimum number of characters to type in order for CodeLite\nto trigger code completion"));

    fgSizer4->Add(m_staticTextMinWordLen, 0, wxALL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_sliderMinWordLen = new wxSlider(this, wxID_ANY, 3, 1, 10, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)),
                                      wxSL_LABELS | wxSL_AUTOTICKS | wxSL_HORIZONTAL);
    m_sliderMinWordLen->SetToolTip(_("Number of chars to type before showing the code completion box"));

    fgSizer4->Add(m_sliderMinWordLen, 0, wxEXPAND | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_checkAutoInsertSingleChoice = new wxCheckBox(this, wxID_ANY, _("Auto insert single match"), wxDefaultPosition,
                                                   wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_checkAutoInsertSingleChoice->SetValue(true);
    m_checkAutoInsertSingleChoice->SetToolTip(
        _("When there is only a single match don't show the code completion box but rather insert the match"));

    fgSizer4->Add(m_checkAutoInsertSingleChoice, 0, wxALL, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer102 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer100->Add(boxSizer102, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_button104 = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button104->SetDefault();

    boxSizer102->Add(m_button104, 0, wxALL, WXC_FROM_DIP(5));

    m_button106 = new wxButton(this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer102->Add(m_button106, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("TagsOptionsBaseDlg"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
    // Connect events
    m_staticTextMinWordLen->Bind(wxEVT_UPDATE_UI, &TagsOptionsBaseDlg::OnAutoShowWordAssitUI, this);
    m_sliderMinWordLen->Bind(wxEVT_UPDATE_UI, &TagsOptionsBaseDlg::OnAutoShowWordAssitUI, this);
    m_button104->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TagsOptionsBaseDlg::OnButtonOk, this);
    m_button106->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TagsOptionsBaseDlg::OnButtonCancel, this);
}

TagsOptionsBaseDlg::~TagsOptionsBaseDlg()
{
    m_staticTextMinWordLen->Unbind(wxEVT_UPDATE_UI, &TagsOptionsBaseDlg::OnAutoShowWordAssitUI, this);
    m_sliderMinWordLen->Unbind(wxEVT_UPDATE_UI, &TagsOptionsBaseDlg::OnAutoShowWordAssitUI, this);
    m_button104->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &TagsOptionsBaseDlg::OnButtonOk, this);
    m_button106->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &TagsOptionsBaseDlg::OnButtonCancel, this);
}
