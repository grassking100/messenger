#include "Position.h"
Position addPosition(Position lhs,Position rhs)
{
    Position p(lhs.row+rhs.row,rhs.col+lhs.col);
    return p;
}
