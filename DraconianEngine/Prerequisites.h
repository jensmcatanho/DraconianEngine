#pragma once

namespace Draconian {

#define DRACONIAN_MAJOR_VERSION 1
#define DRACONIAN_MINOR_VERSION 0
#define DRACONIAN_PATCH_VERSION 0
#define DRACONIAN_VERSION (DRACONIAN_MAJOR_VERSION << 8) | (DRACONIAN_MINOR_VERSION << 4) | DRACONIAN_PATCH_VERSION

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