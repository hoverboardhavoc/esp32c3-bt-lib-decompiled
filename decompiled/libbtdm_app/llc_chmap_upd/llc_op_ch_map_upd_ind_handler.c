/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_chmap_upd.o -> llc_op_ch_map_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 llc_op_ch_map_upd_ind_handler(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = param_2 >> 8 & 0xff;
  iVar4 = *(int *)(&llc_env + (param_2 >> 8) * 4);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar3 = 0;
  if (((uVar1 < *(byte *)(iVar2 + 0xd)) &&
      (iVar2 = *(int *)(&llc_env + (param_2 >> 8) * 4), iVar2 != 0)) &&
     ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(uVar1,0,*(code **)(_r_ip_funcs_p + 0x678));
    uVar3 = 2;
    if ((iVar2 == 0) && ((*(ushort *)(iVar4 + 0x42) & 0x10) == 0)) {
      (**(code **)(_r_ip_funcs_p + 0x67c))(uVar1,0,param_1,*(code **)(_r_ip_funcs_p + 0x67c));
      (**(code **)(_r_ip_funcs_p + 0x61c))(uVar1,0,0,*(code **)(_r_ip_funcs_p + 0x61c));
      uVar3 = 1;
    }
  }
  return uVar3;
}

