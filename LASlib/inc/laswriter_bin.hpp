/*
===============================================================================

  FILE:  laswriter_bin.hpp
  
  CONTENTS:
  
    Writes LIDAR points from to ASCII through on-the-fly conversion from LAS.

  PROGRAMMERS:

    martin.isenburg@rapidlasso.com  -  http://rapidlasso.com

  COPYRIGHT:

    (c) 2007-2014, martin isenburg, rapidlasso - fast tools to catch reality

    This is free software; you can redistribute and/or modify it under the
    terms of the GNU Lesser General Licence as published by the Free Software
    Foundation. See the LICENSE.txt file for more information.

    This software is distributed WITHOUT ANY WARRANTY and without even the
    implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  
  CHANGE HISTORY:
  
    13 October 2014 -- changed default IO buffer size with setvbuf() to 262144
    5 November 2011 -- changed default IO buffer size with setvbuf() to 65536
    5 September 2011 -- created after sampling grapes in the sommerhausen hills  
  
===============================================================================
*/
#ifndef LAS_WRITER_BIN_HPP
#define LAS_WRITER_BIN_HPP

#include "laswriter.hpp"

#include <stdio.h>

class ByteStreamOut;

class LASwriterBIN : public LASwriter
{
public:

  las_BOOL refile(FILE* file);

  las_BOOL open(const char* file_name, const LASheader* header, const char* version, U32 io_buffer_size=LAS_TOOLS_IO_OBUFFER_SIZE );
  las_BOOL open(FILE* file, const LASheader* header, const char* version);
  las_BOOL open(ByteStreamOut* stream, const LASheader* header, const char* version);

  las_BOOL write_point(const LASpoint* point);
  las_BOOL chunk() { return FALSE; };

  las_BOOL update_header(const LASheader* header, las_BOOL use_inventory=FALSE, las_BOOL update_extra_bytes=FALSE);
  I64 close(las_BOOL update_npoints=TRUE);

  LASwriterBIN();
  ~LASwriterBIN();

private:
  ByteStreamOut* stream;
  FILE* file;
  U32 version;
  I32 units;
  F64 origin_x;
  F64 origin_y;
  F64 origin_z;
};

#endif
