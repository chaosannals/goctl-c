add_executable(demo)

target_sources(
    demo
    PRIVATE
    "gen/base.c"
    "gen/message.c"
    "gen/client.c"
    "main.c"
)

set_target_properties(
    demo
    PROPERTIES
    C_STANDARD 11
)

if (MSVC)
    message(STATUS "cl compile source is utf-8.")
    target_compile_options(
        demo
        PRIVATE
        /utf-8
    )
endif()


target_link_libraries(
    demo
    PUBLIC
    libcjson
    CURL::libcurl
)
