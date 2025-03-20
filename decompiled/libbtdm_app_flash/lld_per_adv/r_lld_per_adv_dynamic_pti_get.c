/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_dynamic_pti_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_dynamic_pti_get(int param_1,undefined1 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined1 *puVar7;
  
  iVar6 = *(int *)(_bt_rf_coex_cfg_p + 0x38);
  uVar3 = *(uint *)(param_1 + 0x44);
  if ((uint)*(byte *)(iVar6 + 9) * 0x271 < uVar3) {
    if ((uint)*(byte *)(iVar6 + 10) * 0x271 < uVar3) {
      if ((uint)*(byte *)(iVar6 + 0xb) * 0x271 < uVar3) {
        uVar3 = (uint)*(ushort *)(iVar6 + 0x12);
      }
      else {
        uVar3 = (uint)*(ushort *)(iVar6 + 0x10);
      }
    }
    else {
      uVar3 = (uint)*(ushort *)(iVar6 + 0xe);
    }
  }
  else {
    uVar3 = (uint)*(ushort *)(iVar6 + 0xc);
  }
  iVar1 = r_rwip_time_get();
  iVar2 = r_lld_adv_coex_check_ext_adv_synced(*(undefined1 *)(param_1 + 0x52));
  iVar6 = _bt_rf_coex_cfg_p;
  if (iVar2 == 0) {
    uVar4 = iVar1 - *(int *)(param_1 + 0x5c) & 0xfffffff;
    if (0x8000000 < uVar4) {
      uVar4 = -(*(int *)(param_1 + 0x5c) - iVar1 & 0xfffffffU);
    }
    if ((int)uVar4 < (int)(uVar3 << 1)) {
      uVar5 = *(undefined1 *)(*(int *)(_bt_rf_coex_cfg_p + 0x38) + 2);
      goto _L48;
    }
  }
  *(int *)(param_1 + 0x5c) = iVar1;
  puVar7 = *(undefined1 **)(iVar6 + 0x38);
  param_2[3] = puVar7[3];
  param_2[4] = puVar7[4];
  param_2[5] = puVar7[5];
  param_2[6] = puVar7[6];
  param_2[7] = puVar7[7];
  param_2[8] = puVar7[8];
  *param_2 = *puVar7;
  uVar5 = puVar7[1];
_L48:
  param_2[1] = uVar5;
  return;
}

