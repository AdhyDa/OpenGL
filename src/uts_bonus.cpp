#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include "../include/glm/glm.hpp"
#include "../include/glm/gtc/matrix_transform.hpp"
#include "../include/glm/gtc/type_ptr.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"
#include "../include/learnopengl/shader_s.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// Pengaturan ukuran jendela
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// --- VARIABEL GLOBAL UNTUK INTERAKSI (TANTANGAN UTS) ---
// mixValue: Ganti 0.8f dengan 0.x sesuai digit akhir NIM-mu
float mixValue = 0.8f; 
// scaleValue: Digunakan untuk merubah ukuran objek via interaksi keyboard
float scaleValue = 1.0f; 
// --------------------------------------------------------

int main()
{
    // Inisialisasi dan konfigurasi GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Pembuatan jendela GLFW
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "UTS Grafkom - Adhyaksa Daudi", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Gagal membuat jendela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Memuat penunjuk fungsi OpenGL dengan GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Gagal menginisialisasi GLAD" << std::endl;
        return -1;
    }

    // Membangun dan kompilasi shader
    Shader ourShader("src/4.2.texture.vs", "src/4.2.texture.fs");

    // Persiapan data vertex (persegi)
    float vertices[] = {
        // posisi             // warna            // koordinat tekstur
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // kanan atas
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // kanan bawah
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // kiri bawah
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // kiri atas 
    };
    unsigned int indices[] = {
        0, 1, 3, // segitiga pertama
        1, 2, 3  // segitiga kedua
    };
    
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Atribut posisi
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Atribut warna
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // Atribut koordinat tekstur
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    // Memuat dan membuat tekstur
    unsigned int texture1, texture2;
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); 

    // Tekstur 1 (Foto Profil)
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    unsigned char *data = stbi_load("img/GetFoto.jpg", &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Gagal memuat tekstur 1" << std::endl;
    }
    stbi_image_free(data);
    
    // Tekstur 2 (NIM)
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    data = stbi_load("img/nim.png", &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Gagal memuat tekstur 2" << std::endl;
    }
    stbi_image_free(data);

    ourShader.use(); 
    glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0);
    ourShader.setInt("texture2", 1);

    // Loop perenderan utama
    while (!glfwWindowShouldClose(window))
    {
        // 1. Memproses input interaksi keyboard
        processInput(window);

        // 2. Membersihkan layar
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Mengikat tekstur ke unit yang sesuai
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);

        // Mengaktifkan shader
        ourShader.use();

        // --- PENERAPAN NILAI INTERAKTIF ---
        
        // A. Mengirim mixValue yang dapat diubah ke Fragment Shader
        ourShader.setFloat("mixValue", mixValue);

        // B. Melakukan Transformasi Looping sekaligus mengubah Scale
        glm::mat4 transform = glm::mat4(1.0f);
        // Transformasi rotasi berulang berdasarkan waktu berjalan
        transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        // Transformasi skala (interaktif via tombol W/S)
        transform = glm::scale(transform, glm::vec3(scaleValue, scaleValue, scaleValue));
        
        // Mengirim matriks ke Vertex Shader
        unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        // ----------------------------------

        // Menggambar objek
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Menukar buffer dan memeriksa event I/O
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Membersihkan memori
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    glfwTerminate();
    return 0;
}

// Fungsi pemrosesan input (Tempat utama Tantangan Nilai Tambahan)
void processInput(GLFWwindow *window)
{
    // Keluar dari aplikasi
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    // Tombol Panah ATAS: Memperjelas tekstur 2 (NIM)
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        mixValue += 0.005f;
        if(mixValue >= 1.0f) mixValue = 1.0f; // Batas maksimal
    }
    // Tombol Panah BAWAH: Memperjelas tekstur 1 (Foto)
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        mixValue -= 0.005f;
        if(mixValue <= 0.0f) mixValue = 0.0f; // Batas minimal
    }

    // Tombol W: Memperbesar objek
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        scaleValue += 0.005f;
    }
    // Tombol S: Memperkecil objek
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        scaleValue -= 0.005f;
        if(scaleValue <= 0.1f) scaleValue = 0.1f; // Batas ukuran terkecil agar tidak hilang
    }
}

// Fungsi callback untuk penyesuaian ukuran jendela
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}