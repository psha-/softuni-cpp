#ifndef DATE_H
#define DATE_H

// The following are necessary in order to not reorder the Date constructor arguments
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

struct Date
{
    Date(const Day& day, const Month& month, const Year& year)
        : m_Day(day), m_Month(month), m_Year(year)
    {
    }
    Day m_Day;
    Month m_Month;
    Year m_Year;
};

#endif // DATE_H
