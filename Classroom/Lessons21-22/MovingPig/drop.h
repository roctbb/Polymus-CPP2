#ifndef DROP_H
#define DROP_H
#include "cloud.h"
#include <QtGui>
class MainWindow;
class Drop : public Cloud
{
    Q_OBJECT
public:
    Drop(int x, MainWindow* parent);
    void start();
public slots:
    void moveMeVertical();
};

#endif // DROP_H
