FROM debian:12

RUN apt update && apt install -y build-essential cmake python3-pip pkg-config
RUN pip3 install conan --break-system-packages

WORKDIR /app
COPY . /app
RUN rm -rf build && rm -rf CMakeUserPresets.json
RUN conan profile detect --force && conan install . --build=missing -s build_type=Release -c tools.system.package_manager:mode=install
RUN cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=generators/conan_toolchain.cmake -Bbuild/Release .
RUN cmake --build build/Release
