from os.path import join
from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.files import copy, collect_libs
from pathlib import Path
import os

script_dir = os.path.dirname(os.path.realpath(__file__))

class BreakpadSample(ConanFile):
    name = "conan_breakpad_sample"
    version = "0.0.1-1"
    settings = "os", "arch", "build_type", "compiler"
    generators = "CMakeDeps", "CMakeToolchain"
    short_paths = True
    build_policy = "missing"

    
    exports_sources = "CMakeLists.txt", "conanfile.py", "src*", "cmake*", "!build"
    requires = "ms-gsl/4.0.0", "conan_breakpad/0.0.1-1"

        
    def requirements(self):    
        
        if not self.in_local_cache:
            self.requires('gtest/1.14.0')


    def layout(self):
        cmake_layout(self, src_folder=".")
        self.folders.generators = "build"
        self.cpp.build.libdirs = "lib" # write the .libs to the library folder under build
        self.cpp.build.bindirs = "bin" # write the .dll to the bin folder under build

    def generate(self):
        for dep in self.dependencies.values():
            print(dep.cpp_info.libdirs[0])

            copy(self, "*.lib", src=dep.cpp_info.libdirs[0], dst=join(self.cpp.build.libdirs, ""), keep_path=False)  
            copy(self, "*.dll", src=dep.cpp_info.bindirs[0], dst=join(self.cpp.build.bindirs, ""), keep_path=False)
            copy(self, "*.bin", src=dep.cpp_info.bindirs[0], dst=join(self.cpp.build.bindirs, ""), keep_path=False)

        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
