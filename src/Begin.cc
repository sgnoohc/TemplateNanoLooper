#include "Begin.h"

void Begin()
{
    //==============================================
    // Begin:
    // This function gets called prior to the event looping.
    // This function gets called regardless of the looper mode
    //==============================================

    // Begin_Common is always called regardless of the category
    Begin_Common();

    // Then depending on the analysis mode, different "Begin" runs

    switch (ana.looperMode)
    {
        case AnalysisConfig::VBSHWW: Begin_VBSHWW(); break;
        case AnalysisConfig::TTHH: Begin_TTHH(); break;
    }

    // At this point, the variables, histograms, selections are all defined and booked.

    // Print cut structure
    ana.cutflow.printCuts();

}
