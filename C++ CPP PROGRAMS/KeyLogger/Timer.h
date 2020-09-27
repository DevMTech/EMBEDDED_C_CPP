// Parallel, Delayed, Repeated Code execution
// Thread - Share same data, variables, file descriptor, same memory address space,
// multiple threads can run within a Process, use threads for concurrent task execution
// THIS 'Timer.h' HEADER CAN BLOCK THE MAIN THREAD WHEN REQUIRED
// Synchronous code execution without blocking main thread
// Keyboard hooks
//
/*
#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>

class Timer
{
    std::thread Thread;

    bool Alive = false;
    long CallNumber = -1L; // number of times a function is to be called
    long repeat_count = -1L; // number of times a function has been called

    std::chrono::milliseconds interval = std::chrono::milliseconds(0);
    // default interval between function calls kept 0 here, to be changed later

    std::function<void(void)> funct = nullptr;
    // can accept a function that takes nothing & does not return anything

    void SleepAndRun()
    {
        std::this_thread::sleep_for(interval); // block the thread for a certain time interval
        //std::this::sleep_for(interval); // block the thread for a certain time interval
        if(Alive)
            (Function())(); // public method, 2nd () calls the function returned by 1st ()
    }

    void ThreadFunc()
    {
        if(CallNumber == Infinite)
            while(Alive)
                SleepAndRun();
        else
            while(repeat_count--)
                SleepAndRun();
    }

    public:
        static const long Infinite = -1L;

        Timer(){}

        Timer(const std::function<void(void)> &f) : funct (f) {}

        Timer(const std::function<void(void)> &f,
              const unsigned long &i,
              const long repeat = Timer::Infinite) : funct (f),
                                                     interval(std::chrono::milliseconds(i)),
                                                     CallNumber(repeat){}

        void Start(bool Async = true)
        {
            if(IsAlive()) return;

            Alive = true;
            repeat_count = CallNumber;
            if(Async)
                Thread = std::thread(ThreadFunc, this);
            else
                this->ThreadFunc();
        }

        void Stop()
        {
            Alive = false;
            Thread.join();
        }

        void SetFunction(const std::function<void(void)> &f)
        {
            funct = f;
        }

        bool IsAlive() const {return Alive;}

        void RepeatCount(const long r)
        {
            if(Alive)   return;

            CallNumber = r;
        }

        long GetLeftCount() const {return repeat_count;}

        long RepeatCount() const {return CallNumber;}

        void SetInterval(const unsigned long &i)
        {
            if(Alive) return;

            interval = std::chrono::milliseconds(i);
        }

        unsigned long Interval() const {return interval.count;} // chrono:: to long conversion

        const std::function<void(void)> &Function() const
        {
            return funct; // returns a function 'funct()'
        }
};

#endif
*/
