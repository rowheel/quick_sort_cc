import random

from SCons.Environment import Environment


def generateData(target, data):
    dataString = ",".join(str(element) for element in data)
    codeContent = """#include <array>

inline auto testData = std::array<int, {}>({{{}}});
""".format(len(data), dataString)

    for tar in target:
        with open(str(tar), "w") as f:
            f.write(codeContent)


def generateRandomData(target, source, env):
    data = list(range(0, 0xFFFF))
    random.shuffle(data)

    generateData(target, data)


def generateReversedData(target, source, env):
    data = list(range(0, 0xFFFF))
    data.reverse()

    generateData(target, data)


env = Environment()
env.Command("quick_sort_data.hpp", None, generateRandomData)
env.Command("quick_sort", "quick_sort.cpp", "clang++ -o $TARGET $SOURCE")
