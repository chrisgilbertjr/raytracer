
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

static int _RandInt()
{
    return rand();
}

static real
_RandReal()
{
    return ((real)_RandInt()) / RAND_MAX;
}

static real
_RandReal(int l, float h)
{
    return (_RandReal() * (h - l) + l);
}

static int
_RandInt(int l, int h)
{
    return ((int) (_RandReal(0, h - l + 1) + 1));
}


void
MultiJittered::GenerateSamples()
{
    int num_samples = m_sampleCount;
    int num_sets = m_setCount;

    
	int n = (int)sqrt((float)num_samples);
	float subcell_width = 1.0 / ((float) num_samples);
	
	// fill the samples array with dummy points to allow us to use the [ ] notation when we set the 
	// initial patterns
	
	Vector fill_point;
	for (int j = 0; j < num_samples * num_sets; j++)
		m_samples.Push(fill_point);
		
	// distribute points in the initial patterns
	
	for (int p = 0; p < num_sets; p++) 
		for (int i = 0; i < n; i++)		
			for (int j = 0; j < n; j++) {
				m_samples[i * n + j + p * num_samples].x = (i * n + j) * subcell_width + _RandReal(0, subcell_width);
				m_samples[i * n + j + p * num_samples].y = (j * n + i) * subcell_width + _RandReal(0, subcell_width);
			}
	
	// shuffle x coordinates
	
	for (int p = 0; p < num_sets; p++) 
		for (int i = 0; i < n; i++)		
			for (int j = 0; j < n; j++) {
				int k = _RandInt(j, n - 1);
				float t = m_samples[i * n + j + p * num_samples].x;
				m_samples[i * n + j + p * num_samples].x = m_samples[i * n + k + p * num_samples].x;
				m_samples[i * n + k + p * num_samples].x = t;
			}

	// shuffle y coordinates
	
	for (int p = 0; p < num_sets; p++)
		for (int i = 0; i < n; i++)		
			for (int j = 0; j < n; j++) {
				int k = _RandInt(j, n - 1);
				float t = m_samples[j * n + i + p * num_samples].y;
				m_samples[j * n + i + p * num_samples].y = m_samples[k * n + i + p * num_samples].y;
				m_samples[k * n + i + p * num_samples].y = t;
		}




    //int s = (int)sqrtf((float)m_sampleCount);
    //float subcellWidth = 1.f / ((float)m_sampleCount);

    //Vector point(0.f);

    ///// init the samples with dummmy points
    //for (int i = 0; i < m_sampleCount * m_setCount; ++i)
    //{
    //    m_samples.Push(point);
    //}

    ///// initial points
    //for (int c = 0; c < m_setCount; ++c)
    //{
    //    for (int i = 0; i < s; ++i)
    //    {
    //        for (int j = 0; j < s; ++j)
    //        {
    //            real t = RandReal(0, subcellWidth);
    //            real a = RandReal(0, subcellWidth);
	//			m_samples[i * s + j + c * m_sampleCount].x = (i * s + j) * subcellWidth + RandReal(0, subcellWidth);
    //            real b = RandReal(0, subcellWidth);
	//			m_samples[i * s + j + c * m_sampleCount].y = (j * s + i) * subcellWidth + RandReal(0, subcellWidth);
    //            fprintf(stdout, "%0.7f - %0.7f - %0.7f\n", subcellWidth, a, b);
    //            //int i0 = i * s + j;
    //            //int index = i0+ c * m_sampleCount;
    //            //real jitter = i0 * subcellWidth;
    //            //m_samples[index].Set(jitter + RandReal(0, subcellWidth), jitter + RandReal(0, subcellWidth), 0.f);
    //        }
    //    }
    //}

    ///// shuffle x coords
    //for (int c = 0; c < m_setCount; ++c)
    //{
    //    for (int i = 0; i < s; ++i)
    //    {
    //        for (int j = 0; j < s; ++j)
    //        {
    //            int k = RandInt(j, s-1);
    //            float t = m_samples[i * s + j + c * m_sampleCount].x;
    //            m_samples[i * s + j + c * m_sampleCount].x = m_samples[i * s + k + c * m_sampleCount].x;
    //            m_samples[i * s + k + c * m_sampleCount].x = t;
    //            //int ij = i * s + j + c * m_sampleCount;
    //            //int ik = i * s + k + c * m_sampleCount;
    //            //real t = m_samples[ij].x;
    //            //m_samples[ij].x = m_samples[ik].x;
    //            //m_samples[ik].x = t;
    //        }
    //    }
    //}

    ///// shuffle y coords
    //for (int c = 0; c < m_setCount; ++c)
    //{
    //    for (int i = 0; i < s; ++i)
    //    {
    //        for (int j = 0; j < s; ++j)
    //        {
    //            int k = RandInt(j, s-1);
    //            float t = m_samples[i * s + j + c * m_sampleCount].x;
    //            m_samples[i * s + j + c * m_sampleCount].y = m_samples[i * s + k + c * m_sampleCount].y;
    //            m_samples[i * s + k + c * m_sampleCount].y = t;
    //            //int ij = i * s + j + c * m_sampleCount;
    //            //int ik = i * s + k + c * m_sampleCount;
    //            //real t = m_samples[ij].y;
    //            //m_samples[ij].y = m_samples[ik].y;
    //            //m_samples[ik].y = t;
    //        }
    //    }
    //}
}