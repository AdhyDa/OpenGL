#version 330 core
out vec4 FragColor;

// Tangkap variabel warna dari kode C++
uniform vec3 lightColor; 

void main()
{
    // Gunakan warna tersebut untuk kubus lampu, dengan alpha 1.0 (solid)
    FragColor = vec4(lightColor, 1.0); 
}