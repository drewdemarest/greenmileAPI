#include <QJsonObject>
#include <QtCore>
#include <memory>

using namespace std;

template <class T>
class JsonType
{
public:
    JsonType(){construct();}
    JsonType(const QString &qs):                            key(qs){construct();}
    JsonType(const T &t):                                   value(new T(t)){construct();}
    JsonType(const QString &qs, const T &t):                key(qs), value(new T(t)){construct();}
    JsonType(const QJsonValue &jv):                         jsonValue(jv){construct();}
    JsonType(const QString &qs, const QJsonValue &jv):      key(qs), jsonValue(jv){construct();}
    JsonType(const QVariant &qv):                           variantValue(qv){qDebug() << "I USED OL1"; construct();}
    JsonType(const QString &qs, const QVariant &qv):        key(qs), variantValue(qv){qDebug() << "I USED OL2"; construct();}

    //Special ctor, will iterate through a QJsonObject
    //and set values if it finds a key match.
    JsonType(const QString &qs, const QJsonObject &qjo):    key(qs), jsonValue(qjo.value(qs)){construct();}

    inline QString getKey();
    inline shared_ptr<T> getValue();
    inline QJsonValue getJsonValue();
    inline QVariant getVariantValue();
    inline QJsonObject getJsonObject();

private:
    //Construct happisly exists within each constructor.
    //This can be overloaded or not because of its inline status.
    inline void construct();

    QString         key;
    shared_ptr<T>   value;
    QVariant        variantValue;
    QJsonValue      jsonValue;
};

//Constructor overloads for specific templates need to go down here as inlines...
//template<>inline JsonType<QJsonValue>::JsonType(const QString &qs, const QJsonValue &jv): key(qs), jsonValue(jv){construct();}
//template<>inline JsonType<QVariant>::JsonType(const QString &qs, const QVariant &qv): key(qs), variantValue(qv){qDebug() << "I USED OL1"; construct();}
//template<>inline JsonType<QJsonArray>::JsonType(const QString &qs, const QJsonArray &qja): key(qs), jsonArray(qja){qDebug() << "I USED OL2"; construct();}

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
    if(!key.isEmpty())
    {
        //Determine which type is not null and populate other values.
        //Once everything is populated, return.
        if(value)
        {
            variantValue = QVariant(*value.get());
            jsonValue = jsonValue.fromVariant(variantValue);
            if(variantValue.isNull())
                qDebug() << "Warning, variantValuse did not properly map";
            if(jsonValue.isNull())
                qDebug() << "Warning, jsonValue did not properly map";
            return;
        }

        if(!variantValue.isNull())
        {
            value.reset(new T(variantValue.value<T>()));
        }


    }
    else
    {

    }

//    if(value)
//    {
//        qDebug() << "shared_ptr IS NOT NULL KEY IS" << key << "VALUE IS" << *value.get();
//        variantValue.setValue(*value.get());
//        qDebug() << "can T convert to variant?" << variantValue.canConvert<T>();
//        //qDebug() << key << variantValue.setValue(*value.get());
//    }
//    else if(!variantValue.isNull())
//    {
//        qDebug() << "VARIANT NOT NULL" << "KEY IS" << key << "VALUE" << variantValue.toString();
//        qDebug() << "Now trying an int cast " << variantValue.toDouble();
//    }
//    else if(!jsonValue.isNull())
//    {
//        qDebug() << "JSON NOT NULL" << "KEY IS" << key << "VALUE" << jsonValue.toString();
//    }
//    else
//    {
//        qDebug() << "ALL VALUES NULL" << "KEY IS" << key;
//    }



   // qDebug() << "trash variant of type t can conver to int?" << trash.convert(QMetaType::Int);
}
