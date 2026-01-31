/*
 * Copyright (c) 2026 reri
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
This product includes software developed by the OpenSSL Project for use in the OpenSSL Toolkit (http://www.openssl.org/)
*/

#include <stdio.h>
#include <string.h>

#include <openssl/evp.h>
#include <openssl/err.h>

void err_handle(EVP_CIPHER_CTX *ctx)
{
    if (ctx)
    {
        EVP_CIPHER_CTX_free(ctx);
    }

    ERR_print_errors_fp(stderr);
    exit(1);
}

int main(int argc, char *argv[])
{
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901"; // 256비트 (32 bytes)
    unsigned char *iv = (unsigned char *)"0123456789012345"; // 128비트 (16 bytes)

    unsigned char *plaintext = (unsigned char *)"Hello, OpenSSL Encryption!";
    unsigned char ciphertext[128] = {0};
    unsigned char decryptedtext[128] = {0};

    int len, ciphertext_len, decryptedtext_len;

    //----------------------------------------------------------------
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) err_handle(NULL);

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) err_handle(ctx);

    // 평문을 암호문으로 변환
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, strlen((char*)plaintext)) != 1) err_handle(ctx);
    ciphertext_len = len;

    if (EVP_EncryptFinal_ex(ctx, ciphertext+len, &len) != 1) err_handle(ctx);
    ciphertext_len += len;

    //----------------------------------------------------------------

    EVP_CIPHER_CTX_reset(ctx);

    //----------------------------------------------------------------
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) err_handle(ctx);

    if (EVP_DecryptUpdate(ctx, decryptedtext, &len, ciphertext, ciphertext_len) != 1) err_handle(ctx);
    decryptedtext_len = len;

    if (EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len) != 1) err_handle(ctx);
    decryptedtext_len += len;

    decryptedtext[decryptedtext_len] = '\0';
    EVP_CIPHER_CTX_free(ctx);

    printf("Original: %s\n", plaintext);
    printf("Decrypted: %s\n", decryptedtext);

    return 0;
}