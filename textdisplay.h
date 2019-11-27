#ifndef _TESTDISPLAY_H_
#define _TESTDISPLAY_H_
#include <vector>
#include "observer.h"
#include "subject.h"

class TextDisplay: public Observer {
    std::vector<std::vector<std::vector<char>>> boardData; 
    public:
    TextDisplay(int playerNum);
    void notify(Subject& s) override;
};
#endif
