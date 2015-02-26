#ifndef CALLBACK_H
#define CALLBACK_H

class CallBack
{
public:
    CallBack();
    virtual ~CallBack();

    //return the object pointer of the called function
    virtual void * getObject() = 0;

    //create the same callback obj
    virtual CallBack* Clone() = 0;

    virtual void exectue() = 0;
    virtual void execute(int a) = 0;
    virtual void execute(void *pArgs) = 0;
    virtual void execute(void *pArgs, void *pReturnVal) = 0;

    void cancel();
    bool isCanceled();

private:
    QVector<Call

};

#endif // CALLBACK_H
