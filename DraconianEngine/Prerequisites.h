#pragma once

#include "Platform.h"

namespace Draconian {

#define DRACO_MAJOR_VERSION 1
#define DRACO_MINOR_VERSION 0
#define DRACO_PATCH_VERSION 0
#define DRACO_VERSION (DRACO_MAJOR_VERSION << 8) | (DRACO_MINOR_VERSION << 4) | DRACO_PATCH_VERSION

// Forward declarations
class FileManager;
class IndexBufferObject;
class LogManager;
class Renderable2D;
enum class RenderingState { EXIT, RUNNING };
class ShaderProgram;
class Sprite;
class StaticSprite;
class Timer;
class VertexArrayObject;
class VertexBufferObject;
struct VertexData;
class Window;

}

#include "StandardHeaders.h"

#include <GL/glew.h> 
#include <glm/glm.hpp>

// More to come...