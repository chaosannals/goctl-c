include(FetchContent)

function(
    FetchCJSON
)
    FetchContent_Declare(
        cjson
        GIT_REPOSITORY git@github.com:DaveGamble/cJSON.git
        GIT_TAG v1.7.18
        GIT_SHALLOW ON # 浅克隆，git 参数加 --depth=1
        GIT_PROGRESS ON # 打印下载进度
    )

    set(ENABLE_CJSON_TEST OFF)
    set(ENABLE_CJSON_UTILS ON)
    set(BUILD_SHARED_AND_STATIC_LIBS ON)

    FetchContent_MakeAvailable(cjson)

    add_library(libcjson INTERFACE)

    target_include_directories(
        libcjson
        INTERFACE
        ${cjson_SOURCE_DIR}
    )

    target_link_libraries(
        libcjson
        INTERFACE
        cjson-static
        cjson_utils-static
    )
endfunction()
