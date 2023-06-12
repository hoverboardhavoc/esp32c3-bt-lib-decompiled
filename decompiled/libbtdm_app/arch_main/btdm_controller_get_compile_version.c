/*
 * Last changed at upstream commit b438f60a295183e7c67eb42ae05f4580f4b1ced0
 * https://github.com/espressif/esp32c3-bt-lib/commit/b438f60a295183e7c67eb42ae05f4580f4b1ced0
 * Upstream date: 2023-06-12 21:42:40 +0800
 * Upstream subject: update libbtdm_app.a for ESP32C3 and ESP32S3(963cad48)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_get_compile_version
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * btdm_controller_get_compile_version(void)

{
  return "963cad4";
}

