/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_dynamic_pti_get
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
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
  iVar2 = (**(code **)(_r_ip_funcs_p + 400))
                    (*(undefined1 *)(param_1 + 0x52),*(code **)(_r_ip_funcs_p + 400));
  iVar6 = _bt_rf_coex_cfg_p;
  if (iVar2 == 0) {
    uVar4 = iVar1 - *(int *)(param_1 + 0x5c) & 0xfffffff;
    if (0x8000000 < uVar4) {
      uVar4 = -(*(int *)(param_1 + 0x5c) - iVar1 & 0xfffffffU);
    }
    if ((int)uVar4 < (int)(uVar3 << 1)) {
      uVar5 = *(undefined1 *)(*(int *)(_bt_rf_coex_cfg_p + 0x38) + 2);
      goto _L33;
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
_L33:
  param_2[1] = uVar5;
  return;
}

