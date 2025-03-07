include(FetchContent)

function(
    FetchCURL
)
    FetchContent_Declare(
        curl
        GIT_REPOSITORY git@github.com:curl/curl.git
        GIT_TAG curl-8_11_1
        GIT_SHALLOW ON # 浅克隆，git 参数加 --depth=1
        GIT_PROGRESS ON # 打印下载进度
    )

    set(CURL_STATIC_CRT ON)
    set(CURL_USE_OPENSSL ON)
    set(BUILD_SHARED_LIBS OFF)
    set(BUILD_STATIC_LIBS ON)
    set(BUILD_STATIC_CURL ON)
    set(BUILD_CURL_EXE OFF)
    set(BUILD_EXAMPLES OFF)
    set(BUILD_TESTING OFF)
    set(BUILD_LIBCURL_DOCS OFF)
    set(BUILD_MISC_DOCS OFF)

    FetchContent_MakeAvailable(curl)
endfunction()
