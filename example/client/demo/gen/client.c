#include "client.h"
#include <stdlib.h>
#include <string.h>

// define

bool demo_api_get_demo(demo_api_t *client, request_t* req, response_t *resp, const char *body) {
    //request headers
    curl_slist_t * headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    
    // request path
    char *path = "/from/:name";
     path = replace_substr(path, ":name", req->name); 

    // request
    base_request_t request = {
        .method = HTTP_METHOD_GET,
        .headers = headers,
        .body = body,
        .body_size = body ? strlen(body) : 0,
        .path = path,
    };
    base_response_t response;
    if (!base_client_request(client, &request, &response)) {
        return false;
    }

    // response body
    if (!response_from_json(resp, response.body)) {
        return false;
    }

    base_response_free(&response);

    
    
    return true;
}
