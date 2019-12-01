#ifndef _GRAPHICSDISPLAY_H_
#define _GRAPHICSDISPLAY_H_
#include "window.h"
#include "board.h"
#include "observer.h"
#include "info.h"
#include "state.h"
#include "boardinfo.h"

class GraphicsDisplay: public Observer {
	private:
    int length;
    int width;
    Xwindow xw;
	public:
    void notify(Subject& s) override;
    GraphicsDisplay(int length, int width);
    ~GraphicsDisplay();
};
#endif
