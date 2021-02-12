#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include "stack.h"
#include "to_postfix.h"

using namespace std;

double Eval(const std::string& in) {
    string fd = to_postfix (in);
    Stack <double> St;
    string last = "";
    for (int i = 0;i < fd.size ();i ++) {
        if (fd[i] == ' ') {
            if (last.size () > 0) {
                double val = stod (last);
                St.push (val);
                last = "";
            }
        }
        if (fd[i] == '-' && (i + 1 < fd.size () && fd[i + 1] != ' ')) {
            last += '-';
            continue;
        }
        if (fd[i] == '+') {
            double fi = St.top ();
            St.pop ();
            double se = St.top ();
            St.pop ();
            St.push (fi + se);
        }
        if (fd[i] == '-') {
            double fi = St.top ();
            St.pop ();
            double se = St.top ();
            St.pop ();
            St.push (se - fi);
        }
        if (fd[i] == '*') {
            double fi = St.top ();
            St.pop ();
            double se = St.top ();
            St.pop ();
            St.push (fi * se);
        }
        if (fd[i] == '/') {
            double fi = St.top ();
            St.pop ();
            double se = St.top ();
            St.pop ();
            St.push (se / fi);
        }
        if (fd[i] == '.' || (fd[i] >= '0' && fd[i] <= '9')) last += fd[i];
    }
    if (last.size () > 0) {
        double val = stod (last);
        St.push (val);                
    }
    if (St.size () == 0) return 0;
    else return St.top ();
}

#endif //CALCULATOR_H
