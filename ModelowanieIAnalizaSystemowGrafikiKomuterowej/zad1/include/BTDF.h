#ifndef BTDF_H
#define BTDF_H
#include "Colour.h"
#include "Info.h"
class BTDF
{
    public:
        BTDF();
        virtual ~BTDF();
        virtual Colour f(const Info& sr, const Vector3Bf& wi, const Vector3Bf& wo) const = 0;
        virtual Colour sample_f(const Info& sr, const Vector3Bf& wo, Vector3Bf& wt) const = 0;
        virtual Colour  rho(const Info& sr, const Vector3Bf& wo) const = 0;

    protected:
    private:
};

#endif // BTDF_H
