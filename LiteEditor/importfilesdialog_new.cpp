//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "importfilesdialog_new.h"


// Declare the bitmap loading function
extern void wxC945BInitBitmapResources();

static bool bBitmapLoaded = false;


ImportFilesDialogNewBase::ImportFilesDialogNewBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC945BInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);
    
    m_banner1 = new wxBannerWindow(this, wxID_ANY, wxTOP, wxDefaultPosition, wxSize(-1,-1), wxBORDER_THEME);
    m_banner1->SetBitmap(wxNullBitmap);
    m_banner1->SetText(_("Import Files"), _("Select the directories to import from"));
    m_banner1->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION), wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    m_banner1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_CAPTIONTEXT));
    
    mainSizer->Add(m_banner1, 0, wxALL|wxEXPAND, 5);
    
    m_dirPicker = new wxDirPickerCtrl(this, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxSize(-1,-1), wxDIRP_DEFAULT_STYLE);
    m_dirPicker->SetToolTip(_("Select the base folder for importing"));
    
    mainSizer->Add(m_dirPicker, 0, wxALL|wxEXPAND, 5);
    
    m_dataview = new wxDataViewCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxDV_ROW_LINES|wxDV_SINGLE);
    m_dataview->SetToolTip(_("Check the folders you wish to import\nfiles from"));
    
    m_dataviewModel = new FolderModel;
    m_dataviewModel->SetColCount( 2 );
    m_dataview->AssociateModel(m_dataviewModel.get() );
    
    mainSizer->Add(m_dataview, 1, wxALL|wxEXPAND, 5);
    
    m_dataview->AppendIconTextColumn(_("Folder"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_INERT, 300, wxALIGN_LEFT);
    m_dataview->AppendToggleColumn(_("Import?"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_ACTIVATABLE, 80, wxALIGN_LEFT);
    m_staticText1 = new wxStaticText(this, wxID_ANY, _("Files extension to import:"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    mainSizer->Add(m_staticText1, 0, wxALL|wxEXPAND, 5);
    
    m_textCtrSpec = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    
    mainSizer->Add(m_textCtrSpec, 0, wxALL|wxEXPAND, 5);
    
    m_checkBoxFilesWOExt = new wxCheckBox(this, wxID_ANY, _("Import files without extensions"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_checkBoxFilesWOExt->SetValue(false);
    m_checkBoxFilesWOExt->SetToolTip(_("If you wish to import files without extensions, tick this option"));
    
    mainSizer->Add(m_checkBoxFilesWOExt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxLI_HORIZONTAL);
    
    mainSizer->Add(m_staticline1, 0, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    
    mainSizer->Add(buttonSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_buttonOk = new wxButton(this, wxID_OK, _("&Ok"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_buttonOk->SetDefault();
    
    buttonSizer->Add(m_buttonOk, 0, wxALL, 5);
    
    m_buttonCancel = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    buttonSizer->Add(m_buttonCancel, 0, wxALL, 5);
    
    
    SetSizeHints(400,400);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_dirPicker->Connect(wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler(ImportFilesDialogNewBase::OnDirChanged), NULL, this);
    m_dataview->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_VALUE_CHANGED, wxDataViewEventHandler(ImportFilesDialogNewBase::OnValueChanged), NULL, this);
    m_dataview->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_EXPANDING, wxDataViewEventHandler(ImportFilesDialogNewBase::OnItemExpanding), NULL, this);
    
}

ImportFilesDialogNewBase::~ImportFilesDialogNewBase()
{
    m_dirPicker->Disconnect(wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler(ImportFilesDialogNewBase::OnDirChanged), NULL, this);
    m_dataview->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_VALUE_CHANGED, wxDataViewEventHandler(ImportFilesDialogNewBase::OnValueChanged), NULL, this);
    m_dataview->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_EXPANDING, wxDataViewEventHandler(ImportFilesDialogNewBase::OnItemExpanding), NULL, this);
    
}
