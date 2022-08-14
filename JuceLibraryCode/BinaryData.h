/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   blueToggle_png;
    const int            blueToggle_pngSize = 59816;

    extern const char*   brownToggle_png;
    const int            brownToggle_pngSize = 59734;

    extern const char*   orangeToggle_png;
    const int            orangeToggle_pngSize = 58265;

    extern const char*   knobOne_png;
    const int            knobOne_pngSize = 178191;

    extern const char*   knobTwo_png;
    const int            knobTwo_pngSize = 146036;

    extern const char*   background_png;
    const int            background_pngSize = 4444874;

    extern const char*   README_md;
    const int            README_mdSize = 14178;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 7;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
