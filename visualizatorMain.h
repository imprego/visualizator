/***************************************************************
 * Name:      visualizatorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Dudenkov Vladimir ()
 * Created:   2018-05-22
 * Copyright: Dudenkov Vladimir ()
 * License:
 **************************************************************/

#ifndef VISUALIZATORMAIN_H
#define VISUALIZATORMAIN_H

//(*Headers(visualizatorFrame)
#include <mathplot.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
//*)

class visualizatorFrame: public wxFrame
{
    public:

        visualizatorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~visualizatorFrame();

    private:

        //(*Handlers(visualizatorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButtonFileClick(wxCommandEvent& event);
        void OnButtonCOMClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(visualizatorFrame)
        static const long ID_BUTTONFILE;
        static const long ID_BUTTONCOM;
        static const long ID_AXISX;
        static const long ID_AXISY;
        static const long ID_MATHPLOTGRAPH;
        static const long ID_PANELMAIN;
        static const long ID_MENUITEMQUIT;
        static const long ID_MENUITEMABOUT;
        static const long ID_STATUSBARMAIN;
        //*)

        //(*Declarations(visualizatorFrame)
        mpScaleX   *Axisx;
        mpScaleY   *Axisy;
        mpWindow* MathPlotGraph;
        wxButton* ButtonCOM;
        wxButton* ButtonFile;
        wxPanel* PanelMain;
        wxStatusBar* StatusBarMain;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // VISUALIZATORMAIN_H
