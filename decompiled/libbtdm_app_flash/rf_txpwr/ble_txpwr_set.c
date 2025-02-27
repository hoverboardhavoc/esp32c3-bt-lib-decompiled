/*
 * Last changed at upstream commit 0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * https://github.com/espressif/esp32c3-bt-lib/commit/0cfafa1e0aa30b7d59f53c38588f0598e228d127
 * Upstream date: 2025-02-27 20:50:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b34b7d6)
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
  int iVar3;
  undefined4 uVar4;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  
  iVar2 = r_sdk_config_get_opts();
  uVar1 = (uint)*(byte *)(iVar2 + 0xd);
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (0xf < param_3) {
    return 0xfffffffe;
  }
  if (param_1 == 1) {
    iVar2 = adv_itf_version_is_legacy(0xfffffffe);
    if ((iVar2 != 0) || (iVar3 = 0, param_2 == 0xffff)) goto _L15;
  }
  else {
    iVar2 = -2;
    if ((param_2 == 0xffff) || (iVar3 = 3, iVar2 = iVar3, param_1 != 4)) goto _L15;
  }
  uVar1 = llm_hdl_to_id(iVar3);
  iVar3 = r_sdk_config_get_opts();
  iVar2 = -4;
  if (*(byte *)(iVar3 + 0xd) <= uVar1) {
    return 0xfffffffc;
  }
_L15:
  iVar2 = r_sdk_config_get_opts(iVar2);
  uVar4 = 0xfffffffd;
  if ((*(byte *)(iVar2 + 0xc) & 1) != 0) {
    uStack_14 = (undefined1)param_1;
    uStack_13 = (undefined1)uVar1;
    uStack_12 = (undefined1)param_3;
    uVar4 = r_btdm_task_post(0xb,&uStack_14,3,1);
  }
  return uVar4;
}

