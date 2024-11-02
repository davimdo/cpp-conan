release:
	conan profile detect --force
	conan install . --build=missing -s build_type=Release -c tools.system.package_manager:mode=install
	cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=generators/conan_toolchain.cmake -Bbuild/Release .
	cmake --build build/Release
