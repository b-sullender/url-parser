//
// Copyright (c) 2023 Brian Sullender
// All rights reserved.
//
// This source code is licensed under the terms provided in the README file.
//
// https://github.com/b-sullender/url-parser
//

#ifndef URL_PARSER_H
#define URL_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Maximum scheme length
#define MAX_URL_SCHEME_LEN 32
// Maximum authority length
#define MAX_URL_AUTHORITY_LEN 512
// Maximum port length
#define MAX_URL_PORT_LEN 64
// Maximum path length
#define MAX_URL_PATH_LEN 1024
// Maximum query length
#define MAX_URL_QUERY_LEN 1024
// Maximum fragment length
#define MAX_URL_FRAGMENT_LEN 256

typedef struct URL_PARTS {
    char scheme[MAX_URL_SCHEME_LEN];
    char authority[MAX_URL_AUTHORITY_LEN];
    char port[MAX_URL_PORT_LEN];
    char path[MAX_URL_PATH_LEN];
    char query[MAX_URL_QUERY_LEN];
    char fragment[MAX_URL_FRAGMENT_LEN];
} URL_PARTS;

// ParseURL
// This function parses a URL string
// @URL: The URL string the parse
// @pURL_Parts: A pointer to a URL_PARTS struct to fill
// @return: true on success, false otherwise
bool ParseURL(char* URL, URL_PARTS* pURL_Parts);

// PrintURL
// This function prints each part of a URL_PARTS struct individually,
// and the entire URL on a single line. For testing purposes only
// @pURL_Parts: A pointer to a URL_PARTS struct to print
void PrintURL(struct URL_PARTS* pURL_Parts);

#endif // !URL_PARSER_H
