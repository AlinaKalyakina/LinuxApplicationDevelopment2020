/* COMMENT:: guess, 1.0: Mon Dec  7 22:10:58 MSK 2020 */;
/** @file main.c
 * Main file of guesser.
 * Guesser guesses your number by asking if it is bigger than certain number
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>
#include "roman.h"
#include "config.h"


/** Macro for localization */
#define _(STRING) gettext(STRING)

/** Help string */
#define MANUAL _("Guesser is a program that guesses th number you've guessed\n\
\n\
Usage: guesser [OPTIONS]\n\
\n\
    --help		print this help, then exit\n\
    --version		print version number, then exit\n\
    -r		use roman numbers while guessing\n\
\n\
The guesser uses half dividion method.\n\
")


int main(int argc, char *argv[])
{
    int use_roman = 0;
    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "--help")) {
            return !printf("%s\n", MANUAL);
        } else if (!strcmp(argv[i], "--version")) {
            return !printf("guesser %s\n", VERSION);
        } else if (!strcmp(argv[i], "-r")) {
            use_roman = 1;
        }
    }
    setlocale (LC_ALL, "");
    if (getenv("PO_LOCAL"))
        bindtextdomain("guesser", ".");
    else
        bindtextdomain("guesser", "usr/share/locale");
    textdomain ("guesser");

    printf(_("Guess number between %d and %d"), MIN_NUM, MAX_NUM);
    printf("\n");

    int left = MIN_NUM - 1, right = MAX_NUM;
    char buf[8];
    while (right - left > 1) {
        int middle = (left + right) / 2;
        while (1) {
            if (use_roman) {
                printf(_("Is your number greater than %s? Print 'yes' or 'no'"), get_roman(middle));
            } else {
                printf(_("Is your number greater than %d? Print 'yes' or 'no'"), middle);
            }
            printf("\n");
            scanf("%8s", buf);
            if (!strcmp(buf, _("yes"))) {
                left = middle;
            } else if (!strcmp(buf, _("no"))) {
                right = middle;
            } else {
                printf("%s\n", _("Bad input, try again"));
                continue;
            }
            break;
        }
    }
    printf(_("You guessed the number %d"), right);
    return 0;
}

