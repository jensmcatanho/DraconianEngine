#pragma once

#include "Draconian.h"

namespace Draconian {

class OBJLoader {
	private:
		std::vector<glm::vec4> vertices;
		std::vector<glm::vec2> textures;
		std::vector<glm::vec4> normals;
		std::vector<int> indices;

	public:
		OBJLoader();
		~OBJLoader();

		void loadFile(std::string filename) {
			std::vector<std::string> lineElements;
			std::ifstream objFile;
			std::string line;

			std::vector<glm::vec2> texturesBuffer;
			std::vector<glm::vec4> normalsBuffer;

			objFile.exceptions(std::ifstream::badbit);

			try {
				objFile.open(filename + ".obj");

				// Skips comments in the .obj file
				do {
					lineElements.clear();
					std::getline(objFile, line);
					split(line, ' ', lineElements);

				} while (lineElements[0] != "v");

				// Starts to process the vertices from the .obj file
				do {
					glm::vec4 vertex;

					vertex.x = std::stof(lineElements[1], nullptr);
					vertex.y = std::stof(lineElements[2], nullptr);
					vertex.z = std::stof(lineElements[3], nullptr);
					vertex.w = 1.0f;
				
					vertices.push_back(vertex);

					lineElements.clear();
					std::getline(objFile, line);
					split(line, ' ', lineElements);

				} while (lineElements[0] == "v");

				// Starts to process the texture coordinates from the .obj file
				do {
					glm::vec2 texCoord;

					texCoord.x = std::stof(lineElements[1], nullptr);
					texCoord.y = std::stof(lineElements[2], nullptr);

					texturesBuffer.push_back(texCoord);

					lineElements.clear();
					std::getline(objFile, line);
					split(line, ' ', lineElements);
				
				} while (lineElements[0] == "vt");

				// Starts to process the normal vectors from the .obj file
				do {
					glm::vec4 normal;

					normal.x = std::stof(lineElements[1], nullptr);
					normal.y = std::stof(lineElements[2], nullptr);
					normal.z = std::stof(lineElements[3], nullptr);
					normal.w = 0.0f;

					normalsBuffer.push_back(normal);

					lineElements.clear();
					std::getline(objFile, line);
					split(line, ' ', lineElements);
				
				} while (lineElements[0] == "vn");

				// Skips smoothing details for now
				do {
					lineElements.clear();
					std::getline(objFile, line);
					split(line, ' ', lineElements);

				} while (lineElements[0] != "f");

				do {
					std::vector<std::string> firstVertex;
					split(lineElements[1], '/', firstVertex);

					std::vector<std::string> secondVertex;
					split(lineElements[2], '/', secondVertex);
					
					std::vector<std::string> thirdVertex;
					split(lineElements[3], '/', thirdVertex);

					processVertex(firstVertex, texturesBuffer, normalsBuffer);
					processVertex(secondVertex, texturesBuffer, normalsBuffer);
					processVertex(thirdVertex, texturesBuffer, normalsBuffer);

				} while (std::getline(objFile, line));

				objFile.close();

			} catch (std::ifstream::failure e) {
				std::cerr << "" << std::endl;
			
			}
		}

	protected:
		void split(const std::string &line, char delim, std::vector<std::string> &elements) {
			std::stringstream ss(line);
			std::string item;

			while (std::getline(ss, item, delim)) {
				elements.push_back(item);
			}

		}

		void processVertex(std::vector<std::string> &vertexData, std::vector<glm::vec2> &tBuffer, std::vector<glm::vec4> &nBuffer) {
			int currentVertexIndex = std::stoi(vertexData[0], nullptr) - 1;
			int currentTextureIndex = std::stoi(vertexData[1], nullptr) - 1;
			int currentNormalIndex = std::stoi(vertexData[2], nullptr) - 1;

			indices.push_back(currentVertexIndex);
			tBuffer[currentTextureIndex].y = 1 - tBuffer[currentTextureIndex].y; // OpenGL starts the UV coordinate system from top-left while Blender starts from bottom-left
			textures.push_back(tBuffer[currentTextureIndex]);
			normals.push_back(nBuffer[currentNormalIndex]);
		}
};

}