/*
 * Copyright (C) 2005 National Association of REALTORS(R)
 *
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, and/or sell copies of the
 * Software, and to permit persons to whom the Software is furnished
 * to do so, provided that the above copyright notice(s) and this
 * permission notice appear in all copies of the Software and that
 * both the above copyright notice(s) and this permission notice
 * appear in supporting documentation.
 */
#define BOOST_FILESYSTEM_VERSION 2
#include <boost/filesystem/path.hpp>
#include "librets/RetsExceptionContext.h"

using namespace librets;
using namespace std;

#undef BOOST_FILESYSTEM_VERSION
#define BOOST_FILESYSTEM_VERSION 3
namespace fs = boost::filesystem;

RetsExceptionContext::RetsExceptionContext()
    : mFileName(""), mLineNumber(0)
{
}

RetsExceptionContext::RetsExceptionContext(const string & fileName,
                                           int lineNumber)
{
    fs::path path(fileName);
    mFileName = path.filename();
    mLineNumber = lineNumber;
}

bool RetsExceptionContext::IsValid() const throw()
{
    return (!mFileName.empty());
}

string RetsExceptionContext::GetFileName() const throw()
{
    return mFileName;
}

int RetsExceptionContext::GetLineNumber() const throw()
{
    return mLineNumber;
}

