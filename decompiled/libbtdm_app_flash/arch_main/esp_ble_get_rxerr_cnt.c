/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> arch_main.o -> esp_ble_get_rxerr_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_ble_get_rxerr_cnt(uint param_1,int *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iStack_14;
  
  iStack_14 = 0;
  uVar1 = llm_hdl_to_id(param_1 & 0xff);
  iVar2 = r_sdk_config_get_opts();
  if (uVar1 < *(byte *)(iVar2 + 0xd)) {
    lld_le_pkt_err_get(uVar1,param_2,param_3);
    if (param_1 == 1) {
      lld_le_pkt_err_get(0xb,&iStack_14,0);
      *param_2 = *param_2 + iStack_14;
      uVar3 = 0;
    }
    else {
      uVar3 = 0;
      if (param_1 == 2) {
        lld_le_pkt_err_get(10,&iStack_14,0);
        *param_2 = *param_2 + iStack_14;
        uVar3 = 0;
      }
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

