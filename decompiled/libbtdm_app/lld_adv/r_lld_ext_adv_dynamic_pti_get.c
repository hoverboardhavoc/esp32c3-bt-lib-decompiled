/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_ext_adv_dynamic_pti_get
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
  int iVar4;
  undefined1 *puVar5;
  
  iVar4 = *(int *)(_bt_rf_coex_cfg_p + 0x34);
  uVar2 = *(uint *)(param_1 + 0x6c);
  if ((uint)*(byte *)(iVar4 + 0xd) * 0x271 < uVar2) {
    if ((uint)*(byte *)(iVar4 + 0xe) * 0x271 < uVar2) {
      if ((uint)*(byte *)(iVar4 + 0xf) * 0x271 < uVar2) {
        uVar2 = (uint)*(ushort *)(iVar4 + 0x16);
      }
      else {
        uVar2 = (uint)*(ushort *)(iVar4 + 0x14);
      }
    }
    else {
      uVar2 = (uint)*(ushort *)(iVar4 + 0x12);
    }
  }
  else {
    uVar2 = (uint)*(ushort *)(iVar4 + 0x10);
  }
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
  iVar4 = _bt_rf_coex_cfg_p;
  uVar3 = iVar1 - *(int *)(param_1 + 0x98) & 0xfffffff;
  if (0x8000000 < uVar3) {
    uVar3 = -(*(int *)(param_1 + 0x98) - iVar1 & 0xfffffffU);
  }
  if (((int)uVar3 < (int)(uVar2 << 1)) ||
     (((*(char *)(param_1 + 0x95) != '\0' && (param_2 == 0)) && (param_3 == 0)))) {
    param_4[1] = *(undefined1 *)(*(int *)(_bt_rf_coex_cfg_p + 0x34) + 2);
    *(undefined1 *)(param_1 + 0x96) = 0;
  }
  else {
    *(int *)(param_1 + 0x98) = iVar1;
    puVar5 = *(undefined1 **)(iVar4 + 0x34);
    param_4[3] = puVar5[3];
    param_4[4] = puVar5[4];
    param_4[7] = puVar5[7];
    param_4[8] = puVar5[8];
    param_4[0xb] = puVar5[0xb];
    param_4[0xc] = puVar5[0xc];
    param_4[9] = puVar5[9];
    param_4[10] = puVar5[10];
    param_4[5] = puVar5[5];
    param_4[6] = puVar5[6];
    *param_4 = *puVar5;
    param_4[1] = puVar5[1];
    *(char *)(param_1 + 0x96) = (char)param_3;
  }
  return;
}

