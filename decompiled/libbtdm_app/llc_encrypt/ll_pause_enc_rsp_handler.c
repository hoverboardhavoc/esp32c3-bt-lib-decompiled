/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_encrypt.o -> ll_pause_enc_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ll_pause_enc_rsp_handler(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar2 + 0x20) == '\0') {
    return 0x24;
  }
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  if ((*(ushort *)(iVar2 + 0x42) & 1) != 0) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(0,param_2,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar1 == 3) {
      uVar3 = 1;
      pcVar4 = *(code **)(_r_ip_funcs_p + 0x594);
      goto _L149;
    }
    if ((*(ushort *)(iVar2 + 0x42) & 1) != 0) {
      return 0x24;
    }
  }
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar2 != 3) {
    return 0x24;
  }
  uVar3 = 0xb;
  pcVar4 = *(code **)(_r_ip_funcs_p + 0x59c);
_L149:
  (*pcVar4)(param_1,uVar3,0,pcVar4);
  return 0;
}

