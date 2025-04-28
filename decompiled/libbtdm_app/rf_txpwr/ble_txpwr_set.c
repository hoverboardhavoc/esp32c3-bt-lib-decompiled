/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> rf_txpwr.o -> ble_txpwr_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ble_txpwr_set(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar1 = (uint)*(byte *)(iVar2 + 0xd);
  if (4 < param_1) {
    return 0xffffffff;
  }
  if (0xf < param_3) {
    return 0xfffffffe;
  }
  if (param_1 == 1) {
    iVar2 = adv_itf_version_is_legacy(0xfffffffe);
    if ((iVar2 != 0) || (iVar3 = 0, param_2 == 0xffff)) goto _L40;
  }
  else {
    iVar2 = -2;
    if ((param_2 == 0xffff) || (iVar3 = 3, iVar2 = iVar3, param_1 != 4)) goto _L40;
  }
  uVar1 = llm_hdl_to_id(iVar3);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  iVar2 = -4;
  if (*(byte *)(iVar3 + 0xd) <= uVar1) {
    return 0xfffffffc;
  }
_L40:
  if ((_r_plf_funcs_p == 0) ||
     (iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(iVar2,*(code **)(_r_plf_funcs_p + 0x38)),
     (*(byte *)(iVar2 + 0xc) & 1) == 0)) {
    uVar4 = 0xfffffffd;
  }
  else {
    uStack_24 = (undefined1)param_1;
    uStack_23 = (undefined1)uVar1;
    uStack_22 = (undefined1)param_3;
    uVar4 = (**(code **)(_r_plf_funcs_p + 0x28))
                      (0xb,&uStack_24,3,1,*(code **)(_r_plf_funcs_p + 0x28));
  }
  return uVar4;
}

