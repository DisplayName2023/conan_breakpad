from os.path import join
from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.files import copy
from pathlib import Path
import os

script_dir = os.path.dirname(os.path.realpath(__file__))

class MyProjectConan(ConanFile):
    name = "conan_breakpad"
    version = "0.0.1-1"
    settings = "os", "arch", "build_type", "compiler"
    generators = "CMakeDeps", "CMakeToolchain"
    short_paths = True
    build_policy = "missing"

    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": True, "fPIC": True}
    
    exports_sources = "CMakeLists.txt", "conanfile.py", "src*", "cmake*", "!build"
    requires = "ms-gsl/4.0.0"

        
    def requirements(self):    
        
        if not self.in_local_cache:
            self.requires('gtest/1.14.0')

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        cmake_layout(self, src_folder=".")
        self.folders.generators = "build"
        self.cpp.build.libdirs = "lib" # write the .libs to the library folder under build
        self.cpp.build.bindirs = "bin" # write the .dll to the bin folder under build

    def generate(self):
        # Optionally generate a CMakeToolchain for Conan's dependencies
        tc = CMakeToolchain(self)
        
        vckpg_root = os.path.join(script_dir, "..", "vcpkg")
        file_path = Path(f"{vckpg_root}/packages/breakpad_x64-windows/share/unofficial-breakpad")
        # Set the vcpkg toolchain file location
        tc.variables["unofficial-breakpad_DIR"] = file_path.as_posix()
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()