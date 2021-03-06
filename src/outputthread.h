#ifndef OUTPUTTHREAD_H
#define OUTPUTTHREAD_H

#include <QThread>
#include <QSemaphore>
#include <QVector>
#include <QMutex>

#include "pivdata.h"
#include "output.h"

class OutputThread : public QThread
{
    Q_OBJECT

    public:
        explicit OutputThread(QSemaphore *freePass, QSemaphore *usedPass, QMutex *mutexPass, QVector<PivData*> *dataVectorPass, int datasizePass, QObject *parent = 0);
        virtual ~OutputThread();

        void setOutputObject(Output *outputPass);

        int startOutput();
        void stopProcess();

    signals:
        void fileOutput();
        void doneProcess();

    private:
        void run();

        QSemaphore *free;
        QSemaphore *used;
        QMutex *mutex;
        QVector<PivData*> *dataVector;
        Output *output;
        int datasize;

        bool abort;
};

#endif // OUTPUTTHREAD_H
