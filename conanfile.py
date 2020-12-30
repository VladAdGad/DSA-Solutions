from conans import ConanFile


class Main(ConanFile):
    generators = "cmake"
    settings = "os", "compiler", "build_type"
    requires = "catch2/2.13.4"
