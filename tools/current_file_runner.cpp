#include <filesystem>
#include <iostream>
#include <string>

#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Open a .cpp file before running Current File.\n";
        return 1;
    }

    const std::filesystem::path source = argv[1];
    if (source.extension() != ".cpp" || !std::filesystem::is_regular_file(source)) {
        std::cerr << "Current File only runs .cpp source files.\n";
        return 1;
    }

    const std::filesystem::path output_directory =
        std::filesystem::current_path() / "cmake-build-current";
    const std::filesystem::path output = output_directory / source.stem();
    std::filesystem::create_directories(output_directory);

    const pid_t compiler = fork();
    if (compiler == -1) {
        std::cerr << "Could not start the C++ compiler.\n";
        return 1;
    }

    if (compiler == 0) {
        execl(
            "/usr/bin/c++",
            "c++",
            "-std=c++17",
            "-Wall",
            "-Wextra",
            "-pedantic",
            source.c_str(),
            "-o",
            output.c_str(),
            nullptr
        );
        _exit(127);
    }

    int compiler_status = 0;
    if (waitpid(compiler, &compiler_status, 0) == -1 ||
        !WIFEXITED(compiler_status) || WEXITSTATUS(compiler_status) != 0) {
        return 1;
    }

    execl(output.c_str(), output.filename().c_str(), nullptr);
    std::cerr << "Could not start the compiled program.\n";
    return 1;
}
