/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_sync_info_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_per_adv_sync_info_get(int param_1,undefined4 *param_2,short *param_3,void *param_4)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  void *__src;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar4 = *(int *)(&lld_per_adv_env + param_1 * 4);
  uVar3 = 0xc;
  if (iVar4 != 0) {
    cVar1 = *(char *)(iVar4 + 0x3d);
    *param_2 = *(undefined4 *)(iVar4 + 4);
    sVar2 = *(short *)(iVar4 + 0x4c);
    *param_3 = sVar2;
    if ((cVar1 == '\0') || (*(short *)(iVar4 + 0x3a) != sVar2)) {
      __src = (void *)(iVar4 + 0x2f);
    }
    else {
      __src = (void *)(iVar4 + 0x34);
    }
    memcpy(param_4,__src,5);
    uVar3 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar3;
}

