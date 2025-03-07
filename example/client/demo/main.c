﻿#include "gen/client.h"

static demo_api_t client = {
    .is_secure = false,
    .host = "127.0.0.1",
    .port = 8888,
    .timeout_s = 10,
};

int main() {

    request_t req = {
        .name = "me",
    };
    response_t resp;
    if (!demo_api_get_demo(&client, &req, &resp, NULL)) {
        printf("error: %s\n", base_last_error());
        return 1;
    }
    printf("response: %s\n", resp.message);

    return 0;
}
