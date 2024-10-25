/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_feat_exch.o -> ll_feature_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_feature_rsp_handler(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  *(undefined1 *)(iVar1 + 0x30) = *(undefined1 *)(param_2 + 1);
  *(undefined1 *)(iVar1 + 0x31) = *(undefined1 *)(param_2 + 2);
  *(undefined1 *)(iVar1 + 0x32) = *(undefined1 *)(param_2 + 3);
  *(undefined1 *)(iVar1 + 0x33) = *(undefined1 *)(param_2 + 4);
  *(undefined1 *)(iVar1 + 0x34) = *(undefined1 *)(param_2 + 5);
  *(undefined1 *)(iVar1 + 0x35) = *(undefined1 *)(param_2 + 6);
  *(undefined1 *)(iVar1 + 0x36) = *(undefined1 *)(param_2 + 7);
  *(undefined1 *)(iVar1 + 0x37) = *(undefined1 *)(param_2 + 8);
  *(ushort *)(iVar1 + 0x42) = *(ushort *)(iVar1 + 0x42) | 0x80;
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(0,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar1 == 4) {
    (**(code **)(_r_ip_funcs_p + 0x5b0))(param_1,0,*(code **)(_r_ip_funcs_p + 0x5b0));
  }
  return 0;
}

