
#ifndef BRDF_H
#define BRDF_H

#include "..\Core\MathUtils.h"
#include "..\Core\Color.h"
#include "..\Samplers\Sampler.h"

class BRDF
{
protected:
    Sampler* m_sampler;

public:
    BRDF();

    BRDF(const BRDF& brdf);

    virtual ~BRDF();

    BRDF& operator=(BRDF brdf);

    virtual BRDF* Clone() const;

    void SetSampler(Sampler* sampler);

    virtual Color F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    virtual Color SampleF(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    virtual Color P(const ShadeRecord& record, const Vector& wo) const;
};

#endif