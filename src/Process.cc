#include "Process.h"

void Process()
{
    //==============================================
    // Process:
    // This function gets called during the event looping.
    // This is where one sets the variables used for the category .
    //==============================================

    // Process_Common is always called regardless of the category
    Process_Common();

    // Then depending on the analysis mode, different "Process" runs

    switch (ana.looperMode)
    {
        case AnalysisConfig::VBSHWW: Process_VBSHWW(); break;
        case AnalysisConfig::TTHH: Process_TTHH(); break;
    }

    // At this point, variables are all computed and set

    // Now fill all the histograms that are booked!
    ana.cutflow.fill();

    // Reset all the variables!
    ana.tx.clear();
}
