/***************************************************************
 * Name:      visualizatorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Dudenkov Vladimir ()
 * Created:   2018-05-22
 * Copyright: Dudenkov Vladimir ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "visualizatorApp.h"

//(*AppHeaders
#include "visualizatorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(visualizatorApp);

bool visualizatorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	visualizatorFrame* Frame = new visualizatorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
