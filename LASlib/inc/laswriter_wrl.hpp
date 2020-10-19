/*
===============================================================================

  FILE:  laswriter_wrl.hpp
  
  CONTENTS:
  
    Writes LIDAR points to VRML through on-the-fly conversion from LAS.

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
  
    26 August 2012 -- after a slice of cake at the Volksfest Sommerhausen
  
===============================================================================
*/
#ifndef LAS_WRITER_WRL_HPP
#define LAS_WRITER_WRL_HPP

#include "laswriter.hpp"

#include <stdio.h>

class LASwriterWRL : public LASwriter
{
public:

  las_BOOL open(const CHAR* file_name, const LASheader* header, const CHAR* parse_string=0);
  las_BOOL open(FILE* file, const LASheader* header, const CHAR* parse_string=0);

  las_BOOL write_point(const LASpoint* point);
  las_BOOL chunk() { return FALSE; };

  las_BOOL update_header(const LASheader* header, las_BOOL use_inventory=FALSE, las_BOOL update_extra_bytes=FALSE);
  I64 close(las_BOOL update_npoints=TRUE);

  LASwriterWRL();
  ~LASwriterWRL();

private:
  las_BOOL close_file;
  FILE* file;
  const LASheader* header;
  CHAR printstring[512];
  U8* rgb;
  I32 rgb_alloc;
};

#endif
