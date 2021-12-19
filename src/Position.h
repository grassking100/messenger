#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED
class Position
{
public:
    int row=0;
    int col=0;
    Position(int _row,int _col)
    {
        row=_row;
        col=_col;
    };
    Position() {};
};
Position addPosition(Position lhs,Position rhs);
#endif // POSITION_H_INCLUDED
