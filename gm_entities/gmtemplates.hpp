#ifndef GMTEMPLATES_H
#define GMTEMPLATES_H

#include <QtCore>

//template <class T>
//void specific(const T&);

//void specific(const std::string&);

//template <class T>
//void something(const T& t)
//{
//    //code that works on all types
//    specific(t);
//    //more code that works on all types
//}

template <typename Map>
inline void setMapNull(Map& map)
{
    for(auto key : map.keys())
    {
        delete map[key];
        map[key] = Q_NULLPTR;
    }
}



#endif // GMTEMPLATES_H
