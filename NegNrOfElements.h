#ifndef NEGNROFELEMENTS_H
#define NEGNROFELEMENTS_H

#include <exception>

class NegNrOfElements : public std::exception
{
public:
    NegNrOfElements () noexcept {}
    NegNrOfElements (const NegNrOfElements&) noexcept = default;
    NegNrOfElements& operator= (const NegNrOfElements&) noexcept = default;
    virtual ~NegNrOfElements() noexcept = default;
    virtual const char* what() const noexcept
    {
        return "Negative number";
    }
};
#endif // NEGNROFELEMENTS_H
