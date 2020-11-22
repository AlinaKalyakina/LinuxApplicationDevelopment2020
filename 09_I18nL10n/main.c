#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

#define MIN_NUM 0
#define MAX_NUM 100

int main(int argc, char *argv[])
{
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
            printf(_("Is your number greater than %d? Print 'yes' or 'no'"), middle);
            printf("\n");
            scanf("%6s", buf);
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

