#ifndef __WINDGAUGE_H
#define __WINDGAUGE_H

#include <deque>

class WindGauge {
    public:
        WindGauge(int = 12);
        ~WindGauge();
        void currentWindSpeed(int);
        int highest() const;
        int lowest() const;
        int average() const;

        static void dump(const WindGauge&);

    private:
        int period;
        std::deque<int> history;
};

#endif
