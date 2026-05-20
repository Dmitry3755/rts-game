import os
from SCons.Script import *

# =========================
# CONFIG
# =========================

env = Environment()

env.Append(CXXFLAGS=["/std:c++17"])

# пути
project_dir = os.getcwd()
godot_cpp_dir = os.path.join(project_dir, "godot-cpp")
cpp_dir = os.path.join(project_dir, "cpp")

# build вне res:// структуры
build_dir = os.path.join(project_dir, ".build")

# платформы (Windows x64)
env.Append(CPPDEFINES=["TYPED_METHOD_BIND"])

# =========================
# GODOT-CPP PATHS
# =========================

env.Append(CPPPATH=[
    os.path.join(godot_cpp_dir, "gen"),
    os.path.join(godot_cpp_dir, "gen", "include"),
    os.path.join(godot_cpp_dir, "include", "core"),
    os.path.join(godot_cpp_dir, "include"),
])

env.Append(LIBPATH=[
    os.path.join(godot_cpp_dir, "bin"),
])

# ⚠️ имя либы может отличаться — проверь в godot-cpp/bin
env.Append(LIBS=[
    "libgodot-cpp.windows.template_debug.x86_64.lib"
])

# =========================
# SOURCE FILES
# =========================

sources = []

for root, dirs, files in os.walk(cpp_dir):
    for file in files:
        if file.endswith(".cpp"):
            sources.append(os.path.join(root, file))

# =========================
# BUILD TARGET
# =========================

env.SharedLibrary(
    target=os.path.join(build_dir, "middle_ages_rts"),
    source=sources
)