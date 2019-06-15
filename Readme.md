Это учебное задание по созданию интепретатора для языка робота, который будет искать выход из лабиринта

Основные идеи
1. Есть главный класс - MAIN_CLASS, который содержит в себе
private
    -> storageID - глобальное хранилище всех переменных
    -> IdTable - струтура, которая разделяет существование переменных в различных простантсвах имён
    по первому ключу определяется простраство имён в котором существует переменная, по второму ключу
    находится имя переменной и в элементе содержится указатель на один из элментом storageID
    -> funcTable - контейнер в котором ключ имя функции и содержимое дескрипторы функций
    -> NameSpace - стэк на который кладётся новое простраство имён при вызове функции
    -> T800 - робот
public
   // -> std::list<int> - лист для сбора индексов
    -> std::list<std::string> -  лист для сбора имён перемнных
    -> std::list<Vertex*> - лист для сбора выражений
    
2. Существует базовый класс  Vertex от которого наследуют классы специфичных действий
3. Класс Robot реализует функции характерные только для него

4. Класс Label -  является универсальным объектом, которую возращает функция execute
    -> Хранит в себе на указатель объект хранилища storageID - Descriptor_value* const_id
    -> Указатель на временную переменную - Descriptor_value* id
    -> Маркер для индефикации текущего состояния Label

