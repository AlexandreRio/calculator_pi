///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "calculatorgui.h"

///////////////////////////////////////////////////////////////////////////

DlgDef::DlgDef( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	m_Overview = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );
	
	m_result = new wxTextCtrl( m_Overview, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 420,40 ), wxTE_PROCESS_ENTER );
	m_result->SetMaxLength( 0 ); 
	m_result->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	m_result->SetMinSize( wxSize( 200,40 ) );
	m_result->SetMaxSize( wxSize( -1,40 ) );
	
	bSizer41->Add( m_result, 8, wxALL|wxEXPAND, 5 );
	
	Calculate = new wxButton( m_Overview, wxID_ANY, _("Calculate"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	Calculate->SetMinSize( wxSize( 80,30 ) );
	Calculate->SetMaxSize( wxSize( 80,40 ) );
	
	bSizer41->Add( Calculate, 0, wxALL|wxEXPAND, 5 );
	
	m_Help = new wxCheckBox( m_Overview, wxID_ANY, _("History"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( m_Help, 0, wxALL|wxEXPAND, 5 );
	
	m_HelpButton = new wxButton( m_Overview, wxID_ANY, _("?"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( m_HelpButton, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer45->Add( bSizer41, 0, wxEXPAND, 5 );
	
	wxBoxSizer* HelpPanel;
	HelpPanel = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl = new wxListCtrl( m_Overview, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_AUTOARRANGE|wxLC_LIST|wxLC_SINGLE_SEL );
	m_listCtrl->Hide();
	
	HelpPanel->Add( m_listCtrl, 3, wxALL|wxEXPAND, 5 );
	
	
	bSizer45->Add( HelpPanel, 1, wxEXPAND, 5 );
	
	
	m_Overview->SetSizer( bSizer45 );
	m_Overview->Layout();
	bSizer45->Fit( m_Overview );
	bSizer7->Add( m_Overview, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer7 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_result->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( DlgDef::key_shortcut ), NULL, this );
	m_result->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( DlgDef::OnCalculate ), NULL, this );
	Calculate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnCalculate ), NULL, this );
	m_Help->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DlgDef::OnToggle ), NULL, this );
	m_HelpButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnHelp ), NULL, this );
}

DlgDef::~DlgDef()
{
	// Disconnect Events
	m_result->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( DlgDef::key_shortcut ), NULL, this );
	m_result->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( DlgDef::OnCalculate ), NULL, this );
	Calculate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnCalculate ), NULL, this );
	m_Help->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DlgDef::OnToggle ), NULL, this );
	m_HelpButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnHelp ), NULL, this );
	
}

CfgDlgDef::CfgDlgDef( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Show/Hide Buttons") ), wxVERTICAL );
	
	m_showhelpB = new wxCheckBox( this, wxID_ANY, _("Help Button"), wxDefaultPosition, wxDefaultSize, 0 );
	m_showhelpB->SetToolTip( _("Show/Hide help button (you can always type \"help\" from input window).") );
	
	sbSizer3->Add( m_showhelpB, 0, wxALL, 5 );
	
	m_showhistoryB = new wxCheckBox( this, wxID_ANY, _("History Toggle"), wxDefaultPosition, wxDefaultSize, 0 );
	m_showhistoryB->SetValue(true); 
	m_showhistoryB->SetToolTip( _("Show/Hide history toggle (you can always type \"history\" from input window).") );
	
	sbSizer3->Add( m_showhistoryB, 0, wxALL, 5 );
	
	m_CalculateB = new wxCheckBox( this, wxID_ANY, _("Calculate Button"), wxDefaultPosition, wxDefaultSize, 0 );
	m_CalculateB->SetValue(true); 
	m_CalculateB->SetToolTip( _("Show/Hide Calculate button (you can always press enter at the end of input).") );
	
	sbSizer3->Add( m_CalculateB, 0, wxALL, 5 );
	
	
	bSizer2->Add( sbSizer3, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("History Settings") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_Font_Size_txt = new wxStaticText( this, wxID_ANY, _("Max Results"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Font_Size_txt->Wrap( -1 );
	m_Font_Size_txt->SetToolTip( _("More results use up more memory. Memory is only allocated if required (e.g. if number is 30000, corresponding memory will only be used after this many calculations).") );
	
	fgSizer3->Add( m_Font_Size_txt, 0, wxALL, 5 );
	
	m_MaxResults = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 30000, 30000 );
	m_MaxResults->SetToolTip( _("More results use more memory. Memory will be cleared if Max Results is reached. NB variables are kept") );
	
	fgSizer3->Add( m_MaxResults, 0, wxALL, 5 );
	
	
	sbSizer4->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, _("Opacity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	m_staticText17->Hide();
	
	sbSizer4->Add( m_staticText17, 0, wxALL, 5 );
	
	m_sOpacity = new wxSlider( this, wxID_ANY, 50, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_sOpacity->Hide();
	
	sbSizer4->Add( m_sOpacity, 0, wxALL|wxEXPAND, 5 );
	
	m_showhistory = new wxCheckBox( this, wxID_ANY, _("Show History Window"), wxDefaultPosition, wxDefaultSize, 0 );
	m_showhistory->SetToolTip( _("Show/Hide history") );
	
	sbSizer4->Add( m_showhistory, 0, wxALL, 5 );
	
	m_capturehidden = new wxCheckBox( this, wxID_ANY, _("Capture when Hidden"), wxDefaultPosition, wxDefaultSize, 0 );
	m_capturehidden->SetValue(true); 
	m_capturehidden->SetToolTip( _("Capture results in history, even when the history box is hidden. Uncheck this box to save some memory when history is hidden.") );
	
	sbSizer4->Add( m_capturehidden, 0, wxALL, 5 );
	
	
	bSizer2->Add( sbSizer4, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer41;
	sbSizer41 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Other") ), wxVERTICAL );
	
	m_logresults = new wxCheckBox( this, wxID_ANY, _("Log results to opencpn"), wxDefaultPosition, wxDefaultSize, 0 );
	m_logresults->SetToolTip( _("Log calculator results in OpenCPN log file") );
	
	sbSizer41->Add( m_logresults, 0, wxALL, 5 );
	
	
	bSizer2->Add( sbSizer41, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	
	bSizer1->Add( m_sdbSizer1, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
}

CfgDlgDef::~CfgDlgDef()
{
}