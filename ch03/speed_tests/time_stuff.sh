#! /usr/bin/env sh

DTYPES="short int unsigned long"
DTYPES="$DTYPES sc_int\<8\> sc_uint\<19\>"
DTYPES="$DTYPES sc_bigint\<8\> sc_bigint\<100\>"
DTYPES="$DTYPES sc_fixed\<12\,12\>"

echo `date` >times.log

for dtype in $DTYPES; do
    make clean 
    make speed_tests.out ST_DATATYPE=$dtype
    echo "Timing: $dtype" >>times.log
    time --output=times.log --append make run 
done

exit 0;
