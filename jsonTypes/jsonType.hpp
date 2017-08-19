#include <QJsonObject>
#include <QtCore>
#include <memory>

using namespace std;

template <class T>
class JsonType
{
public:
    JsonType(){construct();}
    JsonType(const QString &qs): key(qs){construct();}
    JsonType(const QString &qs, const T &t): key(qs), value(new T(t)){construct();}
    JsonType(const QString &qs, const QJsonValue &jv): key(qs), jsonValue(jv){construct();}
    JsonType(const QString &qs, const QVariant &qv): key(qs), variantValue(qv){construct();}
    JsonType(const QString &qs, const QJsonObject &qjo): key(qs), jsonValue(qjo.value(qs)){construct();}
    JsonType(const QString &qs, const QVariantMap &qvm): key(qs), variantValue(qvm.value(qs)){construct();}

    inline QString getKey();
    inline shared_ptr<T> getValue();
    inline QJsonValue getJsonValue();
    inline QVariant getVariantValue();
    inline QVariantMap getVariantMap();
    inline QJsonObject getJsonObject();

private:
    inline void construct();

    QString         key;
    shared_ptr<T>   value;
    QVariant        variantValue;
    QJsonValue      jsonValue;
};

template <class T>
inline shared_ptr<T> JsonType<T>::getValue()
{
    return value;
}

//template<>
//inline long JsonType<long>::getValue()
//{
//    return 1000L;
//}

template <class T>
inline void JsonType<T>::construct()
{
    if(value)
        variantValue.setValue(*value.get());
    else
        qDebug() << "VALUE NULL";

   // qDebug() << "trash variant of type t can conver to int?" << trash.convert(QMetaType::Int);
}
