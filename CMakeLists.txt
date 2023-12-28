cmake_minimum_required(VERSION 3.5)

project(AsyncMsgDemo)

set(SOURCES
    core/src/Common/MessageRouter/MessageRouter.cpp
    core/src/Common/PayloadRepo/PayloadRepo.cpp
    core/src/MsgRunner/MsgRunner.cpp
    core/src/Receiver/Receiver.cpp
    core/src/Sender/Sender.cpp
    core/src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/core/include
    ${CMAKE_SOURCE_DIR}/core/src
)