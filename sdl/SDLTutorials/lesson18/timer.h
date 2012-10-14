#ifndef TIMER_H
#define TIMER_H

class Timer
{
private:
    int startTicks;//计时器启动时的微秒数

    int pausedTicks;//计时器暂停时的微秒数

    //the Timer status
    bool paused;
    bool started;

public:
    //init
    Timer();

    //the various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the Timer's times;
    int get_ticks();

    //check the timer's status
    bool is_started();
    bool is_paused();
};


#endif // TIMER_H
