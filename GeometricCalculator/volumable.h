#ifndef VOLUMABLE_H
#define VOLUMABLE_H

class Volumable
{
public:
    Volumable();
    virtual double CalculateVolume() const = 0;
};

#endif // VOLUMABLE_H
