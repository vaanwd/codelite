//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : symbols_dialog.h
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#ifndef __symbols_dialog__
#define __symbols_dialog__

/**
@file
Subclass of SymbolsDialogBase, which is generated by wxFormBuilder.
@todo Add your event handlers directly to this file.
*/

#include "symbols_dialog_base.h"
#include "database/entry.h"

#include <vector>

/** Implementing SymbolsDialogBase */
class SymbolsDialog : public SymbolsDialogBase
{
    std::vector<TagEntryPtr> m_tags;
    TagEntryPtr m_tag;
    long m_line;
    wxString m_file;
    wxString m_pattern;
    long m_selectedItem;

public:
    /** Constructor */
    SymbolsDialog(wxWindow* parent);
    virtual ~SymbolsDialog();

    /**
     * Add symbol to the dialog - this should be called before calling the dialog
     * ShowModal() method
     * \param tag tag to add
     * \param sel when set to true, this item will be selected
     */
    void AddSymbol(const TagEntryPtr& tag, bool sel);

    /**
     * A wrapper around the AddSymbol methos that allows
     * adding a vector of tags
     * \param tags
     * \param sel zero based index to select
     */
    void AddSymbols(const std::vector<TagEntryPtr>& tags, size_t sel);

    //---------------------------------------------
    // Getters
    //---------------------------------------------
    const wxString& GetFile() const { return m_file; }
    long GetLine() const { return m_line; }
    const wxString& GetPattern() const { return m_pattern; }
    TagEntryPtr GetTag() { return m_tag; }

private:
    void UpdateFileAndLine(wxListEvent& event);

    //-----------------------------------------------
    // Event handlers
    //-----------------------------------------------
    void OnItemSelected(wxListEvent& event);
    void OnItemActivated(wxListEvent& event);
    void OnButtonCancel(wxCommandEvent& event);
    void OnButtonOK(wxCommandEvent& event);
    void OnCharHook(wxKeyEvent& event);
    void OnItemDeselected(wxListEvent& event);

    DECLARE_EVENT_TABLE()
};

#endif // __symbols_dialog__
