cmake_minimum_required(VERSION 3.16)
include($ENV{IDF_PATH}/tools/cmake/utilities.cmake)

set(SRCS
    "src/audio_codec.cc"
    "src/no_audio_codec.cc"
    "src/display.cc"
    "src/protocols/protocol.cc"
    "src/iot/thing.cc"
    "src/iot/thing_manager.cc"
    "src/application.cc"
    "src/version.cc"
    "src/settings.cc"
    "src/background_task.cc"
    "src/system_reset.cc"
    "src/board.cc"
    "src/wifi_board.cc"
)

# 协议动态添加
if(CONFIG_CONNECTION_TYPE_MQTT_UDP)
    list(APPEND SRCS "src/protocols/mqtt_protocol.cc")
elseif(CONFIG_CONNECTION_TYPE_WEBSOCKET)
    list(APPEND SRCS "src/protocols/websocket_protocol.cc")
endif()

# IoT 文件扫描（修复点）
file(GLOB IOT_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/iot/things/*.cc"
)
list(APPEND SRCS ${IOT_SOURCES})

# 音频处理模块
if(CONFIG_USE_AUDIO_PROCESSOR)
    list(APPEND SRCS "src/audio_processing/audio_processor.cc")
endif()
if(CONFIG_USE_WAKE_WORD_DETECT)
    list(APPEND SRCS "src/audio_processing/wake_word_detect.cc")
endif()

# 语言配置
if(CONFIG_LANGUAGE_ZH_CN)
    set(LANG_DIR "zh-CN")
elseif(CONFIG_LANGUAGE_ZH_TW)
    set(LANG_DIR "zh-TW")
elseif(CONFIG_LANGUAGE_EN_US)
    set(LANG_DIR "en-US")
elseif(CONFIG_LANGUAGE_JA_JP)
    set(LANG_DIR "ja-JP")
endif()

set(LANG_JSON "${CMAKE_CURRENT_SOURCE_DIR}/assets/${LANG_DIR}/language.json")
set(LANG_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/assets/lang_config.h")

# 资源文件扫描（修复点）
file(GLOB LANG_SOUNDS
    "${CMAKE_CURRENT_SOURCE_DIR}/assets/${LANG_DIR}/*.p3"
)
file(GLOB COMMON_SOUNDS
    "${CMAKE_CURRENT_SOURCE_DIR}/assets/common/*.p3"
)

idf_component_register(
    SRCS ${SRCS}
    EMBED_FILES
        ${LANG_SOUNDS}
        ${COMMON_SOUNDS}
        "${LANG_HEADER}"
    INCLUDE_DIRS
        "src"
        "src/protocols"
        "src/audio_processing"
        "${CMAKE_CURRENT_SOURCE_DIR}"
    PRIV_REQUIRES spi_flash esp_app_format esp-opus esp-opus-encoder esp-wifi-connect esp_codec_dev esp-dsp esp-sr
)

# 生成规则
add_custom_command(
    OUTPUT ${LANG_HEADER}
    COMMAND ${PYTHON}
        "${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_lang.py"
        --input "${LANG_JSON}"
        --output "${LANG_HEADER}"
    DEPENDS
        "${LANG_JSON}"
        "${CMAKE_CURRENT_SOURCE_DIR}/scripts/gen_lang.py"
    COMMENT "Generating language config: ${LANG_DIR}"
)

add_custom_target(lang_header ALL
    DEPENDS ${LANG_HEADER}
)
add_dependencies(${COMPONENT_LIB} lang_header)
