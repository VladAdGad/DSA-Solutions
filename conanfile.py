from conans import ConanFile


class Main(ConanFile):
    generators = "cmake"
    settings = "os", "compiler", "build_type"
    requires = "Catch2/2.11.1@catchorg/stable"

