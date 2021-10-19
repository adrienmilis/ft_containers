#!/bin/sh
GREEN='\033[0;32m'
RED='\033[0;31m'
BOLD=$(tput bold)
NORMAL=$(tput sgr0)
NC='\033[0m'

make
./ft_vector > ft
./std_vector > std
diff=`diff ft std`

if [ -z "$diff" ]
then echo -e "$GREEN$BOLD""DIFF SUCCESS"
echo -n $NORMAL
bash time_ft_std.sh
else echo -e "$RED$BOLD""DIFF FAIL\n"
echo -n $NORMAL
echo $diff
fi
rm ft std ft_vector std_vector time_ft_vector time_std_vector