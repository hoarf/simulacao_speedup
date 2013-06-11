#!/bin/bash
# Scheduler - Nicolas Silveira Kagami
# How to use: bash scheduler.sh 1,2,4 ...

OUTPUT_FILE="Results.csv"
EXE_NAME="./avg_var"
LIST=`echo "$1,"`
SAFE="1"
i=1

rm -f $OUTPUT_FILE
while [ $SAFE != "0" ]
do
    PROC_NUM=`echo "$LIST" | cut -d, -f${i}`
    if [[ "$PROC_NUM" =~ ^[0-9]+$ ]]  
    then
        BEG_TIME=`date +'%s.%N'`
        mpirun -np $PROC_NUM $EXE_NAME >/dev/null
        END_TIME=`date +'%s.%N'`
        RUN_TIME=`bc <<< "scale=9;$END_TIME - $BEG_TIME"`
        echo "$PROC_NUM,$RUN_TIME" >> $OUTPUT_FILE
    else
        SAFE="0"
    fi
    let "i=i+1"
done
