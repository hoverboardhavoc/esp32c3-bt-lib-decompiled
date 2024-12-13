/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_lld_adv_start_eco(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (g_qa_test_config != '\0') {
    DAT_00015e60 = 0;
  }
  llm_ext_adv_get_own_addr(param_1,*(undefined1 *)(param_2 + 0x1e),param_2);
  uVar1 = r_lld_adv_start(param_1,param_2);
  r_lld_adv_start_hook_part_1(param_1,param_2);
  return uVar1;
}

