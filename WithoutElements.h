#ifndef WITHOUTELEMENTS_H
#define WITHOUTELEMENTS_H

#include <exception>

class WithoutElements : public std::exception
{
public:
    WithoutElements () noexcept {}
    WithoutElements (const WithoutElements&) noexcept = default;
    WithoutElements& operator= (const WithoutElements&) noexcept = default;
    virtual ~WithoutElements() noexcept = default;
    virtual const char* what() const noexcept
    {
        return "Impossible pop";
    }
};
#endif // WITHOUTELEMENTS_H
