#!/bin/sh

make
./ft_vector > ft
./std_vector > std
diff ft std
rm ft std