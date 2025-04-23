/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_scan_sync_acad_attach
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_scan_sync_acad_attach(uint param_1,undefined1 param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = r_sdk_config_get_opts();
  uVar2 = 2;
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    uVar2 = 2;
    iVar1 = *(int *)(_p_llm_env + 8) + param_1 * 0x44;
    if (*(char *)(iVar1 + 0x40) == '\x0f') {
      *(undefined1 *)(iVar1 + 0x29) = param_2;
      *(undefined2 *)(iVar1 + 0x2a) = param_3;
      uVar2 = 0;
    }
  }
  return uVar2;
}

