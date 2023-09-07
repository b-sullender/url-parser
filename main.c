
#include "url-parser.h"

int main()
{
    URL_PARTS* url_parts = (URL_PARTS*)malloc(sizeof(URL_PARTS));
    if (url_parts == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    // ----------------- //
    // Valid URL testing //
    // ----------------- //

    ParseURL("http://sullewarehouse.com/login", url_parts);
    PrintURL(url_parts);
    printf("%s", "\n");

    ParseURL("https://sullewarehouse.com:1000/login", url_parts);
    PrintURL(url_parts);
    printf("%s", "\n");

    ParseURL("https://sullewarehouse.com:1000/api/get?username=myuser", url_parts);
    PrintURL(url_parts);
    printf("%s", "\n");

    ParseURL("sullewarehouse.com/register", url_parts);
    PrintURL(url_parts);
    printf("%s", "\n");

    ParseURL("http://[2001:0db8:85a3:0000:0000:8a2e:0370:7334]/newpage", url_parts);
    PrintURL(url_parts);
    printf("%s", "\n");

    ParseURL("https://[2001:0db8:85a3:0000:0000:8a2e:0370:7334]:2678/blog", url_parts);
    PrintURL(url_parts);
    printf("%s", "\n");

    return 0;
}
