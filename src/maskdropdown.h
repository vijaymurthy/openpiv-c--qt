#ifndef MASKDROPDOWN_H
#define MASKDROPDOWN_H

#include <QObject>
#include <QMenu>
#include "pivdisplay.h"

class MaskDropDown : public QMenu
{
    Q_OBJECT

    public:
        MaskDropDown(QWidget *parent = 0);
        virtual ~MaskDropDown();

        //void setDisplay(PivDisplay *pivDisplayPass);

    public slots:
        void imageLoaded();
        void maskLoaded();

    protected slots:
        void importTrigger();
        void gridTrigger(bool checkState);
        void clearTrigger();

    signals:
        //void importMaskClicked(PivDisplay *pivDisplayPassOut);
        void importMaskClicked();
        void gridToggled(bool isTrue);
        void clearMask(bool isTrue);

    private:
        bool loaded;
        PivDisplay *pivDisplay;
        QList<QAction*> actionList;

};

#endif // MASKDROPDOWN_H
