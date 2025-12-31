/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_activity_free_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_activity_free_set(uint param_1)

{
  int iVar1;
  
  *(undefined4 *)((param_1 + 0x1800c4cb) * 4) = 0;
  iVar1 = *(int *)(_p_llm_env + 8) + param_1 * 0x44;
  *(undefined1 *)(iVar1 + 0x40) = 0;
  r_sch_plan_rem(iVar1 + 0xc);
  r_ble_log_internal_x1
            (0x404e014b,
             (uint)*(byte *)(*(int *)(_p_llm_env + 8) + param_1 * 0x44 + 0x40) << 8 | param_1);
  return;
}

