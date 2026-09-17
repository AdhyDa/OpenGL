#version 330 core
#define STB_IMAGE_IMPLEMENTATION

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;

// nomor 3
uniform mat4 transform; 

void main()
{
    // Mengalikan posisi titik awal dengan matriks transformasi
    gl_Position = transform * vec4(aPos, 1.0);
    ourColor = aColor;
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}