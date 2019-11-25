#ifndef LEVEL_H
#define LEVEL_H
#include <memory>
#include <fstream>
#include <vector>
#include <string>
#include "celltype.h"

class Level {
	public:
    Level(int level, std::string defaultFileName);

    // pure virtual methods
    virtual CellType genBlock() const = 0;
    virtual std::shared_ptr<Level> levelDown() const = 0;
    virtual std::shared_ptr<Level> levelUp() const = 0;

    // virtual methods
    virtual int heavyOffset() const;
    virtual bool dropBrownBlock() const;

    // non-virtual methods
    void setReadFromFile(std::string fileName);
    void unsetReadFromFile();

    // getter
    void getLevel(int & level) const;

	protected:
    int level;
    std::string defaultFileName; // filename for level 0
    bool readFromFile; // for level 3 & 4
    std::vector<CellType> sequence; // for level 3 & 4
    int nextLine; // for level 3 & 4

    CellType genBlockFromFile() const;
};

#endif
