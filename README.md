# 🎨 OpenGL Computer Graphics & Practicum

![C++ Version](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![OpenGL](https://img.shields.io/badge/OpenGL-3.3%20Core%20Profile-red.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

Repository ini berisi kumpulan kode program, tugas praktikum, dan eksperimen grafika komputer (*Computer Graphics*) berbasis **Modern OpenGL (Core Profile)** menggunakan bahasa pemrograman **C++**. Seluruh materi dipelajari dan dikembangkan berdasarkan acuan kurikulum akademis serta panduan terstruktur dari [LearnOpenGL](https://learnopengl.com/).

---

## 📑 Daftar Isi
- [Tentang Proyek](#-tentang-proyek)
- [Cakupan Praktikum](#-cakupan-praktikum)
- [Teknologi & Pustaka](#-teknologi--pustaka)
- [Struktur Repository](#-struktur-repository)
- [Prasyarat & Dependensi](#-prasyarat--dependensi)
- [Cara Membangun & Menjalankan](#-cara-membangun--menjalankan)
- [Lisensi](#-lisensi)

---

## 🚀 Tentang Proyek

Proyek ini bertujuan untuk memahami fondasi grafika komputer modern, mulai dari alur pemrosesan grafis (*Graphics Pipeline*), manajemen *memory buffer* di GPU, pembuatan program *shader* kustom, pemetaan tekstur 2D, hingga kalkulasi matematika aljabar linear untuk transformasi objek 2D dan 3D.

---

## 📚 Cakupan Praktikum

Berikut adalah beberapa materi dan latihan utama yang telah diimplementasikan dalam repository ini:

### 1. Getting Started & Hello Window
- Inisialisasi *context* OpenGL menggunakan **GLFW**.
- Manajemen *function pointer* GPU dengan **GLAD**.
- Pembuatan objek dasar (Point, Triangle, Rectangle) menggunakan **VBO**, **VAO**, dan **EBO**.

### 2. Shaders & Shading Language (GLSL)
- Implementasi *Vertex Shader* dan *Fragment Shader*.
- Pengiriman data dari C++ ke GPU menggunakan variabel `uniform`.
- Eksperimen *Fragment Interpolation* (gradasi warna RGB pada titik simpul segitiga).
- Pembuatan kelas modular kustom `Shader` (`shader_s.h` & `shader_m.h`) untuk pembacaan file shader eksternal, kompilasi otomatis, dan pengecekan *error*.

### 3. Textures & Blending
- Pemetaan tekstur 2D pada geometri objek menggunakan pustaka `stb_image`.
- Konfigurasi *texture wrapping*, *filtering*, dan pencampuran (*blending*) dua tekstur sekaligus.
- Pembuatan kontrol interaktif menggunakan input keyboard untuk mengubah nilai visibilitas/transparansi tekstur secara *real-time*.

### 4. Transformations & Matrix Math
- Penggunaan pustaka **GLM** (OpenGL Mathematics) untuk kalkulasi aljabar linear.
- Penerapan matriks transformasi: **Translasi** (pergeseran), **Rotasi** (perputaran), dan **Penskalaan** (scaling).
- Pembuatan animasi objek bergerak secara kontinu dengan memanfaatkan fungsi waktu `glfwGetTime()`.

---

## 🛠 Teknologi & Pustaka

| Pustaka / Tools | Versi / Deskripsi | Fungsi Utama |
| :--- | :--- | :--- |
| **C++** | C++17 / C++20 | Bahasa pemrograman utama |
| **OpenGL** | Version 3.3 (Core Profile) | API Grafika Komputer |
| **GLFW** | v3.x | Manajemen window, context OpenGL, dan input keyboard/mouse |
| **GLAD** | OpenGL 3.3 Core | Loading extension & function pointer OpenGL |
| **GLM** | OpenGL Mathematics | Operasi matriks dan vektor (Translasi, Rotasi, Proyeksi) |
| **stb_image** | v2.x | Pustaka *header-only* untuk pembacaan file gambar/tekstur |

---

## 📂 Struktur Repository

```text
OpenGL/
├── include/              # Header files (glad, GLFW, GLM, stb_image, shader_m.h, dll)
├── src/                  # Source code C++ (.cpp)
│   ├── 1.getting_started/
│   │   ├── 1.hello_window/
│   │   ├── 2.shaders/
│   │   ├── 3.textures/
│   │   └── 4.transformations/
│   └── glad.c            # File loader GLAD
├── assets/               # Resource media (gambar/tekstur .jpg, .png)
├── shaders/              # File shader eksternal (.vs untuk vertex, .fs untuk fragment)
├── CMakeLists.txt        # Konfigurasi build CMake (Opsional)
└── README.md             # Dokumentasi utama proyek

```

---

## ⚙ Prasyarat & Dependensi

Pastikan perangkat lunak berikut telah terinstal di komputer Anda:

* **C++ Compiler** yang mendukung standar C++17 (GCC/MinGW, MSVC, atau Clang).
* **CMake** (versi 3.10 atau yang lebih baru, jika menggunakan CMake).
* **IDE / Code Editor**: Visual Studio Code, Visual Studio 2022, atau CLion.

---

## 🛠 Cara Membangun & Menjalankan

### Menggunakan VS Code (MinGW / GCC)

1. **Kloning Repository ini:**
```bash
git clone [https://github.com/AdhyDa/OpenGL.git](https://github.com/AdhyDa/OpenGL.git)
cd OpenGL

```


2. **Kompilasi File (Contoh menggunakan `g++`):**
```bash
g++ -std=c++17 src/1.getting_started/4.transformations/transformations.cpp src/glad.c -Iinclude -Llib -lglfw3 -lopengl32 -lgdi32 -o transformations.exe

```


3. **Jalankan Executable:**
```bash
./transformations.exe

```



---

## 📜 Lisensi

Proyek ini dipublikasikan di bawah lisensi **MIT License**. Silakan gunakan kode di dalam repository ini untuk keperluan pembelajaran dan pengembangan lebih lanjut.

---

⭐ **Jangan lupa berikan Star jika repository ini membantu proses belajar OpenGL Anda!**

```

***

### 💡 Tips Tambahan:
1. Kamu bisa membuat file baru bernama **`README.md`** di root direktori folder proyek lokal kamu, lalu *paste* seluruh isi markdown di atas.
2. Jika ada direktori atau file tertentu yang sedikit berbeda nama atau lokasinya di komputer lokalmu (seperti nama folder `assets/` atau `shaders/`), kamu bisa menyesuaikannya pada bagian **Struktur Repository**.
