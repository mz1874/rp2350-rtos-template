set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(${ProjectName}
    main.c
)

pico_enable_stdio_uart(${ProjectName} 0)
# 开启默认的UART通讯
pico_enable_stdio_usb(${ProjectName} 1)


target_include_directories(${ProjectName} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${ProjectName} 
    pico_stdlib 
    FreeRTOS-Kernel-Heap4 
    )

pico_add_extra_outputs(${ProjectName})