#pragma once

#include "Platform.h"

namespace Draconian {

#define DRACO_MAJOR_VERSION 1
#define DRACO_MINOR_VERSION 0
#define DRACO_PATCH_VERSION 0
#define DRACO_VERSION (DRACO_MAJOR_VERSION << 8) | (DRACO_MINOR_VERSION << 4) | DRACO_PATCH_VERSION

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

// Forward declarations
class FileManager;
class LogManager;
enum class RenderingState { EXIT, RUNNING };
class Timer;
class VertexBufferObject;
class Window;

}

#include "StandardHeaders.h"

#include <GL/glew.h> 
#include <glm/glm.hpp>

// More to come...