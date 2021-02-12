#ifndef TO_POSTFIX_H
#define TO_POSTFIX_H

#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

/*
 * to_postfix
 *
 * argument: std::string of expression with infix notation
 *      (e.g. "3*(324-9*-(1237 +29 12.67)/23)")
 *
 * return value: std::string of converted expression with postfix notation
 *      (e.g. "3 324 9 -1 1237 2912.67 + * * 23 / - *")
 *
 *
 * Permitted input characters
 *      number 0 ~ 9 (e.g. 42)
 *      . (period) for decimal numbers (e.g. 3.14)
 *      + (plus), * (asterisk), / (slash): binary operators (e.g. 1+1, 3*4, 12/4)
 *      - (minus) for both binary and unary operator (e.g. 100 - 1 - 1 - 1 - 1, -27)
 *      (, ): parentheses for calculation precedence (e.g. 2 * (3 + 5))
 *      space characters (' '): ignore, even between numbers
 *          (e.g. "9 9" equivalent to "99")
 *
 * Grammar for expected inputs (You don't have to worry about wrong inputs)
 *      1. Omission of multiplication operator (*) is not allowed
 *          # 48 / 2 (9 + 3) (wrong)
 *      2. You do not need to provide all parentheses, but they must match
 *          # 2 + 3 * 5 (good)
 *          # 2 + (3 * (5)) (good)
 *          # (2 + (3 * 5) (wrong, missing parenthesis)
 *      3. Only use permitted input characters above
 *      4. and of course it must be a valid expression with infix notation.
 *
 * Note on unary minus followed by '('
 *      When a unary minus is followed by left parenthesis,
 *      it should be converted to "-1 *".
 *      e.g. "-(2+3)" -> " -1 2 3 + *"
 *
 * Output format
 *      All operators and operands, except unary minus,
 *          should be separated with single space character (' ').
 *      Unary minus characters should have no spaces with its trailing operand.
 *      There should be no spaces within an operand, even if it had those in input.
 *      Since we don't need them anymore, there should be no parentheses in output.
 *
 * GOOD LUCK!
 */

std::string to_postfix(const std::string& infix) {
    std::string cur = "";
    string nw = "";
    for (int i = 0;i < infix.size ();i ++) {
        if (infix[i] == ' ') continue;
        nw += infix[i];
    }
    for (int i = 0;i < nw.size ();i ++) {
        if (nw[i] == '-' && i + 1 < nw.size () && nw[i + 1] == '(' && (i == 0 || nw[i - 1] == '(' || nw[i - 1] == '-' || nw[i - 1] == '*' || nw[i - 1] == '/' || nw[i - 1] == '+')) cur += "(-1)*";
        else cur += nw[i];
    }
    Stack <char> st;
    string ans = "";
    for (int i = 0;i < cur.size ();i ++) {
        if (cur[i] == '.' || (cur[i] >= '0' && cur[i] <= '9')) {
            if (i == 0 || (cur[i - 1] != '.' && (cur[i - 1] < '0' || cur[i - 1] > '9'))) ans += ' ';
            ans += cur[i];
            continue;
        } 
        if (cur[i] == '(')
            st.push (cur[i]);
        if (cur[i] == ')') {
            while (st.top () != '(') {
                ans += ' ';
                ans += st.top ();
                st.pop ();
            }
            st.pop ();
        }
        if (i == 0 || (cur[i - 1] == '(' || cur[i - 1] == '*' || cur[i - 1] == '+' || cur[i - 1] == '-' || cur[i - 1] == '/')) { 
            if (cur[i] == '-') {
                ans += " -";
                ans += cur[i + 1];
                i ++;
                continue;
            }
        }
        if (cur[i] == '+' || cur[i] == '-') {
            while (!st.empty () && (st.top () == '*' || st.top () == '/' || st.top () == '-' || st.top () == '+')) {
                ans += ' ';
                ans += st.top ();
                st.pop ();
            }
            st.push (cur[i]);
        }
        if (cur[i] == '*' || cur[i] == '/') {
            while (!st.empty () && (st.top () == '*' || st.top () == '/')) {
                ans += ' ';
                ans += st.top ();
                st.pop ();
            }
            st.push (cur[i]);
        }
    }   
    while (!st.empty ()) {
        ans += ' ';
        ans += st.top ();
        st.pop ();
    }
    string reans = "";
    for (int i = 1;i < ans.size ();i ++) reans += ans[i];
    return reans;
}

#endif //TO_POSTFIX_H
