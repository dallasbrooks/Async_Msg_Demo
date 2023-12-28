#include <iostream>

#include "Constants.h"

#include "MsgRunner/MsgRunner.h"

int main(int argc, char *argv[])
{
    msg_runner::MsgRunner runner;
    const int ret = runner.Run();
    if (OKAY != ret)
    {
        std::cout << "Runner failed" << std::endl;
    }
    return 0;
}