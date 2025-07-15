// src/data.c
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fwt2/data.h"

struct data get_data(FILE *stream, struct data ts) {
    char buf[MAXLEN];
    const char *delims = " ,\t\n";
    int COLS = 0;

    while (fgets(buf, MAXLEN, stream)) {
        int line_cols = 0;
        remove_trailing_blanks(buf);
        char *tok = strtok(buf, delims);
        while (tok) {
            ts.value = realloc(ts.value, (++ts.SIZE) * sizeof *ts.value);
            ts.value[ts.SIZE-1] = atof(tok);
            line_cols++;
            tok = strtok(NULL, delims);
        }
        COLS = line_cols;    // we'll assume consistent cols; ts.COLS is set after
        ts.ROWS++;
    }
    ts.COLS = COLS;
    return ts;
}

void remove_trailing_blanks(char *buf) {
    char *p = buf + strlen(buf) - 1;
    while (p >= buf && isspace((unsigned char)*p)) *p-- = '\0';
}

void stack_columns(double *index, double *signal, double *uncert, struct data ts) {
    for (int i = 0; i < ts.ROWS; i++) {
        if (ts.COLS == 1) {
            index[i]  = i;
            signal[i] = ts.value[i];
            uncert[i] = 1.;
        } else if (ts.COLS == 2) {
            index[i]  = ts.value[i*2];
            signal[i] = ts.value[i*2+1];
            uncert[i] = 1.;
        } else {
            index[i]  = ts.value[i*3];
            signal[i] = ts.value[i*3+1];
            uncert[i] = ts.value[i*3+2];
        }
    }
}

