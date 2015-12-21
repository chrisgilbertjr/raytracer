
#include "Samplers\MultiJittered.h"

MultiJittered::MultiJittered()
    : Sampler()
{
    GenerateSamples();
}


MultiJittered::MultiJittered(const int sampleCount)
    : Sampler(sampleCount)
{
    GenerateSamples();
}


MultiJittered::MultiJittered(const int sampleCount, const int setCount)
    : Sampler(sampleCount, setCount)
{
    GenerateSamples();
}


MultiJittered::MultiJittered(const MultiJittered& jittered)
    : Sampler(jittered)
{}


MultiJittered::~MultiJittered() {}


MultiJittered&
MultiJittered::operator=(MultiJittered jittered)
{
    Sampler::operator=(jittered);
    return *this;
}



Sampler*
MultiJittered::Clone() const
{
    return static_cast<Sampler*>(new MultiJittered(*this));
}


void
MultiJittered::GenerateSamples()
{
    /// @TODO:
}