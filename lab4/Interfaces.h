#ifndef LAB4_INTERFACES_H
#define LAB4_INTERFACES_H

// Интерфейс "Геометрическая фигура".
class IGeoFig {
public:
// Площадь.
    virtual double square () = 0 ;
// Периметр.
    virtual double perimeter () = 0 ;
};

// Вектор
class CVector2D {
public:
    double x, y;
    CVector2D(double x, double y) {
        this->x = x;
        this->y = y;
    }
    CVector2D(){
        x = 0;
        y = 0;
    };
};

// Интерфейс "Физический объект".
class IPhysObject {
public:
// Масса, кг.
    virtual double mass () const = 0 ;
// Координаты центра масс, м.
    virtual CVector2D position () = 0 ;
// Сравнение по массе.
    virtual bool operator == ( const IPhysObject& ob ) const = 0 ;
// Сравнение по массе.
    virtual bool operator < ( const IPhysObject& ob ) const = 0 ;
};

// Интерфейс "Отображаемый"
class IPrintable {
public:
// Отобразить на экране
// (выводить в текстовом виде параметры фигуры).
    virtual void draw () = 0 ;
};

// Интерфейс для классов, которые можно задать через диалог с пользователем.
class IDialogInitiable {
// Задать параметры объекта с помощью диалога с пользователем.
    virtual void initFromDialog () = 0 ;
};

// Интерфейс "Класс"
class BaseCObject {
public:
// Имя класса (типа данных).
    virtual const char * classname () = 0 ;
// Размер занимаемой памяти.
    virtual unsigned int size () = 0 ;
};

class IFigure: IGeoFig, public IPhysObject, IPrintable, IDialogInitiable, BaseCObject{
public:
    virtual double mass() const override = 0;

    virtual CVector2D position() override = 0;

    virtual bool operator==(const IPhysObject &ob) const override = 0;

    virtual bool operator<(const IPhysObject &ob) const override = 0;

    virtual double square() override = 0;

    virtual double perimeter() override = 0;

    virtual void draw() override = 0;

    virtual void initFromDialog() override = 0;

    virtual const char *classname() override = 0;

    virtual unsigned int size() override = 0;
};
#endif //LAB4_INTERFACES_H
