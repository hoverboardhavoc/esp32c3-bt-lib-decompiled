/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> arch_main.o -> esp_ble_get_rxerr_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_ble_get_rxerr_cnt(uint param_1,int *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iStack_14;
  
  iStack_14 = 0;
  uVar2 = llm_hdl_to_id(param_1 & 0xff);
  iVar3 = r_sdk_config_get_opts();
  if (uVar2 < *(byte *)(iVar3 + 0xd)) {
    lld_le_pkt_err_get(uVar2,param_2,param_3);
    if (param_1 == 1) {
      lld_le_pkt_err_get(0xb,&iStack_14,0);
      *param_2 = *param_2 + iStack_14;
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
      if (param_1 == 2) {
        lld_le_pkt_err_get(10,&iStack_14,0);
        *param_2 = *param_2 + iStack_14;
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

