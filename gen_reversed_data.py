#!/usr/bin/python

import random

data_list = list(range(0, 0x3FFFFF))
data_list.reverse()

data_str = ", ".join(str(elem) for elem in data_list)

with open("quick_sort_data.h", "w") as f:
    f.write("auto test_data = std::to_array<int>({ " + data_str + " });")
