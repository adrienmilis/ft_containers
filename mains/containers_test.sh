#!/bin/sh
GREEN='\033[0;32m'
RED='\033[0;31m'
BOLD=$(tput bold)
NORMAL=$(tput sgr0)
NC='\033[0m'

##### MAP #####

echo "*** MAP ***"
# compile and get outputs from stl and ft versions
make ft_map
./a.out > ft_map
make stl_map
./a.out > stl_map

# get times
FT_TIME=$(tail -1 ft_map)
STL_TIME=$(tail -1 stl_map)

# erase times from outputs
sed '$d' ft_map > ft_map
sed '$d' stl_map > stl_map

# diff outputs
DIFF=$(diff ft_map stl_map)
echo $DIFF
rm ft_map stl_map

echo -n "DIFF: "
if [ -z "$DIFF" ]
then echo -e "$GREEN$BOLD""OK"
echo -n $NORMAL

    if [[ FT_TIME -lt STL_TIME ]]
    then
    div=`echo "scale=2 ; $STL_TIME / $FT_TIME" | bc`
    echo "ft is $div times faster: $FT_TIME""ns vs $STL_TIME""ns"
    else
    div=`echo "scale=2 ; $FT_TIME / $STL_TIME" | bc`
    echo "std is $div times faster: $STL_TIME""ns vs $FT_TIME""ns"
    fi

else echo -e "$RED$BOLD""KO"
echo -n $NORMAL
fi

##### STACK #####

echo
echo "*** STACK ***"
# compile and get outputs from stl and ft versions
make ft_stack
./a.out > ft_stack
make stl_stack
./a.out > stl_stack

# get times
FT_TIME=$(tail -1 ft_stack)
STL_TIME=$(tail -1 stl_stack)

# erase times from outputs
sed '$d' ft_stack > ft_stack
sed '$d' stl_stack > stl_stack

# diff outputs
DIFF=$(diff ft_stack stl_stack)
echo $DIFF
rm ft_stack stl_stack

echo -n "DIFF: "
if [ -z "$DIFF" ]
then echo -e "$GREEN$BOLD""OK"
echo -n $NORMAL

    if [[ FT_TIME -lt STL_TIME ]]
    then
    div=`echo "scale=2 ; $STL_TIME / $FT_TIME" | bc`
    echo "ft is $div times faster: $FT_TIME""ns vs $STL_TIME""ns"
    else
    div=`echo "scale=2 ; $FT_TIME / $STL_TIME" | bc`
    echo "std is $div times faster: $STL_TIME""ns vs $FT_TIME""ns"
    fi

else echo -e "$RED$BOLD""KO"
echo -n $NORMAL
fi

##### VECTOR #####

echo
echo "*** VECTOR ***"
# compile and get outputs from stl and ft versions
make ft_vector
./a.out > ft_vector
make stl_vector
./a.out > stl_vector

# get times
FT_TIME=$(tail -1 ft_vector)
STL_TIME=$(tail -1 stl_vector)

# erase times from outputs
sed '$d' ft_vector > ft_vector
sed '$d' stl_vector > stl_vector

# diff outputs
DIFF=$(diff ft_vector stl_vector)
echo $DIFF
rm ft_vector stl_vector

echo -n "DIFF: "
if [ -z "$DIFF" ]
then echo -e "$GREEN$BOLD""OK"
echo -n $NORMAL

    if [[ FT_TIME -lt STL_TIME ]]
    then
    div=`echo "scale=2 ; $STL_TIME / $FT_TIME" | bc`
    echo "ft is $div times faster: $FT_TIME""ns vs $STL_TIME""ns"
    else
    div=`echo "scale=2 ; $FT_TIME / $STL_TIME" | bc`
    echo "std is $div times faster: $STL_TIME""ns vs $FT_TIME""ns"
    fi

else echo -e "$RED$BOLD""KO"
echo -n $NORMAL
fi