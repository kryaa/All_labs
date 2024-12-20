## Инструкция по установке:
1) Скачать файлы из папок Headers и Cpp
2) Создать проект, вставить файлы .h в "Файлы заголовков" и файлы .cpp в "Файлы ресурсов"
3) Скомпилировать программу
## Описание программ для запуска
Всё взаимодействие с программами происходит через меню выбора действия. Меню вызывается циклично до того момента, пока пользователь не выберет "Выйти".
### Реализация класса STRING
В данной программе реализован класс STRING, и такие методы в нём как: Конструктор для объявления строки литерой, Метод для изменения строки областью памяти, Метод для получения длины строки, Метод для вывода строки со знакоместа (x, y).

### Трёхмерный массив указателей
Программа предназначена для выделения памяти под трёхмерный массив заданного размера, вывода занимаемой памяти, а так же возможности задавать значения элементов этого массива. В программе реализованы следующие методы: Метод для вывода объёма памяти, Метод для установки значения в массиве, Метод для освобождения памяти.

### Работа с последовательностью
Программа предназначена для выделения памяти под последовательность заданного размера, вывода занимаемой памяти, а так же возможности освободить память. В программе реализованы следующие методы: Метод для вывода объёма памяти, Метод для освобождения памяти.

### Наследование от STRING
Программа предназначена для работы с базовым классом STRING и его наследником EnhancedString. В программе реализованы следующие методы: Конструктор для объявления строки литерой, Метод для изменения строки областью памяти, Метод для получения длины строки, Метод для вывода строки со знакоместа (x, y). Соответственно эти же методы были переопределены в классе наследнике. 

### Перегрузка операторов
Программа предназначена для работы с базовым классом STRING и его перегруженными методами. В программе реализованы следующие методы: Конструктор для объявления строки литерой, Метод для изменения строки областью памяти, Метод для получения длины строки, Метод для вывода строки со знакоместа (x, y), Метод сравнения строк, Перегруженный метод сравнения строк, Перегруженный оператор сложения.

### Шаблоны классов и функций
Программа предназначена для работы с классом Sequence_of_numbers, который управляет массивом чисел произвольного типа с динамическим выделением памяти. В программе реализованы следующие методы: Конструктор с параметрами, Метод добавления числа в последовательность, Метод преобразования последовательности, Метод получения чисел последовательности, Метод получения размера последовательности.

### Потоковый ввод/вывод
Программа предназначена для работы с базовым классом STRING, а так же изменением введённой последовательности в соответствии с заданием.
