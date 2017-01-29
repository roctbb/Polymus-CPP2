## Примечания по коду
### Использование

Программа воспринимает команды следующих типов:

 - exit - выход;
 - change 0 -100 - измений баланс счета номер 0 на -100 рублей;
 - balance 0 - узнать баланс счета с номером 0;
 - register Sarah 200 - создать счет для пользователя Сара с овердрафтом 200 и показать его номер. 


### Структура проекта.
Проект разделен на три файла, в соотвествие с тем, как это обычно принято делать в больших проектов.

 - Файл main.cpp - это основной файл проекта, содержащий функцию main. В нем происходит общение в пользователем.
 - Файл Account.h - это заголовочный файл класса Account. Он содержит перечисление свойств и методов, но не включает реализацию методов (их реальный код).
 - Файл Account.cpp - это реализация методов класса Account.
 
### Хранения файлов.

 - В файлах вида 1.txt программа хранить информацию о счете (имя файла - это номер счета). В файле через пробел записано имя владельца, баланс и возможный овердрафт.
 - В файле last_id.txt хранится одно число - последний занятый номер счета.