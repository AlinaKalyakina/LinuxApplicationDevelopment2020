# Сборка  
```
autoreconf -fisv
./configure
make
```
## Запуск русского варианта
```
make russian_guesser
```
## Запуск английского варианта
```
make english_guesser
```
## Запуск варианта с римскими цифрами
```
make english_guesser_r
```
или
```
make russian_guesser_r
```
## Пересборка перевода
```
make update_translation
...
make ru/LC_MESSAGES/guesser.mo
```
## Очистка
```
make gitclean
```
