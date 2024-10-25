/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_feat_exch.o -> hci_le_rd_rem_feats_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_rem_feats_cmd_handler(uint param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar1 = (int *)(&llc_env + param_1 * 4);
  iVar5 = *piVar1;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar4 = 0xc;
  if (param_1 < *(byte *)(iVar2 + 0xd)) {
    uVar4 = 0xc;
    if ((((*piVar1 != 0) && ((*(byte *)(*piVar1 + 0x44) & 3) != 3)) &&
        (uVar4 = 0x3a, (*(byte *)(iVar5 + 0x45) & 4) == 0)) &&
       ((((iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(0x3a,*(code **)(_r_plf_funcs_p + 0x38)),
          param_1 < *(byte *)(iVar2 + 0xd) && (*piVar1 != 0)) &&
         (((int)(uint)*(byte *)(*piVar1 + 0x30) >> 3 & 1U) != 0)) ||
        (uVar4 = 0x1a, (*(ushort *)(iVar5 + 0x42) & 0x81) != 0)))) {
      puVar3 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x107,param_1 << 8 | 1,0xc,*(code **)(_r_modules_funcs_p + 200));
      *(undefined1 *)(puVar3 + 1) = 4;
      (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
      *(undefined1 *)(puVar3 + 2) = 1;
      *puVar3 = *(undefined4 *)(_r_ip_funcs_p + 0x5a8);
      (**(code **)(_r_modules_funcs_p + 0xe0))(puVar3,*(code **)(_r_modules_funcs_p + 0xe0));
      uVar4 = 0;
      *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) | 4;
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x634))(param_1,param_2,uVar4,*(code **)(_r_ip_funcs_p + 0x634));
  return 0;
}

