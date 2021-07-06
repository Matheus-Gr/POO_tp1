//
// Created by mathe on 06/07/2021.
//

#include "utils.h"

string getDate(){
    const int MAXLEN = 80;
    char date[MAXLEN];
    time_t t = time(0);
    strftime(date, MAXLEN, "%d/%m/%Y", localtime(&t));
    string sDate(date);
    return sDate;
}