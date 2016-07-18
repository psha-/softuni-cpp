#ifndef SURFACEABLE_H
#define SURFACEABLE_H

class Surfaceable
{
public:
    Surfaceable();
    virtual double CalculateSurface() const = 0;
};

#endif // SURFACEABLE_H
