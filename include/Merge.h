#ifndef MERGE_H
#define MERGE_H


class Merge
{
public:
    Merge();
    virtual void execute() = 0;
    virtual void display() = 0;
};


class AlwaysMaximum : public Merge
{
public:
    AlwaysMaximum();
    execute();
    display();
};



#endif // MERGE_H
