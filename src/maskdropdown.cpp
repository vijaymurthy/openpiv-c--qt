#include "maskdropdown.h"
#include "pivdisplay.h"

#include <QMenu>

MaskDropDown::MaskDropDown(QWidget *parent) : QMenu(parent)
{
    loaded = false;
    QAction *tempAction;
    tempAction = new QAction("Import mask...", this);
    actionList.append(tempAction);
    tempAction = new QAction("Show grid", this);
    tempAction->setCheckable(true);
    tempAction->setChecked(false);
    actionList.append(tempAction);
    tempAction = new QAction("Clear mask", this);
    actionList.append(tempAction);

    this->addActions(actionList);
    actionList.value(0)->setEnabled(loaded);
    connect(actionList.value(0), SIGNAL(triggered()), this, SLOT(importTrigger()));
    actionList.value(1)->setEnabled(loaded);
    connect(actionList.value(1), SIGNAL(triggered(bool)), this, SLOT(gridTrigger(bool)));
    actionList.value(2)->setEnabled(loaded);
    connect(actionList.value(2), SIGNAL(triggered()), this, SLOT(clearTrigger()));
}

MaskDropDown::~MaskDropDown()
{

}

//void MaskDropDown::setDisplay(PivDisplay *pivDisplayPass)
//{
//    pivDisplay = pivDisplayPass;
//}

void MaskDropDown::imageLoaded()
{
    loaded = true;
    actionList.value(0)->setEnabled(loaded);
}

void MaskDropDown::importTrigger()
{
    //emit(importMaskClicked(pivDisplay));
    emit(importMaskClicked());
}

void MaskDropDown::maskLoaded()
{
    actionList.value(1)->setEnabled(true);
    actionList.value(1)->setChecked(true);
    actionList.value(2)->setEnabled(true);
    emit (gridToggled(true));
}

void MaskDropDown::gridTrigger(bool checkState)
{
    emit(gridToggled(checkState));
    actionList.value(1)->setChecked(checkState);
}

void MaskDropDown::clearTrigger()
{
    emit(clearMask(false));
}
