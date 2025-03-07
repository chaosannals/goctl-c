#include <stdlib.h>
#include <cJSON.h>
#include "base.h"
#include "message.h"

// headers


// message to json
char* response_to_json(response_t *message) {
    char* text = NULL;
    cJSON* v_root = cJSON_CreateObject();
    { 
        cJSON* v_message = cJSON_CreateString((*message).message);
        cJSON_AddItemToObject(v_root, "message", v_message);
    }

    text = cJSON_Print(v_root);
end:
    cJSON_Delete(v_root);
    return text;
}


// message from json
bool response_from_json(response_t *message, char* body) {
    cJSON* v_root = cJSON_Parse(body);
    if (cJSON_IsObject(v_root)) { 
        cJSON* v_message = cJSON_GetObjectItemCaseSensitive(v_root, "message");
        if (cJSON_IsString(v_message) && (NULL != v_message->valuestring)) {
            (*message).message = strdup(v_message->valuestring);
        }
    }

exit_free:
    cJSON_free(v_root);
    return true;
}
