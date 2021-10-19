make time
ft_time=`./time_ft_vector`
std_time=`./time_std_vector`

if [[ ft_time -lt std_time ]]
then
div=`echo "scale=2 ; $std_time / $ft_time" | bc`
echo "ft is $div times faster: $ft_time""ns vs $std_time""ns"
else
div=`echo "scale=2 ; $ft_time / $std_time" | bc`
echo "std is $div times faster: $std_time""ns vs $ft_time""ns"
fi
