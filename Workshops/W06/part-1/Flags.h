// Name: Neron Parmar
// Student ID: 171690217
// File: Flags.h
// Date: 11/1/23

#ifndef SDDS_FLAGS_H
#define SDDS_FLAGS_H

namespace sdds
{
    // Options for displaying the files and directories
    enum class FormatFlags {
        LONG,     // to display in long format
    };

    // Determine the type of filesystem resource
    enum class NodeType {
        DIR,   // Directory
        FILE   // Regular File
    };

    // Options for performing a filesystem operation
    enum class OpFlags {
        RECURSIVE,  // run an operation recursively
    };
}

#endif