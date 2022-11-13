/* Copyright (c) 2022 Matheus Oliveira, maolivei A.K.A araggohnxd */

#include <iostream>

int main(int argc, char **argv)
{
    std::string str;

    if (argc == 1)
        str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (size_t i = 1; i < argc; ++i)
        str.append(argv[i]);
    for (std::string::iterator c = str.begin(); c != str.end(); ++c)
        *c = toupper(*c);
    std::cout << str << std::endl;
    return (0);
}
