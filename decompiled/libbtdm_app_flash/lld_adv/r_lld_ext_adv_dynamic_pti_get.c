/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_ext_adv_dynamic_pti_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_ext_adv_dynamic_pti_get(int param_1,int param_2,int param_3,undefined1 *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined1 *puVar6;
  
  iVar5 = *(int *)(_bt_rf_coex_cfg_p + 0x34);
  uVar2 = *(uint *)(param_1 + 0x6c);
  if ((uint)*(byte *)(iVar5 + 0xd) * 0x271 < uVar2) {
    if ((uint)*(byte *)(iVar5 + 0xe) * 0x271 < uVar2) {
      if ((uint)*(byte *)(iVar5 + 0xf) * 0x271 < uVar2) {
        uVar2 = (uint)*(ushort *)(iVar5 + 0x16);
      }
      else {
        uVar2 = (uint)*(ushort *)(iVar5 + 0x14);
      }
    }
    else {
      uVar2 = (uint)*(ushort *)(iVar5 + 0x12);
    }
  }
  else {
    uVar2 = (uint)*(ushort *)(iVar5 + 0x10);
  }
  iVar1 = r_rwip_time_get();
  iVar5 = _bt_rf_coex_cfg_p;
  uVar3 = iVar1 - *(int *)(param_1 + 0x98) & 0xfffffff;
  if (0x8000000 < uVar3) {
    uVar3 = -(*(int *)(param_1 + 0x98) - iVar1 & 0xfffffffU);
  }
  if (((int)uVar3 < (int)(uVar2 << 1)) ||
     (((*(char *)(param_1 + 0x95) != '\0' && (param_2 == 0)) && (param_3 == 0)))) {
    param_3 = 0;
    uVar4 = *(undefined1 *)(*(int *)(_bt_rf_coex_cfg_p + 0x34) + 2);
  }
  else {
    *(int *)(param_1 + 0x98) = iVar1;
    puVar6 = *(undefined1 **)(iVar5 + 0x34);
    param_4[3] = puVar6[3];
    param_4[4] = puVar6[4];
    param_4[7] = puVar6[7];
    param_4[8] = puVar6[8];
    param_4[0xb] = puVar6[0xb];
    param_4[0xc] = puVar6[0xc];
    param_4[9] = puVar6[9];
    param_4[10] = puVar6[10];
    param_4[5] = puVar6[5];
    param_4[6] = puVar6[6];
    *param_4 = *puVar6;
    uVar4 = puVar6[1];
  }
  param_4[1] = uVar4;
  *(char *)(param_1 + 0x96) = (char)param_3;
  return;
}

