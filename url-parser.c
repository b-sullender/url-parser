
#include "url-parser.h"

bool ParseURL(char* URL, URL_PARTS* pURL_Parts)
{
    int i;
    unsigned char c;
    bool b = false;

    // Clear the data
    memset(pURL_Parts, 0, sizeof(URL_PARTS));

    // Setup our parser pointer
    char* string = URL;

    // Check for the authority preceding double slash
    char* authority = strstr(string, "//");
    if (authority == NULL) {
        authority = string;
    }
    else
    {
        // Parse the sheme
        i = 0;
        while (string < authority)
        {
            unsigned char c = *string;
            if (c == ':') {
                // End of scheme
                break;
            }
            if (c == '/') {
                // End of scheme
                break;
            }
            // Check for overflow
            if (i == (MAX_URL_SCHEME_LEN - 1)) {
                return false;
            }
            pURL_Parts->scheme[i] = c;
            string++;
            i++;
        }

        // Skip the slashes
        authority += 2;
    }

    c = *authority;
    if (c == '[') {
        b = true;
        authority++;
    }

    // Parse the authority
    i = 0;
    while ((c = *authority) != 0)
    {
        // Skip spaces
        if (c == ' ') {
            authority++;
            continue;
        }
        // Check for path
        if (c == '/') {
            break;
        }
        // Check for port number
        if (c == ':') {
            // Check if bracket used (IPv6)
            if (!b) {
                break;
            }
        }
        // Check for query
        if (c == '?') {
            break;
        }
        // Check for fragment
        if (c == '#') {
            break;
        }
        // Should we check for closing bracket?
        if (b) {
            if (c == ']') {
                authority++;
                break;
            }
        }
        // Check for overflow
        if (i == (MAX_URL_AUTHORITY_LEN - 1)) {
            return false;
        }
        pURL_Parts->authority[i] = c;
        authority++;
        i++;
    }

    // Switch back to string variable
    string = authority;

    // Check for a port number
    if (*string == ':')
    {
        string++;
        // Parse the port number
        i = 0;
        while ((c = *string) != 0)
        {
            // Check for path
            if (c == '/') {
                break;
            }
            // Check for query
            if (c == '?') {
                break;
            }
            // Check for fragment
            if (c == '#') {
                break;
            }
            // Check for overflow
            if (i == (MAX_URL_PORT_LEN - 1)) {
                return false;
            }
            pURL_Parts->port[i] = c;
            string++;
            i++;
        }
    }

    // Check for a path
    if (*string == '/')
    {
        // Parse the path
        i = 0;
        while ((c = *string) != 0)
        {
            // Check for query
            if (c == '?') {
                break;
            }
            // Check for fragment
            if (c == '#') {
                break;
            }
            // Check for overflow
            if (i == (MAX_URL_PATH_LEN - 1)) {
                return false;
            }
            pURL_Parts->path[i] = c;
            string++;
            i++;
        }
    }

    // Check for a query
    if (*string == '?')
    {
        // Parse the query
        i = 0;
        while ((c = *string) != 0)
        {
            // Check for fragment
            if (c == '#') {
                break;
            }
            // Check for overflow
            if (i == (MAX_URL_QUERY_LEN - 1)) {
                return false;
            }
            pURL_Parts->query[i] = c;
            string++;
            i++;
        }
    }

    // Check for a fragment
    if (*string == '#')
    {
        // Parse the fragment
        i = 0;
        while ((c = *string) != 0)
        {
            // Check for overflow
            if (i == (MAX_URL_FRAGMENT_LEN - 1)) {
                return false;
            }
            pURL_Parts->fragment[i] = c;
            string++;
            i++;
        }
    }

    return true;
}

void PrintURL(struct URL_PARTS* pURL_Parts)
{
    // Safety check
    if (pURL_Parts == NULL) {
        fprintf(stderr, "%s\n", "PrintURL Error: Parameter 'pURL_Parts' is NULL");
        return;
    }

    // Print each individually
    printf("Scheme: %s\nAuthority: %s\nPort: %s\nPath: %s\nQuery: %s\nFragment: %s\n",
        pURL_Parts->scheme, pURL_Parts->authority, pURL_Parts->port,
        pURL_Parts->path, pURL_Parts->query, pURL_Parts->fragment);

    // Print as a single URL
    if (strlen(pURL_Parts->scheme) != 0) {
        printf("%s://%s", pURL_Parts->scheme, pURL_Parts->authority);
    } else if (strlen(pURL_Parts->authority) != 0) {
        printf("%s", pURL_Parts->authority);
    }
    if (strlen(pURL_Parts->port) != 0) {
        printf(":%s", pURL_Parts->port);
    }
    if (strlen(pURL_Parts->path) != 0) {
        printf("%s", pURL_Parts->path);
    }
    if (strlen(pURL_Parts->query) != 0) {
        printf("%s", pURL_Parts->query);
    }
    if (strlen(pURL_Parts->fragment) != 0) {
        printf("%s", pURL_Parts->fragment);
    }

    printf("%s", "\n");
}

