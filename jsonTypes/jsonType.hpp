#include <QJsonObject>
#include <QtCore>
#include <memory>

using namespace std;

template <class T>
class JsonType
{
public:
    JsonType(): key(), value(new T()){createMapFormat();}
    JsonType(const QString &qs): key(qs), value(new T()){createMapFormat();}
    JsonType(const QString &qs, const T &t): key(qs), value(new T(t)){createMapFormat();}

    inline QString getKey();
    inline T getValue();

    bool isMapValid();
    bool isJsonValid();

private:
    inline void createMapFormat();

    QString key;
    unique_ptr<T> value;

    bool validJson;
    bool validMap;
    QJsonObject jsonFormat;
    QVariantMap varMapFormat;
};

template <class T>
inline T JsonType<T>::getValue()
{
    return *value.get();
}

template<>
inline long JsonType<long>::getValue()
{
    return 1000L;
}

template <class T>
inline void JsonType<T>::createMapFormat()
{
    qDebug() << "Map are valid? Hurp";
}
