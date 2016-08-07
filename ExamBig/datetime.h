#ifndef DATETIME_H
#define DATETIME_H

// The Day, Month and Year structs are necessary in order to not misorder the DateTime constructor. There are different date formats.
// The time format though is always the same.
struct Day {
    explicit Day(unsigned short int val)
        :m_Val(val)
    {
    }
    unsigned short int m_Val;
};

struct Month {
    explicit Month(unsigned short int val)
        :m_Val(val)
    {
    }
    unsigned short int m_Val;
};

struct Year {
    explicit Year(unsigned short int val)
        :m_Val(val)
    {
    }
    unsigned short int m_Val;
};

struct DateTime
{
    Date(const Day& day, const Month& month, const Year& year, unsigned short hour, unsigned short minute, unsigned short second)
        : m_Day(day), m_Month(month), m_Year(year), m_Hour(hour), m_Minute(minute), m_Second(second)
    {
    }
    Day m_Day;
    Month m_Month;
    Year m_Year;
    unsigned short m_Hour;
    unsigned short m_Minute;
    unsigned short m_Second;
};


#endif // DATETIME_H
