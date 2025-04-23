/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> arch_main.o -> esp_ble_get_rxerr_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_ble_get_rxerr_cnt(uint param_1,int *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iStack_14;
  
  iStack_14 = 0;
  uVar1 = llm_hdl_to_id(param_1 & 0xff);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(byte *)(iVar2 + 0xd) <= uVar1) {
    return 1;
  }
  lld_le_pkt_err_get(uVar1,param_2,param_3);
  if (param_1 == 1) {
    uVar3 = 0xb;
  }
  else {
    if (param_1 != 2) {
      return 0;
    }
    uVar3 = 10;
  }
  lld_le_pkt_err_get(uVar3,&iStack_14,0);
  *param_2 = *param_2 + iStack_14;
  return 0;
}

