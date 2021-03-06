#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <vector>
#include <iostream>
#include <iomanip>
#include "observer.h"
#include "subject.h"
#include "celltype.h"
#include "info.h"
#include "boardinfo.h"
#include "board.h"

class TextDisplay : public Observer {
	private:
    std::vector<int> level;
    std::vector<int> score;
    std::vector<std::vector<std::vector<char>>> boardData;
    std::vector<CellType> nextType;
	public:
    int getScore(int player) const;
    TextDisplay(int numberOfPlayers, int numberOfRows, int numberOfColumns);
    void notify(Subject & s) override;
    friend std::ostream& operator<<(std::ostream &out, const TextDisplay & td);
};

#endif
