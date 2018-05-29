/***************************************************************
 * Name:      visualizatorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Dudenkov Vladimir ()
 * Created:   2018-05-22
 * Copyright: Dudenkov Vladimir ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "visualizatorMain.h"
#include <wx/msgdlg.h>
#include <vector>
#include <string>

//(*InternalHeaders(visualizatorFrame)
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

//(*IdInit(visualizatorFrame)
const long visualizatorFrame::ID_BUTTONFILE = wxNewId();
const long visualizatorFrame::ID_BUTTONCOM = wxNewId();
const long visualizatorFrame::ID_AXISX = wxNewId();
const long visualizatorFrame::ID_AXISY = wxNewId();
const long visualizatorFrame::ID_MATHPLOTGRAPH = wxNewId();
const long visualizatorFrame::ID_PANELMAIN = wxNewId();
const long visualizatorFrame::ID_MENUITEMQUIT = wxNewId();
const long visualizatorFrame::ID_MENUITEMABOUT = wxNewId();
const long visualizatorFrame::ID_STATUSBARMAIN = wxNewId();
//*)

BEGIN_EVENT_TABLE(visualizatorFrame,wxFrame)
    //(*EventTable(visualizatorFrame)
    //*)
END_EVENT_TABLE()

visualizatorFrame::visualizatorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(visualizatorFrame)
    wxMenu* Menu1;
    wxMenu* MenuHelp;
    wxMenuBar* MenuBarMain;
    wxMenuItem* MenuItemAbout;
    wxMenuItem* MenuItemQuit;

    Create(parent, wxID_ANY, _("Visualizator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(814,450));
    SetMinSize(wxSize(1200,600));
    SetMaxSize(wxSize(1200,600));
    PanelMain = new wxPanel(this, ID_PANELMAIN, wxPoint(400,240), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELMAIN"));
    ButtonFile = new wxButton(PanelMain, ID_BUTTONFILE, _("File..."), wxPoint(8,8), wxSize(88,23), 0, wxDefaultValidator, _T("ID_BUTTONFILE"));
    ButtonCOM = new wxButton(PanelMain, ID_BUTTONCOM, _("COM"), wxPoint(8,40), wxSize(88,23), 0, wxDefaultValidator, _T("ID_BUTTONCOM"));
    MathPlotGraph = new mpWindow(PanelMain, ID_MATHPLOTGRAPH, wxPoint(104,8), wxSize(1072,512), wxRAISED_BORDER|wxTAB_TRAVERSAL);
    Axisx = new mpScaleX(_("X-axis"), 4, true);
    MathPlotGraph->AddLayer(Axisx);
    Axisy = new mpScaleY(_("Y-axis"), 4, true);
    MathPlotGraph->AddLayer(Axisy);
    MathPlotGraph->UpdateAll();
    MathPlotGraph->Fit();
    MenuBarMain = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItemQuit = new wxMenuItem(Menu1, ID_MENUITEMQUIT, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItemQuit);
    MenuBarMain->Append(Menu1, _("&File"));
    MenuHelp = new wxMenu();
    MenuItemAbout = new wxMenuItem(MenuHelp, ID_MENUITEMABOUT, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    MenuHelp->Append(MenuItemAbout);
    MenuBarMain->Append(MenuHelp, _("Help"));
    SetMenuBar(MenuBarMain);
    StatusBarMain = new wxStatusBar(this, ID_STATUSBARMAIN, 0, _T("ID_STATUSBARMAIN"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBarMain->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBarMain->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBarMain);

    Connect(ID_BUTTONFILE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&visualizatorFrame::OnButtonFileClick);
    Connect(ID_BUTTONCOM,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&visualizatorFrame::OnButtonCOMClick);
    Connect(ID_MENUITEMQUIT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&visualizatorFrame::OnQuit);
    Connect(ID_MENUITEMABOUT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&visualizatorFrame::OnAbout);
    //*)

    MathPlotGraph->SetScaleX(0.1);
    MathPlotGraph->SetScaleY(0.1);
}

visualizatorFrame::~visualizatorFrame()
{
    //(*Destroy(visualizatorFrame)
    //*)
}

void visualizatorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void visualizatorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void visualizatorFrame::OnButtonFileClick(wxCommandEvent& event)
{
    /*
    wxFileDialog openFileDialog(this,
                                _("Open file"),
                                "",
                                "",
                                "Files with data(*.txt;*.log)|*.txt;*.log",
                                wxFD_OPEN|wxFD_FILE_MUST_EXIST);


    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;
    */
    wxMessageBox( "Вероятность реализации этой функции\n\tКРАЙНЕ МАЛА!", "IMMOLATE IMPROVED", wxICON_ERROR );
}

//random color
int rc( int min_v, int max_v )
{
    return ( rand() % ( max_v - min_v + 1 ) ) + min_v;
}


std::vector<double>v[2];
std::vector<double>* getVectors( int &c )
{
    v[0].clear();
    v[1].clear();
    int a = 50;
    for(int i = 0; i < 1000; ++i)
    {
        v[0].push_back(i);
        a += ( rand() % 7 ) - 3;
        v[1].push_back(a);
    }

    c = 2;
    return v;
}

static std::vector< mpFXYVector* >graphics;
static mpInfoLayer* legend = new mpInfoLegend( wxRect( wxPoint( 800, 50 ), wxSize( 0, 0 ) ) );
void visualizatorFrame::OnButtonCOMClick(wxCommandEvent& event)
{
    //get vectors
    //getVectors();
    int counter;
    printf("1\n");
    std::vector<double>*tmp = getVectors( counter );
    printf("2\n");

    if( graphics.empty() )
    {
        for(int i = 1; i < counter; ++i)
        {
            graphics.push_back( new mpFXYVector() );
            graphics.at( i - 1 )->SetName( "TESTING" );
            graphics.at( i - 1 )->ShowName( false );
            graphics.at( i - 1 )->SetData( tmp[ 0 ], tmp[ i ] );
            graphics.at( i - 1 )->SetPen( wxPen( wxColour( rc(100,200), rc(100,200), rc(100,200) ), 3 ) );
            graphics.at( i - 1 )->SetContinuity( true );
            MathPlotGraph->AddLayer( graphics.at( i - 1 ) );
        }
        legend->SetVisible( true );
        MathPlotGraph->AddLayer( legend );
        MathPlotGraph->Fit();
    }
    else
    {
        for(int i = 1; i < counter; ++i)
        {
            graphics.at( i - 1 )->SetData( tmp[ 0 ], tmp[ i ] );
        }
        MathPlotGraph->UpdateAll();
    }
}
