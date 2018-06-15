cmake_minimum_required(VERSION 3.10)
project(RayTracing)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(RayTracing
        Camera.cpp
        Camera.h
        Color.cpp
        Color.h
        Cube.cpp
        Cube.h
        Entity.cpp
        Entity.h
        Geometry.cpp
        Geometry.h
        Hit.cpp
        Hit.h
        Image.cpp
        Image.h
        Optic.cpp
        Optic.h
        Point3d.cpp
        Point3d.h
        Ray.cpp
        Ray.h
        Sphere.cpp
        Sphere.h
        Texture.cpp
        Texture.h
        UniColor.cpp
        UniColor.h
        Vector3d.cpp
        Vector3d.h SpotLight.cpp SpotLight.h)
