# Bit Stream Cipher Program

---

## Overview

This program implements a simple **bit stream cipher** for encrypting ASCII text using an **XOR-based encryption algorithm**. It operates in two modes:

1. **Interactive Mode**: Prompts the user for plaintext and a 4-bit encryption key.
2. **Batch Mode**: Reads plaintext and key from a file for non-interactive processing.

Encrypted text is displayed in **hexadecimal format** to ensure clarity and easy verification.

---

## Features

- **Text Encryption**: XOR-based encryption of ASCII characters.
- **Hexadecimal Display**: Outputs both plaintext and ciphertext in hex format.
- **Two Modes of Operation**:
  - **Interactive Mode**: User-friendly with prompts.
  - **Batch Mode**: Supports automated workflows via file redirection.
- **Flexible Compilation**: Controlled using conditional compilation with `#ifdef`.

---

## Usage

### Compilation

Use the provided `Makefile` for managing the compilation and cleanup:

- **Compile Interactive Mode**:  
  ```bash
  make bit_encode2
