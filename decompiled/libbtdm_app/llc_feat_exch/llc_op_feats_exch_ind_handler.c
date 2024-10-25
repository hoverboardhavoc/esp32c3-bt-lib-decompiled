/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_feat_exch.o -> llc_op_feats_exch_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llc_op_feats_exch_ind_handler(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar1 = param_2 >> 8 & 0xff;
  if (((uVar1 < *(byte *)(iVar2 + 0xd)) && (*(int *)(&llc_env + uVar1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + uVar1 * 4) + 0x44) & 3) != 3)) {
    uVar3 = 2;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(uVar1,0,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar2 == 0) {
      uVar3 = 1;
      (**(code **)(_r_ip_funcs_p + 0x67c))(uVar1,0,param_1,*(code **)(_r_ip_funcs_p + 0x67c));
      (**(code **)(_r_ip_funcs_p + 0x5b0))(uVar1,0,*(code **)(_r_ip_funcs_p + 0x5b0));
    }
  }
  else {
    uVar3 = 0;
    if (*(char *)(param_1 + 8) != '\0') {
      (**(code **)(_r_ip_funcs_p + 0x5ac))
                (uVar1,*(undefined1 *)(*(int *)(&llc_env + (param_2 >> 8) * 4) + 0x46),
                 *(int *)(&llc_env + (param_2 >> 8) * 4) + 0x30,*(code **)(_r_ip_funcs_p + 0x5ac));
    }
  }
  return uVar3;
}

