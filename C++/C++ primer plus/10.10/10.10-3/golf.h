#pragma once
// golf.h -- for pe9-1.cpp
#ifndef _Golf_H
#define _Golf_H

class Golf {
    static const int Len = 40;
    char fullname[Len];
    int handicap;
public:
    // non-interactive version:
    // function sets golf structure to provided name, handicap
    // using values passed as arguments to the function
    void setgolf(const char* name, int hc);

    // interactive version:
    // function solicits nameand handicap from user
    // and sets the members of g to the values entered
    // returns 1 if name is entered, 0 if name is empty string
    int setgolf();

    // function resets handicap to new value
    void Handicap(int hc);
    // function displays contents of golf structure
    void showgolf() const;
};

#endif