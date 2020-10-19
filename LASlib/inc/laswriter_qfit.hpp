/*
===============================================================================

  FILE:  laswriter_qfit.hpp
  
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
  
    23 December 2011 -- created after by new OGIO laptop bagpack arrived 
  
===============================================================================
*/
#ifndef LAS_WRITER_QFIT_HPP
#define LAS_WRITER_QFIT_HPP

#include "laswriter.hpp"

#include <stdio.h>

class ByteStreamOut;

class LASwriterQFIT : public LASwriter
{
public:

  las_BOOL refile(FILE* file);

  las_BOOL open(const char* file_name, const LASheader* header, I32 version=48, U32 io_buffer_size=65536);
  las_BOOL open(FILE* file, const LASheader* header, I32 version=48);
  las_BOOL open(ByteStreamOut* stream, const LASheader* header, I32 version=48);

  las_BOOL write_point(const LASpoint* point);
  las_BOOL chunk() { return FALSE; };

  las_BOOL update_header(const LASheader* header, las_BOOL use_inventory=FALSE, las_BOOL update_extra_bytes=FALSE);
  I64 close(las_BOOL update_npoints=TRUE);

  LASwriterQFIT();
  ~LASwriterQFIT();

private:
  ByteStreamOut* stream;
  FILE* file;
  I32 version;
  las_BOOL endian_swap;
  las_BOOL rescale_reoffset;
  I32 buffer[14];
  I32 scan_azimuth_array_offset;
  I32 pitch_array_offset;
  I32 roll_array_offset;
  I32 pulse_width_array_offset;
};

#endif
