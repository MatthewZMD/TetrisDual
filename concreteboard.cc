#include "concreteboard.h"

void ConcreteBoard::levelUp()
{
    level = level->levelUp();
}

void ConcreteBoard::levelDown()
{
    level = level->levelDown();
}

void ConcreteBoard::right(int time)
{
    bool exist = 0;
    while (time != 0)
    {
        for (auto &i : thisBlock->cells)
        {
            for (auto &j : thisBlock->cells)
            {
                if (i->pos.col + 1 == j->pos.col)
                {
                    exist = 1;
                }
            }
            if (exist == 0)
            {
                if (i->pos.col == 10 || !allCells[i->pos.row][i->pos.col + 1].isEmpty())
                {
                    break;
                }
            }
            exist = 0;
        }
        Celltype cur_type = thisBlock->cells[0].type;
        int cur_level = thisBlock->cells[0].blockLevel;
        std::vector<Cell> temp;
        for (auto &i : thisBlock->cells)
        {
            temp.emplace_back(&(allCells[i->pos.row][i->pos.col + 1]));
            i->restore();
        }
        thisBlock = std::shared_ptr<Block>(new Block{cur_type, cur_level, temp});
        thisBlock->recaliBtmLft();
        --time;
    }
    if (level->getLevel() == 3)
    {
        down();
    }
}

void ConcreteBoard::left(int time)
{
    bool exist = 0;
    while (time != 0)
    {
         for (auto &i : thisBlock->cells)
        {
            for (auto &j : thisBlock->cells)
            {
                if (i->pos.col - 1 == j->pos.col)
                {
                    exist = 1;
                }
            }
            if (exist == 0)
            {
                if (i->pos.col == 0 || !allCells[i->pos.row][i->pos.col - 1].isEmpty())
                {
                    break;
                }
            }
            exist = 0;
        }
        Celltype cur_type = thisBlock->cells[0].type;
        int cur_level = thisBlock->cells[0].blockLevel;
        std::vector<Cell> temp;
        for (auto &i : thisBlock->cells)
        {
            temp.emplace_back(&(allCells[i->pos.row][i->pos.col - 1]));
            i->restore();
        }
        thisBlock = std::shared_ptr<Block>(new Block{cur_type, cur_level, temp});
        thisBlock->recaliBtmLft();
        --time;
    }
    if (level->getLevel() == 3)
    {
        down();
    }
}

