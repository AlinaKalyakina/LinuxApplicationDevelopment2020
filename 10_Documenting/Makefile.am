bin_PROGRAMS=guesser
guesser_SOURCES =main.c roman.c
pkgdata_DATA=ru/LC_MESSAGES/guesser.mo guesser.manpage

@DX_RULES@

ru/LC_MESSAGES/guesser.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	main.c
	xgettext -k_ -c $< -o messages.new.pot
	msgmerge -U $@ messages.new.pot
	rm messages.new.pot

update_translate: messages.pot ru.po

%.manpage:	%
	help2man --no-info --output=$@ --name='@PACKAGE_NAME@' ./$<

man: guesser.manpage
	help2man ./guesser > guesser.manpage
	man ./guesser.manpage

english_guesser: guesser
	./guesser

russian_guesser: guesser
	LANGUAGE=ru_RU PO_LOCAL=1 ./guesser

english_guesser_r: guesser
	./guesser -r

russian_guesser_r: guesser
	LANGUAGE=ru_RU PO_LOCAL=1 ./guesser -r

gitclean:
	git clean -fd

all-local:	doxygen-doc

.PHONY: update gitclean english_guesser russian_guesser ru/LC_MESSAGES/guesser.mo
