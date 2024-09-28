# conan_breakpad


```
mkdir build
cd build
conan install .. --build=missing
conan build ..
```


```
        vckpg_root = os.path.join(script_dir, "..", "vcpkg")
        file_path = Path(f"{vckpg_root}/packages/breakpad_x64-windows/share/unofficial-breakpad")
        # Set the vcpkg toolchain file location
        tc.variables["unofficial-breakpad_DIR"] = file_path.as_posix()
```