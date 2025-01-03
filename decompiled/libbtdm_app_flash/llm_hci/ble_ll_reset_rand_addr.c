/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> llm_hci.o -> ble_ll_reset_rand_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ble_ll_reset_rand_addr(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = llm_is_non_con_legacy_act_ongoing_check();
  uVar2 = 0xc;
  if (iVar1 == 0) {
    memcpy((void *)(_p_llm_env + 0x12),&co_null_bdaddr,6);
    uVar2 = 0;
  }
  return uVar2;
}

