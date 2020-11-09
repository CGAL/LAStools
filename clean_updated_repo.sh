#!/bin/sh

git rm -f -r bin/

git rm -f -r data/

git rm -f -r example_batch_scripts/

git rm -f -r LASlib/example/
git rm -f -r LASlib/lib/
git rm -f LASlib/CMakeLists.txt

git rm -f -r LASzip/cmake/
git rm -f -r LASzip/example/
git rm -f -r LASzip/stl/
git rm -f LASzip/CMakeLists.txt
git rm -f LASzip/DEMzip.dsp
git rm -f LASzip/laszip_api_version.h.in

git rm -f -r src/

git rm -f HALL_OF_SHAME.txt
git rm -f lastools.dsw
git rm -f Makefile
git rm -f README.txt
