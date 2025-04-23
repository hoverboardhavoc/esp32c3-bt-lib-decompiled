/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> flash.o -> r_flash_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * r_flash_init(void)

{
  flash_env = vflash_mem;
  DAT_0001020c = 0;
  DAT_00010210 = 0;
  if (sdk_cfg_priv_opts == '\0') {
    return vflash_mem;
  }
  memset(vflash_mem,0xff,0x800);
  if (sdk_cfg_priv_opts == '\0') {
    return (undefined1 *)0x1f;
  }
  *flash_env = 0x34;
  flash_env[1] = 0x12;
  flash_env[2] = 0xff;
  flash_env[3] = 0xff;
  DAT_00010210 = 4;
  DAT_0001020c = 0x800;
  flash_env = (undefined1 *)CONCAT31(flash_env._1_3_,4);
  return (undefined1 *)0x0;
}

