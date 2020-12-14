bin_PROGRAMS=guesser
guesser_SOURCES =main.c
pkgdata_DATA=ru/LC_MESSAGES/guesser.mo
pkgdatadir = $(localedir)/ru/LC_MESSAGES

AM_CPPFLAGS = -D LOCALEDIR='"$(localedir)"'


ru/LC_MESSAGES/guesser.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	main.c
	xgettext -k_ -c $< -o messages.new.pot
	msgmerge -U $@ messages.new.pot
	rm messages.new.pot

update: messages.pot ru.po

english_guesser: guesser
	LANGUAGE=en_EN guesser

russian_guesser: guesser
	LANGUAGE=ru_RU guesser

gitclean:
	git clean -fd

.PHONY: update gitclean english_guesser russian_guesser
