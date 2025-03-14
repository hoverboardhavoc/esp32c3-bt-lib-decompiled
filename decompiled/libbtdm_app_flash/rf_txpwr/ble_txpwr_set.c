/*
 * Last changed at upstream commit bc9fd38197fb6a50e1b09791498782a1797e4757
 * https://github.com/espressif/esp32c3-bt-lib/commit/bc9fd38197fb6a50e1b09791498782a1797e4757
 * Upstream date: 2025-03-14 10:49:41 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(99e9a8dd)
 * Source: libbtdm_app_flash -> rf_txpwr.o -> ble_txpwr_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ble_txpwr_set(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  
  iVar2 = r_sdk_config_get_opts();
  uVar1 = (uint)*(byte *)(iVar2 + 0xd);
  if (4 < param_1) {
    return 0xffffffff;
  }
  uVar3 = 0xfffffffe;
  if (0xf < param_3) {
    return 0xfffffffe;
  }
  if (param_2 != 0xffff) {
    if (param_1 == 1) {
      uVar3 = 0;
    }
    else {
      uVar3 = 3;
      if (param_1 != 4) goto _L14;
    }
    uVar1 = llm_hdl_to_id(uVar3);
    iVar2 = r_sdk_config_get_opts();
    uVar3 = 0xfffffffc;
    if (*(byte *)(iVar2 + 0xd) <= uVar1) {
      return 0xfffffffc;
    }
  }
_L14:
  iVar2 = r_sdk_config_get_opts(uVar3);
  uVar3 = 0xfffffffd;
  if ((*(byte *)(iVar2 + 0xc) & 1) != 0) {
    uStack_14 = (undefined1)param_1;
    uStack_13 = (undefined1)uVar1;
    uStack_12 = (undefined1)param_3;
    uVar3 = r_btdm_task_post(0xb,&uStack_14,3,1);
  }
  return uVar3;
}