void ConcreteBoard::rotate(bool isClockwise)
{
    int rm_length = 0;
    int new_row = 0;
    int new_col = 0;
    bool exist = 0;
    if (isClockwise == 1)
    {
        for (auto &i : thisBlock->cells)
        {
            if (rm_length < i->pos.col - thisBlock->btmLft.col)
            {
                rm_length = i->pos.col - thisBlock->btmLft.col;
            }
        }
        for (auto &i : thisBlock->cells)
        {
            int new_row = thisBlock->btmLft.row + i->pos.col - thisBlock->btmLft.col - rm_length;
            int new_col = thisBlock->btmLft.col + thisBlock->btmLft.row - i->pos.row if (new_col > 10 || !allCells[new_row][new_col].isEmpty())
            for (auto &j : thisBlock->cells) {
                if (new_row == j->pos.row && new_col == j->pos.col) {
                    exist = 1;
                }
            }
            if (exist = 0) {
                if (new_col > 10 || !allCells[new_row][new_col].isEmpty()) {
                    return;
                }
            }
            exist = 0;
        }
        Celltype cur_type = thisBlock->cells[0].type;
        int cur_level = thisBlock->cells[0].blockLevel;
        std::vector<Cell> temp;
        for (auto &i : thisBlock->cells)
        {
            temp.emplace_back(&(allCells[thisBlock->btmLft.row + i->pos.col - thisBlock->btmLft.col - rm_length][thisBlock->btmLft.col + thisBlock->btmLft.row - i->pos.row]));
            i->restore();
        }
        thisBlock = std::shared_ptr<Block>(new Block{cur_type, cur_level, temp});
        thisBlock->recaliBtmLft();
    }
    else
    {
        for (auto &i : thisBlock->cells)
        {
            if (rm_length < thisBlock->btmLft.row - i->pos.row)
            {
                rm_length = thisBlock->btmLft.row - i->pos.row;
            }
        }
        for (auto &i : thisBlock->cells)
        {
            int new_row = thisBlock->btmLft.row + i->pos.col - thisBlock->btmLft.col;
            int new_col = thisBlock->btmLft.col - thisBlock->btmLft.row + i->pos.row + rm_length;
            for (auto &j : thisBlock->cells) {
                if (new_row == j->pos.row && new_col == j->pos.col) {
                    exist = 1;
                }
            }
            if (exist = 0) {
                if (new_col > 10 || !allCells[new_row][new_col].isEmpty()) {
                    return;
                }
            }
            exist = 0;
        }
        Celltype cur_type = thisBlock->cells[0].type;
        int cur_level = thisBlock->cells[0].blockLevel;
        std::vector<Cell> temp;
        for (auto &i : thisBlock->cells)
        {
            temp.emplace_back(&(allCells[thisBlock->btmLft.row + i->pos.col - thisBlock->btmLft.col][thisBlock->btmLft.col - thisBlock->btmLft.row + i->pos.row + rm_length]));
            i->restore();
        }
        thisBlock = std::shared_ptr<Block>(new Block{cur_type, cur_level, temp});
        thisBlock->recaliBtmLft();
    }
}

bool ConcreteBoard::down()
{
    {
    bool exist = 0;
    while (time != 0)
    {
         for (auto &i : thisBlock->cells)
        {
            for (auto &j : thisBlock->cells)
            {
                if (i->pos.col - 1 == j->pos.col)
                {
                    exist = 1;
                }
            }
            if (exist == 0)
            {
                if (i->pos.col == 0 || !allCells[i->pos.row][i->pos.col - 1].isEmpty())
                {
                    break;
                }
            }
            exist = 0;
        }
        Celltype cur_type = thisBlock->cells[0].type;
        int cur_level = thisBlock->cells[0].blockLevel;
        std::vector<Cell> temp;
        for (auto &i : thisBlock->cells)
        {
            temp.emplace_back(&(allCells[i->pos.row][i->pos.col - 1]));
            i->restore();
        }
        thisBlock = std::shared_ptr<Block>(new Block{cur_type, cur_level, temp});
        thisBlock->recaliBtmLft();
        --time;
    }
    if (level->getLevel() == 3)
    {
        down();
    }
}
}

void ConcreteBoard::genThis()
{
    std::vector<std::shared_ptr<Cell>> cells;
    Coordinate btmLft{3, 0};
    switch (nextType)
    {
    case CellType::I:
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col)));
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 2)));
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 3)));
        break;
    case CellType::J:
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col)));
        cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col)));
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 2)));
        break;
    case CellType::L:
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col)));
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 2)));
        cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 2)));
        break;
    case CellType::O:
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col)));
        cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col)));
        cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 1)));
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
        break;
    case CellType::S:
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col)));
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
        cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 1)));
        cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 2)));
        break;
    case CellType::Z:
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
        cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col)));
        cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 1)));
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 2)));
        break;
    case CellType::T:
        cells.emplace_back(&(allCells.at(btmLft.row).at(btmLft.col + 1)));
        cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col)));
        cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 1)));
        cells.emplace_back(&(allCells.at(btmLft.row - 1).at(btmLft.col + 2)));
        break;
    case CellType::E:
        break; // Do nothing
    }
    thisBlock = std::shared_ptr<Block>(new Block{nextType, level->getLevel(), cells});
    nextType = CellType::E;
}

void ConcreteBoard::genNext()
{
    nextType = level->genBlock();
}
