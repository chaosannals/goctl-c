#include "gen/client.h"

static demo_api_t client = {
    .is_secure = false,
    .host = "127.0.0.1",
    .port = 8888,
    .timeout_s = 10,
};

int main() {
#ifdef WIN32
    // console set code page to utf8.
	system("chcp 65001");
#endif

    request_t req = {
        .name = "me",
    };
    response_t resp;
    if (!demo_api_get_demo(&client, &req, &resp, NULL)) {
        printf("error: %s\n", base_last_error());
        return 1;
    }
    printf("response: %s\n", resp.message);
    free(resp.message); // TODO 内存管理，减少用户自己释放内存。

    return 0;
}
