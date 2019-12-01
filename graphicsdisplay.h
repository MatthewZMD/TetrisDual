#ifndef _GRAPHICSDISPLAY_H_
#define _GRAPHICSDISPLAY_H_

#include "window.h"
#include "board.h"
#include "observer.h"
#include "info.h"
#include "state.h"

class GraphicsDisplay: public Observer {
	private:
		Xwindow xw;
		int length;
		int width;
	public:
		void notify(Subject& s) override;
		GraphicsDisplay(int length, int width);
		~GraphicsDisplay();
};
#endif
