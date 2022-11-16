/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:45:16 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/16 16:47:56 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>   /* perror */
#include <fstream>  /* ifstream and ofstream classes */
#include <iostream> /* cin, cout, cerr */
#include <sstream>  /* stringstream class */
#include <string>   /* string class */

static int checkUserInput(int argc)
{
    if (argc != 4) {
        if (argc > 4)
            std::cerr << "Too many arguments" << std::endl;
        else if (argc < 4)
            std::cerr << "Too few arguments" << std::endl;
        std::cerr << "Usage: ./sed <filename> <search> <replace>" << std::endl;
        return (-1);
    }
    return (0);
}

static void replaceString(std::string       &subject,
                          std::string const &search,
                          std::string const &replace)
{
    size_t pos = 0;

    if (search.empty())
        return;
    while (true) {
        pos = subject.find(search, pos);
        if (pos == std::string::npos)
            break;
        subject.erase(pos, search.length());
        subject.insert(pos, replace);
        pos += replace.length();
    }
}

static int readInfile(std::string &contents, const char *filename)
{
    std::ifstream     input;
    std::stringstream buffer;

    input.open(filename, std::fstream::in);
    if (input.fail()) {
        std::perror(filename);
        return (-1);
    }
    buffer << input.rdbuf();
    contents = buffer.str();
    input.close();
    return (0);
}

static int writeOutfile(std::string &contents, std::string file_preffix)
{
    std::string   outfile;
    std::ofstream output;

    outfile = file_preffix + ".replace";
    output.open(outfile.c_str(), std::fstream::out | std::fstream::trunc);
    if (output.fail()) {
        std::perror(outfile.c_str());
        return (-1);
    }
    output << contents;
    output.close();
    return (0);
}

int main(int argc, char **argv)
{
    std::string contents;

    if (checkUserInput(argc) != 0)
        return (1);
    if (readInfile(contents, argv[1]) != 0)
        return (1);
    replaceString(contents, argv[2], argv[3]);
    if (writeOutfile(contents, argv[1]) != 0)
        return (1);
    return (0);
}
