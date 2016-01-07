
#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>

/// output of the raytraced image
enum Output
{
    EXPORT_BMP = 0,
};

/// output options for the raytraced image
typedef struct OutputOptions
{
    Output output;        /// the raytraced image output
    std::string filename; /// the filename of the output
} OutputOptions;


/// convenience function for output option creation
inline OutputOptions
Options(Output output, std::string filename)
{
    return { output, filename };
}

/// convenience function for output option creation
inline OutputOptions
Options(Output output, const char* filename)
{
    return { output, std::string(filename) };
}

#endif